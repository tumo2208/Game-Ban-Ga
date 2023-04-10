#include "Bullet.h"


Bullet::Bullet()
{

    rect = {0, 0, 0, 0};
    texture = NULL;
    xpos = ypos = 0.f;
    x_speed = y_speed = 0.f;
    type = 0;
    angle = 90;
    index = 0;
    isMove = false;

}


Bullet::~Bullet()
{
    Free();
}


void Bullet::BulletMove(const int& x_border, const int& y_border)
{

    if(type==1)
    {
        xpos+=x_speed*cos(angle*M_PI/180);
        ypos+=y_speed*sin(angle*M_PI/180);
    }

    if(rect.y < 0 || rect.y > y_border)
    {
        isMove = false;
    }

    if(rect.x < 0 || rect.x > x_border)
    {
        isMove=false;
    }
    rect.x = float(xpos);
    rect.y = float(ypos);

}


