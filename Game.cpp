#include "Game.h"
#include "Plane.h"
#include "Chicken.h"
#include "ChickenWave.h"
#include "Collision.h"
#include "Menu.h"


Game::Game()
{

    score = 0;
    game = QuitMenu = victory = GameOver = pause = score_screen = skin = help = false;
    isRunning = menu = SetPositionPlane = reset = true;
    win = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}


Game::~Game()
{
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

}


void Game::EndLoop()
{

    SDL_PollEvent(&e);
    {
        if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
            isRunning = false;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN)
            cout << "Mouse\n";
    }

}


void Game::Run()
{
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) == -1)   isRunning = false;
    Mix_Chunk* plane_bullet_sound = Mix_LoadWAV("assets/plane_bullet_sound.wav");
    Mix_Chunk* chicken_die_sound = Mix_LoadWAV("assets/chicken_die_sound.wav");
    Mix_Chunk* Game_Menu_Music = Mix_LoadWAV("assets/Game_Menu_Music.wav");
    Mix_Chunk* Game_Music = Mix_LoadWAV("assets/Game_Music.wav");
    Mix_Chunk* gameover_music_sound = Mix_LoadWAV("assets/gameover_music_sound.wav");
    Mix_Chunk* victory_music_sound = Mix_LoadWAV("assets/victory_music_sound.wav");

    if (TTF_Init() == -1)   isRunning = false;
    TTF_Font* font = TTF_OpenFont("assets/arial.ttf", 20);

    Plane spaceship;
    Entity Score;

    Menu game_background;
    Menu game_gameover;
    Menu game_victory;
    Menu game_score;
    Menu game_menu;
    Menu game_help;
    Menu PlayButton;
    Menu SkinButton;
    Menu ChooseButton;
    Menu HelpButton;
    Menu ExitButton;
    Menu BackButton;
    Menu LeftButton;
    Menu RightButton;
    Menu HomeButton;
    Menu PauseButton;
    Menu ContinueButton;
    Menu NextButton;
    Menu RestartButton;

    vector<Chicken*> chicken_list;
    vector<Bullet*> egg_list;

    int wave = 0;
    int plane_number = 1;

    game_menu.Entity::loadIMG("assets/Background_Menu.png", ren);
    game_help.Entity::loadIMG("assets/Game_Help.png", ren);
    game_background.Entity::loadIMG("assets/Background_Space.png", ren);
    game_gameover.Entity::loadIMG("assets/GAMEOVER.png", ren);
    game_victory.Entity::loadIMG("assets/VICTORY.png", ren);
    game_score.Entity::loadIMG("assets/Game_Score.png", ren);

    game_menu.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_menu.Entity::SetPosition(0, 0);
    game_help.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_help.Entity::SetPosition(0, 0);
    game_score.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_score.Entity::SetPosition(0, 0);
    game_gameover.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_gameover.Entity::SetPosition(0, 0);
    game_victory.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_victory.Entity::SetPosition(0, 0);

    Score.SetWidthHeight(150, 150);
    Score.Entity::SetPosition(SCREEN_WIDTH/2 - 60, SCREEN_HEIGHT/2 + 30);

    while (isRunning)
    {
        EndLoop();
        SDL_RenderClear(ren);

        if (!QuitMenu && reset)
        {
            Mix_HaltChannel(2);
            reset = false;
            Reset(chicken_list, spaceship, egg_list, wave, score, SetPositionPlane, victory);
            plane_number = 1;
        }

        if(!QuitMenu)
        {
            if(!Mix_Playing(1))
                Mix_PlayChannel(1, Game_Menu_Music, 0);

            if (menu)
            {
                PlayButton.SetWidthHeight(200, 50);
                SkinButton.SetWidthHeight(200, 50);
                HelpButton.SetWidthHeight(200, 50);
                ExitButton.SetWidthHeight(200, 50);

                PlayButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, 400);
                SkinButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, 500);
                HelpButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, 600);
                ExitButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, 700);

                PlayButton.Play(e, ren, menu, game, QuitMenu);
                SkinButton.Skin(e, ren, menu, skin);
                HelpButton.Help(e, ren, menu, help);
                ExitButton.Exit(e, ren, isRunning);

                game_menu.Display(ren);
                PlayButton.Display(ren);
                SkinButton.Display(ren);
                HelpButton.Display(ren);
                ExitButton.Display(ren);

                SDL_RenderPresent(ren);
            }

            if (skin)
            {
                BackButton.SetWidthHeight(100, 50);
                BackButton.Entity::SetPosition(100, SCREEN_HEIGHT - 100);
                BackButton.Back(e, ren, menu, help, skin);

                ChooseButton.SetWidthHeight(100, 50);
                ChooseButton.Entity::SetPosition(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 100);
                ChooseButton.Choose(e, ren, menu, skin);

                spaceship.Entity::SetPosition((SCREEN_WIDTH - PLANE_WIDTH_SKIN)/2, (SCREEN_HEIGHT - PLANE_HEIGHT_SKIN)/2);
                spaceship.SetWidthHeight(PLANE_WIDTH_SKIN, PLANE_HEIGHT_SKIN);
                spaceship.Plane::loadIMG(plane_number, ren);
                spaceship.ChangeSkin(plane_number, e);

                LeftButton.Entity::SetPosition(420, (SCREEN_HEIGHT - 50)/2);
                LeftButton.SetWidthHeight(50, 50);
                LeftButton.Left(e, ren, plane_number);

                RightButton.Entity::SetPosition(SCREEN_WIDTH - 420 - 50, (SCREEN_HEIGHT - 50)/2);
                RightButton.SetWidthHeight(50, 50);
                RightButton.Right(e, ren, plane_number);

                game_menu.Display(ren);
                spaceship.Display(ren);
                LeftButton.Display(ren);
                RightButton.Display(ren);
                BackButton.Display(ren);
                ChooseButton.Display(ren);

                SDL_RenderPresent(ren);
            }

            if (help)
            {
                BackButton.SetWidthHeight(100, 50);
                BackButton.Entity::SetPosition(100, SCREEN_HEIGHT - 100);
                BackButton.Back(e, ren, menu, help, skin);

                game_help.Display(ren);
                BackButton.Display(ren);

                SDL_RenderPresent(ren);
            }

            PlayButton.Free();
            SkinButton.Free();
            ChooseButton.Free();
            HelpButton.Free();
            BackButton.Free();
            ExitButton.Free();
            LeftButton.Free();
            RightButton.Free();
            spaceship.Free();
        }

        if (QuitMenu && SetPositionPlane)
        {
            Mix_HaltChannel(1);
            SetPositionPlane = false;
            spaceship.Entity::SetPosition((SCREEN_WIDTH - PLANE_WIDTH)/2, SCREEN_HEIGHT - PLANE_HEIGHT - 100);
            spaceship.SetWidthHeight(PLANE_WIDTH, PLANE_HEIGHT);
        }

        if(game)
        {
            if (!GameOver && !victory)
            {
                if (!pause)
                {
                    if (!Mix_Playing(2))
                        Mix_PlayChannel(2, Game_Music, 0);

                    game_background.MoveBackground(ren);

                    PauseButton.SetWidthHeight(50, 50);
                    PauseButton.Entity::SetPosition(50, (SCREEN_HEIGHT - 50)/2);
                    PauseButton.Pause(e, ren, pause);
                    PauseButton.Display(ren);

                    spaceship.Plane::loadIMG(plane_number, ren);
                    spaceship.HandleInputAction(e, ren, plane_bullet_sound);
                    spaceship.MakeBullet(ren);
                    spaceship.Display(ren);

                    SwapWave(chicken_list, ren, wave, victory);
                    Collision(chicken_list, spaceship, egg_list, ren, GameOver, score, chicken_die_sound);

                    SDL_RenderPresent(ren);
                }

                else
                {
                    PauseButton.Pause(e, ren, pause);
                    PauseButton.Display(ren);

                    ContinueButton.SetWidthHeight(100, 100);
                    ContinueButton.Entity::SetPosition(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 150);
                    ContinueButton.Continue(e, ren, pause);
                    ContinueButton.Display(ren);

                    HomeButton.SetWidthHeight(100, 100);
                    HomeButton.Entity::SetPosition(100, SCREEN_HEIGHT - 150);
                    HomeButton.Home(e, ren, QuitMenu, game, GameOver, reset, pause, menu, score_screen);
                    HomeButton.Display(ren);

                    SDL_RenderPresent(ren);
                }
            }

            if (victory)
            {
                Mix_HaltChannel(2);

                if (!score_screen)
                {
                    if (!Mix_Playing(3))
                        Mix_PlayChannel(3, victory_music_sound, 0);

                    game_victory.Display(ren);

                    NextButton.SetWidthHeight(200, 50);
                    NextButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT - 100);
                    NextButton.Next(e, ren, score_screen);
                    NextButton.Display(ren);

                    SDL_RenderPresent(ren);
                }

                else
                {
                    Mix_HaltChannel(3);

                    game_score.Display(ren);

                    Score.set_text(to_string(score));
                    Score.loadText(font, ren);
                    Score.Display(ren);

                    HomeButton.SetWidthHeight(100, 100);
                    HomeButton.Entity::SetPosition(100, SCREEN_HEIGHT - 150);
                    HomeButton.Home(e, ren, QuitMenu, game, GameOver, reset, pause, menu, score_screen);
                    HomeButton.Display(ren);

                    RestartButton.SetWidthHeight(100, 100);
                    RestartButton.Entity::SetPosition(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 150);
                    RestartButton.Restart(e, ren, chicken_list, spaceship, egg_list, wave, score, SetPositionPlane, victory, GameOver, score_screen);
                    RestartButton.Display(ren);

                    SDL_RenderPresent(ren);
                }
            }

            if (GameOver)
            {
                Mix_HaltChannel(2);

                if (!score_screen)
                {
                    if (!Mix_Playing(4))
                        Mix_PlayChannel(4, gameover_music_sound, 0);

                    game_gameover.Display(ren);

                    NextButton.SetWidthHeight(200, 50);
                    NextButton.Entity::SetPosition(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT - 100);
                    NextButton.Next(e, ren, score_screen);
                    NextButton.Display(ren);

                    SDL_RenderPresent(ren);
                }

                else
                {
                    Mix_HaltChannel(4);

                    game_score.Display(ren);

                    Score.set_text(to_string(score));
                    Score.loadText(font, ren);
                    Score.Display(ren);

                    HomeButton.SetWidthHeight(100, 100);
                    HomeButton.Entity::SetPosition(100, SCREEN_HEIGHT - 150);
                    HomeButton.Home(e, ren, QuitMenu, game, GameOver, reset, pause, menu, score_screen);
                    HomeButton.Display(ren);

                    RestartButton.SetWidthHeight(100, 100);
                    RestartButton.Entity::SetPosition(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 150);
                    RestartButton.Restart(e, ren, chicken_list, spaceship, egg_list, wave, score, SetPositionPlane, victory, GameOver, score_screen);
                    RestartButton.Display(ren);

                    SDL_RenderPresent(ren);
                }
            }

            PauseButton.Free();
            ContinueButton.Free();
            NextButton.Free();
            HomeButton.Free();
            RestartButton.Free();
            spaceship.Free();
            Score.Free();
        }
    }

    for (int i = 0; i < int(egg_list.size()); i++)
    {
        Bullet* egg = egg_list[i];
        if (egg != NULL)
        {
            delete egg;
            egg = NULL;
        }
    }
    egg_list.clear();

    for (int i = 0; i < int(chicken_list.size()); i++)
    {
        Chicken* chicken = chicken_list[i];
        if (chicken != NULL)
        {
            delete chicken;
            chicken = NULL;
        }
    }
    chicken_list.clear();

}
