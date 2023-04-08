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

        loadIMG("assets/left_arrow_click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN && a)
        {
            a = 0;
            plane_number -= 1;
        }

    }
    else
    {
        loadIMG("assets/left_arrow.png", ren);

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
            loadIMG("assets/left_arrow_click.png", ren);
    }


}

void Menu::Right(SDL_Event& e, SDL_Renderer* ren, int& plane_number)
{

    if (Click())
    {
        bool a = 1;

        loadIMG("assets/right_arrow_click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN && a)
        {
            a = 0;
            plane_number += 1;
        }

    }
    else
    {
        loadIMG("assets/right_arrow.png", ren);

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
            loadIMG("assets/right_arrow_click.png", ren);
    }

}


void Menu::Play(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& game, bool& QuitMenu)
{

    if (Click())
    {
        loadIMG("assets/Play_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            game = true;
            QuitMenu = true;
        }
    }
    else
        loadIMG("assets/Play_Button.png", ren);

}


void Menu::Skin(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin)
{

    if (Click())
    {
        loadIMG("assets/Skin_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            skin = true;
        }
    }
    else
        loadIMG("assets/Skin_Button.png", ren);

}


void Menu::Choose(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin)
{

    if (Click())
    {
        loadIMG("assets/Choose_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = true;
            skin = false;
        }
    }
    else
        loadIMG("assets/Choose_Button.png", ren);

}


void Menu::Help(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help)
{

    if (Click())
    {
        loadIMG("assets/Help_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = false;
            help = true;
        }
    }
    else
        loadIMG("assets/Help_Button.png", ren);

}


void Menu::Exit(SDL_Event& e, SDL_Renderer* ren, bool& isRunning)
{

    if (Click())
    {
        loadIMG("assets/Exit_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            isRunning = false;
        }
    }
    else
        loadIMG("assets/Exit_Button.png", ren);

}


void Menu::Back(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help, bool& skin)
{

    if (Click())
    {
        loadIMG("assets/Back_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            menu = true;
            help = false;
            skin = false;
        }
    }
    else
        loadIMG("assets/Back_Button.png", ren);

}


void Menu::Pause(SDL_Event& e, SDL_Renderer* ren, bool& pause)
{

    if (Click())
    {
        loadIMG("assets/Pause_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            pause = true;
        }
    }
    else
    {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
        {
            loadIMG("assets/Pause_Button_Click.png", ren);
            pause = Reverse(pause);
        }
        else if (pause) loadIMG("assets/Pause_Button_Click.png", ren);
        else
            loadIMG("assets/Pause_Button.png", ren);
    }

}


void Menu::Continue(SDL_Event& e, SDL_Renderer* ren, bool& pause)
{

    if (Click())
    {
        loadIMG("assets/Continue_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            pause = false;
        }
    }
    else
        loadIMG("assets/Continue_Button.png", ren);

}


void Menu::Next(SDL_Event& e, SDL_Renderer* ren, bool& score_screen)
{

    if (Click())
    {
        loadIMG("assets/Next_Button_Click.png", ren);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            score_screen = true;
        }
    }
    else
        loadIMG("assets/Next_Button.png", ren);

}


void Menu::Home(SDL_Event& e, SDL_Renderer* ren, bool& QuitMenu, bool& game, bool& GameOver, bool& reset, bool& pause, bool& menu, bool& score_screen)
{

    if (Click())
    {
        loadIMG("assets/Home_Button_Click.png", ren);
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
        loadIMG("assets/Home_Button.png", ren);

}


void Menu::Restart(SDL_Event& e, SDL_Renderer* ren, vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, int& wave, int& score, bool& SetPositionPlane, bool& victory, bool& GameOver, bool& score_screen)
{

    if (Click())
	{
	    loadIMG("assets/Restart_Button_Click.png", ren);
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
		    GameOver = false;
		    score_screen = false;
            Reset(chicken_list, spaceship, egg_list, wave, score, SetPositionPlane, victory);
		}
	}
	else
		loadIMG("assets/Restart_Button.png", ren);

}
