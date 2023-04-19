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
    time_wave5_out = 30000;
    time_wave_5_out = false;
    set_lasttime = true;
    chieu = true;
    angle_bullet = 90;
    angle_rotate_speed = 10;
    delay_shoot_time = 0;
    CurrentTime = LastTime = 0;
    TimePause = 0;
    TimeEndPause = 0;
    boss_bullet = 0;

}


Chicken::~Chicken()
{
    Free();
}


void Chicken::RotateBullet()
{

    if (angle_bullet >= 360)
    {
        angle_bullet = 0;
    }

    if (chieu)
        angle_bullet += angle_rotate_speed;

    else
        angle_bullet -= angle_rotate_speed;

}


void Chicken::ChickenMove()
{

    if (type == 1 || type == 2)
    {
        if (xpos <= x_limit)
            xpos = x_limit;
        xpos -= x_speed;
    }

    if (type == 3)
    {
        if (xpos >= x_limit)
            xpos = x_limit;
        xpos += x_speed;
    }

    if (type == 4 || type == 5 || type == 6 || type == 11 || type == 12 || type == 14 || type == 15 || type == 16)
    {
        if (ypos >= y_limit)
            ypos = y_limit;
        ypos += y_speed;
    }

    /*if (type == 7)
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

    if (type == 7)
    {
        if (xpos >= x_limit)
            xpos = x_limit;
        xpos += x_speed;
    }

    if (type == 8)
    {
        if (xpos <= x_limit)
            xpos = x_limit;
        xpos -= x_speed;

    }

    if (type == 10)
    {
        CurrentTime = SDL_GetTicks();

        if (rect.y <= -240 && set_lasttime)
        {
            LastTime = CurrentTime;
            set_lasttime = false;
        }

        if (CurrentTime <= time_wave5_out + LastTime)
        {
            if (ypos <= y_limit)
            {
                ypos += CHICKEN_SPEED;
            }
            else
            {
                set_y_limit(-1000);

                xpos += 3.305*cos(angle*M_PI/180);

                if (xpos >= SCREEN_WIDTH - 180)
                    set_angle(180);
                if (xpos <= 0)
                    set_angle(0);
            }
        }

        else
        {
            ypos -= CHICKEN_SPEED;

            if (ypos < -300 && ypos >= y_limit)
            {
                time_wave_5_out = true;
            }
        }

        if (time_wave_5_out == true)
        {
            set_health(0);
        }
    }

    if (type == 13)
    {
       ypos += METEORITE_SPEED;

       if (ypos >= SCREEN_HEIGHT)
            Chicken::SetPosition(GetRandom_wave7(), -METEORITE_HEIGHT);
    }

    if (type == 17)
    {
        if (xpos >= x_limit)
            xpos = x_limit;
        xpos += x_speed;
    }

    if (type == 18)
    {
        if (xpos <= x_limit)
            xpos = x_limit;
        xpos -= x_speed;
    }

    if (type == 20)
    {
        if (ypos <= y_limit)
        {
            ypos += CHICKEN_SPEED;
        }
        else
        {
            set_y_limit(-100);
            srand(time(NULL));

            ypos += y_speed*sin(M_PI*angle/180);
            xpos += x_speed*cos(M_PI*angle/180);

            if (xpos >= SCREEN_WIDTH - 250)
            {
                set_angle(rand()%181 + 90);
            }

            if (xpos <= 0)
            {
                set_angle(rand()%181 - 90);
            }

            if (ypos >= SCREEN_HEIGHT - 225)
            {
                set_angle(rand()%181 + 180);
            }

            if (ypos <= 0)
            {
                set_angle(rand()%181);
            }

        }
    }

    rect.y = float(ypos);
    rect.x = float(xpos);

}


bool Chicken::CanShoot(bool pause, SDL_Event& e)
{

    CurrentTime = SDL_GetTicks();
    bool check_can_spawn = false;

    /*if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
    {
        if (pause)
        {
            TimeEndPause = CurrentTime;
            LastTime += (TimeEndPause - TimePause);
        }

        else
        {
            TimePause = CurrentTime;
        }
    }*/

    if (type == 4 || type == 5 || type == 6 || type == 11 || type == 12 || type == 14 || type == 15 || type == 20)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && ypos >= y_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    /*if (type == 7)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos <= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }*/

    if (type == 7 || type == 17)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos >= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    if (type == 8 || type == 18)
    {
        if (CurrentTime >= LastTime + delay_shoot_time && xpos <= x_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = true;
        }
    }

    if (type == 1 || type == 2 || type == 3 || type == 10 || type == 13 || type == 16) {}


    return check_can_spawn;

}


void Chicken::MakeBullet(vector<Bullet*> &egg_list, SDL_Renderer* ren, Plane &spaceship)
{

    if (type == 1 || type == 2 || type == 3) {}

    if (type == 4)
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

    if (type == 5)
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

    if (type == 6)
    {
        for (int i = 0; i < 12; i++)
        {
            delay_shoot_time = 3000;
            Bullet* egg = new Bullet();
            egg->set_type(1);
            egg->loadIMG("bin/Debug/assets/Chicken_waste.png", ren);
            egg->set_is_move(true);
            egg->set_angle(0 + 30*i);

            if ((egg->get_angle() > 0 && egg->get_angle() < 90) || (egg->get_angle() > 180 && egg->get_angle() < 270))
                egg->set_index(-egg->get_angle());
            else if ((egg->get_angle() > 90 && egg->get_angle() < 180) || (egg->get_angle() > 270 && egg->get_angle() < 360))
                egg->set_index(180 - egg->get_angle());
            else if (egg->get_angle() == 90 || egg->get_angle() == 270)
                egg->set_index(90 - egg->get_angle());
            else egg->set_index(270 - egg->get_angle());

            egg->set_x_speed(3);
            egg->set_y_speed(3);
            egg->Bullet::SetPosition(rect.x + rect.w/2, rect.y + rect.h/2);
            egg->SetWidthHeight(7, 14);
            egg_list.push_back(egg);
        }
    }

    if (type == 7)
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

    if (type == 7 || type == 8)
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

    if (type == 10){}

    if (type == 11)
    {
        delay_shoot_time = 1500;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->loadIMG("bin/Debug/assets/fried_egg.png", ren);
        egg->set_is_move(true);
        egg->set_angle(random_angle_1());
        egg->set_index(0);
        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 10, rect.y + rect.h + 10);
        egg->SetWidthHeight(20, 20);
        egg_list.push_back(egg);
    }

    if (type == 12)
    {
        delay_shoot_time = 400;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->loadIMG("bin/Debug/assets/Chicken_waste.png", ren);
        egg->set_is_move(true);
        egg->set_angle(angle_bullet);
        RotateBullet();

        if ((angle_bullet > 0 && angle_bullet < 90) || (angle_bullet > 180 && angle_bullet < 270))
            egg->set_index(-angle_bullet);
        else if ((angle_bullet > 90 && angle_bullet < 180) || (angle_bullet > 270 && angle_bullet < 360))
            egg->set_index(180 - angle_bullet);
        else if (angle_bullet == 90 || angle_bullet == 270)
            egg->set_index(90 - angle_bullet);
        else egg->set_index(270 - angle_bullet);

        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2, rect.y + rect.h/2);
        egg->SetWidthHeight(10, 20);
        egg_list.push_back(egg);
    }

    if (type == 13){}

    if (type == 14)
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

    if (type == 15)
    {
        delay_shoot_time = 1000;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->loadIMG("bin/Debug/assets/knife.png", ren);
        egg->set_is_move(true);

        if(spaceship.GetRect().x - xpos - rect.w/2 > 0)
        {
            egg->set_angle(float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2)))*180/M_PI);
        }
        else if(spaceship.GetRect().x - xpos - rect.w/2 < 0)
        {
            egg->set_angle(180 + float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2)))*180/M_PI);
        }
        else if (spaceship.GetRect().x == xpos + rect.w/2)
        {
            if (spaceship.GetRect().y > ypos + rect.h/2)   egg->set_angle(90);
            else egg->set_angle(-90);
        }

        if ((egg->get_angle() > 0 && egg->get_angle() < 90) || (egg->get_angle() > 180 && egg->get_angle() < 270))
            egg->set_index(-egg->get_angle());
        else if ((egg->get_angle() > 90 && egg->get_angle() < 180) || (egg->get_angle() > 270 && egg->get_angle() < 360))
            egg->set_index(180 - egg->get_angle());
        else if (egg->get_angle() == 90 || egg->get_angle() == 270)
            egg->set_index(90 - egg->get_angle());
        else egg->set_index(270 - egg->get_angle());

        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 10, rect.y + rect.h);
        egg->SetWidthHeight(20, 80);
        egg_list.push_back(egg);
    }

    if (type == 16) {}

    if (type == 17 || type == 18)
    {
        delay_shoot_time = 2000;
        Bullet* egg = new Bullet();
        egg->set_type(1);
        egg->loadIMG("bin/Debug/assets/chicken_bullet.png", ren);
        egg->set_is_move(true);

        if(spaceship.GetRect().x - xpos - rect.w/2 + 5 > 0)
        {
            egg->set_angle(float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2 + 5)))*180/M_PI);
        }
        else if(spaceship.GetRect().x - xpos - rect.w/2 + 5 < 0)
        {
            egg->set_angle(180 + float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2 + 5)))*180/M_PI);
        }
        else if (spaceship.GetRect().x == xpos + rect.w/2 - 5)
        {
            if (spaceship.GetRect().y > ypos + rect.h/2)   egg->set_angle(90);
            else egg->set_angle(-90);
        }

        if ((egg->get_angle() > 0 && egg->get_angle() < 90) || (egg->get_angle() > 180 && egg->get_angle() < 270))
            egg->set_index(-egg->get_angle());
        else if ((egg->get_angle() > 90 && egg->get_angle() < 180) || (egg->get_angle() > 270 && egg->get_angle() < 360))
            egg->set_index(180 - egg->get_angle());
        else if (egg->get_angle() == 90 || egg->get_angle() == 270)
            egg->set_index(90 - egg->get_angle());
        else egg->set_index(270 - egg->get_angle());

        egg->set_x_speed(3);
        egg->set_y_speed(3);
        egg->Bullet::SetPosition(rect.x + rect.w/2 - 5, rect.y + rect.h);
        egg->SetWidthHeight(10, 30);
        egg_list.push_back(egg);
    }

    if (type == 20)
    {
        delay_shoot_time = 1000;
        boss_bullet += 1;
        if (mod(boss_bullet, 12) == 1)
        {
            for (int i = 0; i < 12; i++)
            {
                Bullet* egg = new Bullet();
                egg->set_type(1);

                if (i == 1 || i == 2 || i == 7 || i == 8) egg->set_index(0 - 30*i);
                else if (i == 3 || i == 9) egg->set_index(90 - 30*i);
                else if (i == 4 || i == 5 || i == 10 || i == 11) egg->set_index(180 - 30*i);
                else egg->set_index(270 - 30*i);

                egg->loadIMG("bin/Debug/assets/Chicken_waste.png", ren);
                egg->set_is_move(true);
                egg->set_angle(0 + 30*i);
                egg->set_x_speed(7);
                egg->set_y_speed(7);
                egg->Bullet::SetPosition(rect.x + rect.w/2, rect.y + rect.h/2);
                egg->SetWidthHeight(10, 10);
                egg_list.push_back(egg);
            }
        }
        else if (mod(boss_bullet, 12) == 12)
        {
            for (int i = -1; i <= 1; i+=2)
            {
                Bullet* egg = new Bullet();
                egg->set_type(1);
                egg->loadIMG("bin/Debug/assets/knife.png", ren);

                if(spaceship.GetRect().x - xpos - rect.w/2 - 15*i > 0)
                {
                    egg->set_angle(float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2 - 15*i)))*180/M_PI);
                }
                else if(spaceship.GetRect().x - xpos - rect.w/2 - 15*i < 0)
                {
                    egg->set_angle(180 + float(atan((spaceship.GetRect().y - ypos - rect.h/2)/(spaceship.GetRect().x - xpos - rect.w/2 - 15*i)))*180/M_PI);
                }
                else if (spaceship.GetRect().x == xpos + rect.w/2 + 15*i)
                {
                    if (spaceship.GetRect().y > ypos + rect.h/2)   egg->set_angle(90);
                    else egg->set_angle(-90);
                }

                if ((egg->get_angle() > 0 && egg->get_angle() < 90) || (egg->get_angle() > 180 && egg->get_angle() < 270))
                    egg->set_index(-egg->get_angle());
                else if ((egg->get_angle() > 90 && egg->get_angle() < 180) || (egg->get_angle() > 270 && egg->get_angle() < 360))
                    egg->set_index(180 - egg->get_angle());
                else if (egg->get_angle() == 90 || egg->get_angle() == 270)
                    egg->set_index(90 - egg->get_angle());
                else egg->set_index(270 - egg->get_angle());

                egg->set_x_speed(5);
                egg->set_y_speed(5);
                egg->Bullet::SetPosition(rect.x + rect.w/2 + 15*i, rect.y + rect.h/2);
                egg->SetWidthHeight(20, 80);
                egg->set_is_move(true);
                egg_list.push_back(egg);
            }
        }
        else
        {
            Bullet* egg = new Bullet();
            egg->set_type(1);
            egg->loadIMG("bin/Debug/assets/chicken_bullet.png", ren);
            egg->set_is_move(true);
            egg->set_angle(rand()%361);
            egg->set_index(-egg->get_angle());
            egg->set_x_speed(6);
            egg->set_y_speed(6);
            egg->Bullet::SetPosition(rect.x + rect.w/2, rect.y + rect.h/2);
            egg->SetWidthHeight(20, 40);
            egg_list.push_back(egg);
        }
    }

}

