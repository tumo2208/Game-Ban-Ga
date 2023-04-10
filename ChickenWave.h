#ifndef CHICKENWAVE_H
#define CHICKENWAVE_H

#include "Chicken.h"


void Chicken_Wave_1(vector<Chicken*> &chicken_list, SDL_Renderer* ren);
void Chicken_Wave_2(vector<Chicken*> &chicken_list, SDL_Renderer* ren);
void Chicken_Wave_3(vector<Chicken*> &chicken_list, SDL_Renderer* ren);
void Chicken_Wave_4(vector<Chicken*> &chicken_list, SDL_Renderer* ren);
void Chicken_Wave_5(vector<Chicken*> &chicken_list, SDL_Renderer* ren);
void Chicken_Wave_6(vector<Chicken*> &chicken_list, SDL_Renderer* ren);

void SwapWave(vector<Chicken*> &chicken_list, SDL_Renderer* ren, int& wave, bool& victory);

#endif // CHICKENWAVE_H
