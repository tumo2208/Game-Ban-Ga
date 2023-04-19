#ifndef COLLISION_H
#define COLLISION_H

#include "ChickenWave.h"
#include "Spell.h"


void Reset(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> spell_list, int& wave, int& score, bool& SetPositionPlane, bool& victory);

bool CheckCollision(SDL_Rect a, SDL_Rect b);

void Collision(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, vector<Spell*> &spell_list, SDL_Renderer* ren, SDL_Event& e, bool& GameOver, bool pause, int wave, int& score, int& count_chicken_wave8, Mix_Chunk* chicken_die, Mix_Chunk* meteorite_die, Mix_Chunk* egg_cracking, Mix_Chunk* metal_sound);

#endif // COLLISION_H
