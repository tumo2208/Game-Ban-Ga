#include "Menu.h"


Menu::Menu()
{

    rect = {0, 0, 0, 0};
    texture = NULL;

}


Menu::~Menu()
{
    Free();
}


void Menu::Left(SDL_Event& e, SDL_Renderer* ren, int& plane_number)
{



    if (Click())
    {
        bool a = 1;

        loadIMG("bin/Debug/assets/left_arrow_click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN && a)
        {
            a = 0;
            plane_number -= 1;
        }

    }
    else
    {
        loadIMG("bin/Debug/assets/left_arrow.png", ren);

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
            loadIMG("bin/Debug/assets/left_arrow_click.png", ren);
    }


}

void Menu::Right(SDL_Event& e, SDL_Renderer* ren, int& plane_number)
{

    if (Click())
    {
        bool a = 1;

        loadIMG("bin/Debug/assets/right_arrow_click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN && a)
        {
            a = 0;
            plane_number += 1;
        }

    }
    else
    {
        loadIMG("bin/Debug/assets/right_arrow.png", ren);

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
            loadIMG("bin/Debug/assets/right_arrow_click.png", ren);
    }

}


void Menu::Play(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& game, bool& QuitMenu)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Play_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            game = true;
            QuitMenu = true;
        }
    }
    else
        loadIMG("bin/Debug/assets/Play_Button.png", ren);

}


void Menu::Skin(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Skin_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            skin = true;
        }
    }
    else
        loadIMG("bin/Debug/assets/Skin_Button.png", ren);

}


void Menu::Choose(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Choose_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = true;
            skin = false;
        }
    }
    else
        loadIMG("bin/Debug/assets/Choose_Button.png", ren);

}


void Menu::Help(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Help_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            help = true;
        }
    }
    else
        loadIMG("bin/Debug/assets/Help_Button.png", ren);

}


void Menu::Exit(SDL_Event& e, SDL_Renderer* ren, bool& isRunning)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Exit_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            isRunning = false;
        }
    }
    else
        loadIMG("bin/Debug/assets/Exit_Button.png", ren);

}


void Menu::Back(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help, bool& skin)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Back_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = true;
            help = false;
            skin = false;
        }
    }
    else
        loadIMG("bin/Debug/assets/Back_Button.png", ren);

}


void Menu::Pause(SDL_Event& e, SDL_Renderer* ren, bool& pause)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Pause_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            pause = true;
        }
    }
    else
    {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
        {
            loadIMG("bin/Debug/assets/Pause_Button_Click.png", ren);
            pause = Reverse(pause);
        }
        else if (pause) loadIMG("bin/Debug/assets/Pause_Button_Click.png", ren);
        else
            loadIMG("bin/Debug/assets/Pause_Button.png", ren);
    }

}


void Menu::Continue(SDL_Event& e, SDL_Renderer* ren, bool& pause)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Continue_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            pause = false;
        }
    }
    else
        loadIMG("bin/Debug/assets/Continue_Button.png", ren);

}


void Menu::Next(SDL_Event& e, SDL_Renderer* ren, bool& score_screen)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Next_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            score_screen = true;
        }
    }
    else
        loadIMG("bin/Debug/assets/Next_Button.png", ren);

}


void Menu::Home(SDL_Event& e, SDL_Renderer* ren, bool& QuitMenu, bool& game, bool& GameOver, bool& reset, bool& pause, bool& menu, bool& score_screen)
{

    if (Click())
    {
        loadIMG("bin/Debug/assets/Home_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            QuitMenu = false;
            game = false;
            GameOver = false;
            reset = true;
            pause = false;
            menu = true;
            score_screen = false;
        }
    }
    else
        loadIMG("bin/Debug/assets/Home_Button.png", ren);

}


void Menu::Restart(SDL_Event& e, SDL_Renderer* ren, vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> spell_list, int& wave, int& score, bool& SetPositionPlane, bool& victory, bool& GameOver, bool& score_screen)
{

    if (Click())
	{
	    loadIMG("bin/Debug/assets/Restart_Button_Click.png", ren);
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
		    GameOver = false;
		    score_screen = false;
            Reset(chicken_list, spaceship, egg_list, spell_list, wave, score, SetPositionPlane, victory);
		}
	}
	else
		loadIMG("bin/Debug/assets/Restart_Button.png", ren);

}
