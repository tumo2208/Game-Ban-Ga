#include "ConstVal.h"


int GetRandom_wave7()
{

    int ran = rand() % 60 * 24;
    return ran;

}


int mod (int a, int b)
{

    int c = a%b;
    c > 0 ? c = c : c+=b;
    return c;

}


bool Reverse(bool a)
{

    if (a == true)  return false;
    else return true;

}


int random_angle_1()
{

    return rand()%(165-15+1)+15;

}
