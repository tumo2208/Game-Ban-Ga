#ifndef GAME_H
#define GAME_H

#include "ConstVal.h"


class Game
{
    public:
        Game();
        ~Game();

        void Run();
        void EndLoop();


    private:
        SDL_Window* win;
        SDL_Renderer* ren;
        SDL_Event e;

        int score;
        bool isRunning, game, QuitMenu, victory, GameOver, pause, score_screen, menu, skin, help, SetPositionPlane, reset;

};

#endif // GAME_H
