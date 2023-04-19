#include "Collision.h"


void Reset(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> spell_list, int& wave, int& score, bool& SetPositionPlane, bool& victory)
{

    wave = 0;
    score = 0;
    SetPositionPlane = true;
    victory = false;
    chicken_list.erase(chicken_list.begin(), chicken_list.end());
    egg_list.erase(egg_list.begin(), egg_list.end());
    spell_list.erase(spell_list.begin(), spell_list.end());
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


void Collision(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> &spell_list,
               SDL_Renderer* ren, SDL_Event& e, bool &GameOver, bool pause, int wave, int& score, int& count_chicken_wave8,
               Mix_Chunk* chicken_die, Mix_Chunk* meteorite_die, Mix_Chunk* egg_cracking, Mix_Chunk* metal_sound)
{

    int rand_spell = rand()%2;

    for (int i = 0; i < int(chicken_list.size()); i++)
    {
        Chicken *chicken = chicken_list[i];
        if (chicken != NULL)
        {
            chicken->ChickenMove();
            chicken->Display(ren);
            if (chicken->CanShoot(pause, e))
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

    if (wave == 5)
    {
        for (int i = 0; i < int(chicken_list.size()); i++)
        {
            Chicken* chicken = chicken_list[i];
            if (chicken != NULL && chicken->die())
            {
                if (!chicken->get_time_wave_5_out())
                {
                    score += chicken->get_score();

                    Spell* spell = new Spell();
                    if (rand_spell == 1)
                    {
                        spell->loadIMG("bin/Debug/assets/Spell_twin_bullet.png", ren);
                        spell->set_type(1);
                    }

                    if (rand_spell == 0)
                    {
                        spell->loadIMG("bin/Debug/assets/Spell_trio_bullet.png", ren);
                        spell->set_type(2);
                    }

                    spell->Entity::SetPosition(chicken->GetRect().x + chicken->GetRect().w/2 - 15, chicken->GetRect().y + chicken->GetRect().h);
                    spell->SetWidthHeight(SPELL_WIDTH, SPELL_HEIGHT);
                    spell->set_is_move(true);

                    spell_list.push_back(spell);
                }

                chicken_list.erase(chicken_list.begin() + i);
                delete chicken;
                chicken = NULL;
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
                    if (wave == 5)
                    {
                        if (SpaceshipBullet_to_Chicken)
                        {
                            Mix_PlayChannel(-1, egg_cracking, 0);

                            chicken->set_health(chicken->get_health() - 1);
                            spaceship.RemoveBullet(i);
                        }
                    }

                    else
                    {
                        if (SpaceshipBullet_to_Chicken)
                        {
                            if (wave != 7)
                            {
                                if (chicken->get_type() == 12 || chicken->get_type() == 16)
                                    Mix_PlayChannel(-1, metal_sound, 0);

                                else Mix_PlayChannel(-1, chicken_die, 0);

                            }

                            chicken->set_health(chicken->get_health() - 1);
                            spaceship.RemoveBullet(i);
                            if (chicken->die())
                            {
                                if (wave == 7)
                                    Mix_PlayChannel(-1, meteorite_die, 0);

                                if (wave == 8 && chicken->get_type() != 16)
                                    count_chicken_wave8 ++;

                                score += chicken->get_score();
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

    if (wave == 8 && count_chicken_wave8 == 9)
    {
        for (int i = 0; i < int(chicken_list.size()); i++)
        {
            Chicken* chicken = chicken_list[i];
            if (chicken->get_type() == 16)
            {
                chicken_list.erase(chicken_list.begin() + i);
                delete chicken;
                chicken = NULL;
            }
        }
    }

    if (wave != 8)
        count_chicken_wave8 -= count_chicken_wave8;

    for (int i = 0; i < int(spell_list.size()); i++)
    {
        Spell* spell = spell_list[i];
        SDL_Rect SpellRect = spell->GetRect();
        SDL_Rect SpaceshipRect = spaceship.GetRect();
        bool EatSpell = CheckCollision(SpellRect, SpaceshipRect);
        if (EatSpell)
        {
            if (spell->get_type() == 1)
                spaceship.set_type_spell(2);
            if (spell->get_type() == 2)
                spaceship.set_type_spell(3);

            spell_list.erase(spell_list.begin() + i);
        }
        if (spell->get_is_move())
        {
            spell->SpellMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            spell->Display(ren);
        }
        else
        {
            spell_list.erase(spell_list.begin() + i);
            delete spell;
            spell = NULL;
        }
    }
}
