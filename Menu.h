#ifndef MENU_H
#define MENU_H

#include "Collision.h"

class Menu : public Entity
{
    public:
        Menu();
        ~Menu();

        void Left(SDL_Event& e, SDL_Renderer* ren, int& plane_number);
        void Right(SDL_Event& e, SDL_Renderer* ren, int& plane_number);
        void Play(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& game, bool& QuitMenu);
        void Skin(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin);
        void Choose(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& skin);
        void Help(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help);
        void Exit(SDL_Event& e, SDL_Renderer* ren, bool& isRunning);
        void Back(SDL_Event& e, SDL_Renderer* ren, bool& menu, bool& help, bool& skin);
        void Pause(SDL_Event& e, SDL_Renderer* ren, bool& pause);
        void Continue(SDL_Event& e, SDL_Renderer* ren, bool& pause);
        void Next(SDL_Event& e, SDL_Renderer* ren, bool& score);
        void Home(SDL_Event& e, SDL_Renderer* ren, bool& QuitMenu, bool& game, bool& GameOver, bool& reset, bool& pause, bool& menu, bool& score_screen);
        void Restart(SDL_Event& e, SDL_Renderer* ren, vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> spell_list, int& wave, int& score, bool& SetPositionPlane, bool& victory, bool& GameOver, bool& score_screen);

};

#endif // MENU_H
