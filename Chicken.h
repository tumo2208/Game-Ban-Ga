#ifndef CHICKEN_H
#define CHICKEN_H

#include "Plane.h"


class Chicken : public Entity
{
    public:
        Chicken();
        ~Chicken();

        void SetPosition(const float& x, const float& y)
        {
            xpos = x;
            ypos = y;
        }
        void set_type(const int& Type) {type = Type;}
        void set_angle(const int& Angle) {angle = Angle;}
        void set_x_limit(const float& x) {x_limit = x;}
        void set_y_limit(const float& y) {y_limit = y;}
        void set_health(const int& health) {hp = health;}
        int get_health() const {return hp;}
        bool die(int& score) {score += chicken_score;   return (hp <= 0);}
        void set_score(const int& Score) {chicken_score = Score;}
        int get_score() const {return chicken_score;}
        void set_delay_shoot_time(const int& time) {delay_shoot_time = time;}
        void ChickenMove();
        bool CanShoot();
        void MakeBullet(vector<Bullet*> &egg_list, SDL_Renderer* ren, Plane &spaceship);


    private:
        float xpos, ypos;
        float x_speed, y_speed;
        float x_limit, y_limit;
        int type;
        int angle;
        int hp;
        int chicken_score;

        int delay_shoot_time;
        unsigned long long CurrentTime;
        unsigned long long LastTime;

};

#endif // CHICKEN_H
