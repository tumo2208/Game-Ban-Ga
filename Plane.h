#ifndef PLANE_H
#define PLANE_H

#include "Bullet.h"


class Plane : public Entity
{
    public:
        Plane();
        ~Plane();

        void loadIMG(const int& plane_number, SDL_Renderer* ren);
        void ChangeSkin(int& plane_number, SDL_Event& e);
        void HandleInputAction(SDL_Event &e, SDL_Renderer* ren, Mix_Chunk* sound);
        vector<Bullet*> GetBulletList() const {return bullet_list;}
        void MakeBullet(SDL_Renderer* ren);
        void RemoveBullet(const int& i);
        void ResetBulletPlane();


    private:
        vector<Bullet*> bullet_list;

};

#endif // PLANE_H
