#ifndef COLLISION_H
#define COLLISION_H

#include "ChickenWave.h"


void Reset(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, int& wave, int& score, bool& SetPositionPlane, bool& victory);

bool CheckCollision(SDL_Rect a, SDL_Rect b);

void Collision(vector<Chicken*> &chicken_list, Plane &spaceship, vector<Bullet*> &egg_list, SDL_Renderer* ren, bool& GameOver, int& score, Mix_Chunk* chicken_die);

#endif // COLLISION_H
