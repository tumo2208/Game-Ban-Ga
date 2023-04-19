#ifndef PLANE_H
#define PLANE_H

#include "Bullet.h"


class Plane : public Entity
{
    public:
        Plane();
        ~Plane();

        void set_type_spell(const int& type)   {type_spell = type;}
        int get_type_spell()    const {return type_spell;}
        void loadIMG(const int& plane_number, SDL_Renderer* ren);
        void ChangeSkin(int& plane_number, SDL_Event& e);
        void HandleInputAction(SDL_Event &e, SDL_Renderer* ren, Mix_Chunk* sound);
        vector<Bullet*> GetBulletList() const {return bullet_list;}
        void MakeBullet(SDL_Renderer* ren);
        void RemoveBullet(const int& i);
        void ResetBulletPlane();


    private:
        vector<Bullet*> bullet_list;
        int type_spell;

};

#endif // PLANE_H
