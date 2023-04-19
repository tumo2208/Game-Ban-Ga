#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;


const int SCREEN_WIDTH = 1440, SCREEN_HEIGHT = 800;
const int SCREEN_SPEED = 1;
const string SCREEN_TITLE = "Ban Ga";

const int PLANE_SPEED = 5;
const int PLANE_WIDTH = 100, PLANE_HEIGHT = 100;
const int PLANE_WIDTH_SKIN = 300, PLANE_HEIGHT_SKIN = 300;

const int PlaneBullet_WIDTH = 20, PlaneBullet_HEIGHT = 60, PlaneBullet_SPEED = 8;

const int CHICKEN_SPEED = 2;
const int CHICKEN_WIDTH = 76, CHICKEN_HEIGHT = 62, CHICKEN_SMALL_WIDTH = 50, CHICKEN_SMALL_HEIGHT = 45;
const int METEORITE_SPEED = 6;
const int METEORITE_WIDTH = 120, METEORITE_HEIGHT = 200;

const int SPELL_SPEED = 2;
const int SPELL_WIDTH = 50, SPELL_HEIGHT = 50;

const int Number_of_chickenwave1_small_hang13 = 5;
const int Number_of_chickenwave1_small_hang2 = 3;
const int Number_of_chickenwave1_big = 2;
const int Number_of_chickenwave2 = 8;
const int Number_of_chickenwave3 = 3;
const int Number_of_chickenwave4 = 2;
const int Number_of_chickenwave5 = 1;
const int Number_of_chickenwave6_small = 3;
const int Number_of_chickenwave6_big = 2;
const int Number_of_chickenwave7 = 10;
const int Number_of_chickenwave8_big = 1;
const int Number_of_chickenwave8_small = 8;
const int Number_of_chickenwave8_shield = 6;
const int Number_of_chickenwave9 = 5;


int GetRandom_wave7();
int mod (int a, int b);
bool Reverse(bool a);
int random_angle_1();

#endif // COMMONFUNCTION_H
