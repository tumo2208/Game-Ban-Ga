#include "Spell.h"


Spell::Spell()
{
    rect = {0, 0, 0, 0};
    texture = NULL;
    isMove = false;
    type = 0;
}


Spell::~Spell()
{
    Free();
}


void Spell::SpellMove(const int& x_border, const int& y_border)
{

    rect.y += SPELL_SPEED;

    if (rect.y >= y_border)
    {
        isMove = false;
    }

}
