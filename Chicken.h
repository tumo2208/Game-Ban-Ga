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
        int get_type()  const {return type;}
        void set_angle(const int& Angle) {angle = Angle;}
        void set_x_limit(const float& x) {x_limit = x;}
        void set_y_limit(const float& y) {y_limit = y;}
        void set_x_speed(const float& x) {x_speed = x;}
        void set_y_speed(const float& y) {y_speed = y;}
        void set_health(const int& health) {hp = health;}
        int get_health() const {return hp;}
        bool die() {return (hp <= 0);}
        void set_score(const int& Score) {chicken_score = Score;}
        int get_score() const {return chicken_score;}
        bool get_time_wave_5_out()  const {return time_wave_5_out;}
        void RotateBullet ();
        void set_angle_rotate_speed (const int& speed) {angle_rotate_speed = speed;}
        void set_chieu(const bool& Chieu) {chieu = Chieu;}
        void set_delay_shoot_time(const int& time) {delay_shoot_time = time;}
        void ChickenMove();
        bool CanShoot(bool pause, SDL_Event& e);
        void MakeBullet(vector<Bullet*> &egg_list, SDL_Renderer* ren, Plane &spaceship);


    private:
        float xpos, ypos;
        float x_speed, y_speed;
        float x_limit, y_limit;
        int type;
        int angle;
        int hp;
        int chicken_score;

        unsigned long long time_wave5_out;
        bool time_wave_5_out;
        bool set_lasttime;

        bool chieu;
        int angle_bullet;
        int angle_rotate_speed;

        int delay_shoot_time;
        unsigned long long CurrentTime;
        unsigned long long LastTime;
        unsigned long long TimePause;
        unsigned long long TimeEndPause;

        int boss_bullet;

};

#endif // CHICKEN_H
