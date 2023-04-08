#include "ConstVal.h"


int GetRandom()
{

    srand(time(NULL));
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
