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

const int Number_of_chickenwave1 = 0;
const int Number_of_chickenwave2 = 8;
const int Number_of_chickenwave3 = 3;
const int Number_of_chickenwave4 = 2;
const int Number_of_chickenwave5 = 0;
const int Number_of_chickenwave6 = 10;


int GetRandom();
int mod (int a, int b);
bool Reverse(bool a);

#endif // COMMONFUNCTION_H
