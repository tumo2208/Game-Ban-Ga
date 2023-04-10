#include "Collision.h"


void Reset(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, int& wave, int& score, bool& SetPositionPlane, bool& victory)
{

    wave = 0;
    score = 0;
    SetPositionPlane = true;
    victory = false;
    chicken_list.erase(chicken_list.begin(), chicken_list.end());
    egg_list.erase(egg_list.begin(), egg_list.end());
    spaceship.ResetBulletPlane();

}


bool CheckCollision(SDL_Rect a, SDL_Rect b)
{

    if (a.x + a.w >= b.x&&
        b.x + b.w >= a.x&&
        a.y + a.h >= b.y&&
        b.y + b.h >= a.y)
            return true;

    return false;

}


void Collision(vector<Chicken*> &chicken_list, Plane &spaceship,
               vector<Bullet*> &egg_list, SDL_Renderer* ren, bool &GameOver, int& score, Mix_Chunk* chicken_die)
{

    for (int i = 0; i < int(chicken_list.size()); i++)
    {
        Chicken *chicken = chicken_list[i];
        if (chicken != NULL)
        {
            chicken->ChickenMove();
            chicken->Display(ren);
            if (chicken->CanShoot())
            {
                chicken->MakeBullet(egg_list, ren, spaceship);
            }
            SDL_Rect spaceshipRect = spaceship.GetRect();
            if(chicken != NULL)
            {
                SDL_Rect ChickenRect = chicken->GetRect();
                bool Chicken_to_Spaceship = CheckCollision(spaceshipRect, ChickenRect);
                if (Chicken_to_Spaceship)
                {

                    GameOver = true;
                }
            }
        }
    }

    for (int i = 0; i < int(egg_list.size()); i++)
    {
        Bullet* egg = egg_list[i];
        if (egg != NULL)
        {
            SDL_Rect EggRect = egg->GetRect();
            SDL_Rect spaceship_Rect = spaceship.GetRect();
            bool ChickenBullet_to_spaceship = CheckCollision(EggRect, spaceship_Rect);
            if(ChickenBullet_to_spaceship)
            {
                GameOver = true;
                egg_list.erase(egg_list.begin() + i);
            }
            if (egg->get_is_move())
            {
                egg->BulletMove(SCREEN_WIDTH,SCREEN_HEIGHT);
                egg->Display(ren, egg->get_index());
            }
            else
            {
                egg_list.erase(egg_list.begin() + i);
                delete egg;
                egg = NULL;
            }
        }
    }

    vector<Bullet*> spaceship_bullet_list = spaceship.GetBulletList();
    for (int i = 0; i < int(spaceship_bullet_list.size()); i++)
    {
        Bullet* bullet = spaceship_bullet_list[i];
        if (bullet != NULL)
        {
            for (int j = 0; j < int(chicken_list.size()); j++)
            {
                Chicken* chicken = chicken_list[j];
                if (chicken != NULL)
                {
                    SDL_Rect Chicken_Rect = chicken->GetRect();
                    SDL_Rect BulletRect = bullet->GetRect();
                    bool SpaceshipBullet_to_Chicken = CheckCollision(Chicken_Rect, BulletRect);
                    if (SpaceshipBullet_to_Chicken)
                    {
                        Mix_PlayChannel(-1, chicken_die, 0);
                        chicken->set_health(chicken->get_health() - 1);
                        spaceship.RemoveBullet(i);
                        if (chicken->die(score))
                        {
                            if (chicken != NULL)
                            {
                                chicken_list.erase(chicken_list.begin() + j);
                                delete chicken;
                                chicken = NULL;
                            }
                        }
                    }
                }
            }
        }
    }
}
