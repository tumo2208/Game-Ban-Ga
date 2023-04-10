#include "Chicken.h"


Chicken::Chicken()
{

    rect = {0, 0, 0, 0};
    texture = NULL;
    xpos = ypos = 0.f;
    x_speed = CHICKEN_SPEED;
    y_speed = CHICKEN_SPEED;
    x_limit = y_limit = 0.f;
    type = 0;
    angle = 0;
    hp = 1;
    chicken_score = 0;
    delay_shoot_time = 0;
    CurrentTime = LastTime = 0;

}


Chicken::~Chicken()
{
    Free();
}


void Chicken::ChickenMove()
{

    if (type == 2 || type == 3)
    {
        if (ypos >= y_limit)
            ypos = y_limit;
        ypos += y_speed;
    }

    /*if (type == 4)
    {
        if (xpos > x_limit)
        {
            if (ypos < y_limit)
            {
                ypos += 1;
                xpos = float(sqrt(1 - float((ypos - 100)/400)*float((ypos - 100)/400)))*690 + 750;
            }
            else
            {
                ypos -= 1;
                xpos = -float(sqrt(1 - float((ypos - 100)/400)*float((ypos - 100)/400)))*690 + 750;
            }
        }
    }*/

    if (type == 4)
    {
        if (xpos >= x_limit)
            xpos = x_limit;
        xpos += x_speed;
    }

    if (type == 5)
    {
        if (xpos <= x_limit)
            xpos = x_limit;
        xpos -= x_speed;

    }

    /*if (type == 6)
    {
        if (xpos >= x_limit)
        {
            xpos = x_limit;
            ypos = y_limit;
        }
        xpos += x_speed*cos(M_PI*angle/180);
        ypos += y_speed*sin(M_PI*angle/180);
    }

    if (type == 7)
    {
        if (xpos <= x_limit)
        {
            xpos = x_limit;
            ypos = y_limit;
        }
        xpos -= x_speed*cos(M_PI*angle/180);
        ypos -= y_speed*sin(M_PI*angle/180);
    }*/

    if (type == 11)
    {
       ypos += METEORITE_SPEED;

       if (ypos >= SCREEN_HEIGHT)
            Chicken::SetPosition(GetRandom(), -METEORITE_HEIGHT);
    }

    rect.y = float(ypos);
    rect.x = float(xpos);

}


bool Chicken::CanShoot()
{

    CurrentTime = SDL_GetTicks();
    bool check_can_spawn = false;
    if (type == 2 || type == 3)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && ypos >= y_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    /*if (type == 4)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos <= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }*/

    if (type == 4 /*|| type == 6*/)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos >= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    if (type == 5 /*|| type == 7*/)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos <= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    if (type == 11) {}



    return check_can_spawn;

}


void Chicken::MakeBullet(vector<Bullet*> &egg_list, SDL_Renderer* ren, Plane &spaceship)
{

    if (type == 2)
    {
        delay_shoot_time = 2000;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->set_index(0);
        egg->loadIMG("bin/Debug/assets/egg.png", ren);
        egg->set_is_move(true);
        egg->set_angle(90);
        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 10, rect.y + rect.h + 10);
        egg->SetWidthHeight(20, 20);
        egg_list.push_back(egg);
    }

    if (type == 3)
    {
        for (int i = 0; i < 12; i++)
        {
            delay_shoot_time = 3000;
            Bullet* egg = new Bullet();
            egg->set_type(1);

            if (i == 1 || i == 2 || i == 7 || i == 8) egg->set_index(0 - 30*i);
            else if (i == 3 || i == 9) egg->set_index(90 - 30*i);
            else if (i == 4 || i == 5 || i == 10 || i == 11) egg->set_index(180 - 30*i);
            else egg->set_index(270 - 30*i);

            egg->loadIMG("bin/Debug/assets/Chicken_waste.png", ren);
            egg->set_is_move(true);
            egg->set_angle(0 + 30*i);
            egg->set_x_speed(3);
            egg->set_y_speed(3);
            egg->Bullet::SetPosition(rect.x + rect.w/2, rect.y + rect.h/2);
            egg->SetWidthHeight(10, 10);
            egg_list.push_back(egg);
        }
    }

    /*if (type == 4)
    {
        delay_shoot_time = 2000;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->set_index(0);
        egg->loadIMG("bin/Debug/assets/egg.png", ren);
        egg->set_is_move(true);
        egg->set_angle(90);
        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 10, rect.y + rect.h + 10);
        egg->SetWidthHeight(20, 20);
        egg_list.push_back(egg);
    }*/

    if (type == 4 || type == 5)
    {
        delay_shoot_time = 2000;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->set_index(0);
        egg->loadIMG("bin/Debug/assets/Chicken_waste.png", ren);
        egg->set_is_move(true);
        egg->set_angle(90);
        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 5, rect.y + rect.h + 10);
        egg->SetWidthHeight(10, 20);
        egg_list.push_back(egg);
    }

    if (type == 11){}



}

