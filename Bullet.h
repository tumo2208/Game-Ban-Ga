#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"


class Bullet : public Entity
{
    public:
        Bullet();
        ~Bullet();

        void SetPosition(const float& x, const float& y)
        {
            xpos = x;
            ypos = y;
        }
        void set_type(const int& Type) {type=Type;}
        void set_index(const int& i) {index = i;}
        int get_index() const {return index;}
        void set_angle(const int& Angle) {angle = Angle;}
        void set_x_speed(const float& x) {x_speed=x;}
        void set_y_speed(const float& y) {y_speed=y;}
        void set_is_move(const bool& ismove) {isMove = ismove;}
        bool get_is_move() const {return isMove;}
        void BulletMove(const int &x_border,const int &y_border);


    private:
        float xpos, ypos;
        float x_speed, y_speed;
        int type;
        int angle;
        int index;

        bool isMove;

};

#endif // BULLET_H
