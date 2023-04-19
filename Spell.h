#ifndef SPELL_H
#define SPELL_H

#include "Entity.h"


class Spell : public Entity
{
    public:
        Spell();
        ~Spell();

        void SpellMove(const int &x_border,const int &y_border);
        void set_is_move(const bool& ismove) {isMove = ismove;}
        bool get_is_move() const {return isMove;}
        void set_type(const int& Type) {type = Type;}
        int get_type()  const {return type;}

    private:

        bool isMove;
        int type;
};

#endif // SPELL_H
