#include "Plane.h"


Plane::Plane()
{

    rect = {0, 0, 0, 0};
    texture = NULL;
    type_spell = 1;

}


Plane::~Plane()
{
    Free();
}


void Plane::loadIMG(const int& plane_number, SDL_Renderer* ren)
{

    string s = "bin/Debug/assets/SpaceShip" + to_string(mod(plane_number, 5)) + ".png";
    SDL_Surface* loadSurface = IMG_Load(s.c_str());
    texture = SDL_CreateTextureFromSurface(ren, loadSurface);
    SDL_FreeSurface(loadSurface);

}


void Plane::ChangeSkin(int& plane_number, SDL_Event& e)
{

    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_d) plane_number += 1;
        if (e.key.keysym.sym == SDLK_a) plane_number -= 1;
    }

}


const Uint8* getkb = SDL_GetKeyboardState(NULL);

void Plane::HandleInputAction(SDL_Event &e, SDL_Renderer* ren, Mix_Chunk* sound)
{

    if (getkb[SDL_SCANCODE_W]) {
        rect.y = max(0, rect.y - PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_S]) {
        rect.y = min(SCREEN_HEIGHT - PLANE_HEIGHT, rect.y + PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_A]) {
        rect.x = max(0, rect.x - PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_D]) {
        rect.x = min(SCREEN_WIDTH - PLANE_WIDTH, rect.x + PLANE_SPEED);
    }

    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_j)
        {
            if (type_spell == 1)
            {
                Bullet* bullet = new Bullet();
                bullet->loadIMG("bin/Release/assets/Bullet_1.png", ren);
                bullet->set_type(1);
                bullet->set_index(0);
                bullet->SetWidthHeight(PlaneBullet_WIDTH, PlaneBullet_HEIGHT);
                bullet->Bullet::SetPosition(rect.x + rect.w/2 - PlaneBullet_WIDTH/2, rect.y - PlaneBullet_HEIGHT/2);
                bullet->set_angle(-90);
                bullet->set_x_speed(PlaneBullet_SPEED);
                bullet->set_y_speed(PlaneBullet_SPEED);
                bullet->set_is_move(true);
                bullet_list.push_back(bullet);
            }

            else if (type_spell == 2)
            {
                for (int i = -1; i <= 1; i+=2)
                {
                    Bullet* bullet = new Bullet();
                    bullet->loadIMG("bin/Release/assets/Bullet_1.png", ren);
                    bullet->set_type(1);
                    bullet->set_index(0);
                    bullet->SetWidthHeight(PlaneBullet_WIDTH, PlaneBullet_HEIGHT);
                    bullet->Bullet::SetPosition(rect.x + rect.w/2 - PlaneBullet_WIDTH/2 + 20*i, rect.y - PlaneBullet_HEIGHT/2);
                    bullet->set_angle(-90);
                    bullet->set_x_speed(PlaneBullet_SPEED);
                    bullet->set_y_speed(PlaneBullet_SPEED);
                    bullet->set_is_move(true);
                    bullet_list.push_back(bullet);
                }
            }

            else if (type_spell == 3)
            {
                for (int i = -1; i < 2; i++)
                {
                    Bullet* bullet = new Bullet();
                    bullet->loadIMG("bin/Release/assets/Bullet_1.png", ren);
                    bullet->set_type(1);
                    bullet->SetWidthHeight(PlaneBullet_WIDTH, PlaneBullet_HEIGHT);
                    bullet->Bullet::SetPosition(rect.x + rect.w/2 - PlaneBullet_WIDTH/2 - 10, rect.y - PlaneBullet_HEIGHT/2);
                    bullet->set_angle(270 + 30*i);
                    if (i == -1)
                        bullet->set_index(-30);
                    if (i == 1)
                        bullet->set_index(30);
                    bullet->set_x_speed(PlaneBullet_SPEED);
                    bullet->set_y_speed(PlaneBullet_SPEED);
                    bullet->set_is_move(true);
                    bullet_list.push_back(bullet);
                }
            }

            Mix_PlayChannel(-1, sound, 0);
        }
    }

}


void Plane::MakeBullet(SDL_Renderer* ren)
{

    for(int i = 0; i < int(bullet_list.size()); i++)
    {
        Bullet* bullet = bullet_list.at(i);

        if(bullet->get_is_move())
        {
            bullet->BulletMove(SCREEN_WIDTH,SCREEN_HEIGHT);
            bullet->Display(ren, bullet->get_index());
        }
        else
        {
            bullet_list.erase(bullet_list.begin()+i);
            if(bullet!=NULL)
            {
                delete bullet;
                bullet = NULL;
            }
        }
    }

}


void Plane::RemoveBullet(const int& i)
{

    int n = bullet_list.size();
    if(n > 0 && i < n)
    {
        Bullet* bullet = bullet_list.at(i);
        bullet_list.erase(bullet_list.begin() + i);
        if(bullet != NULL)
        {
            delete bullet;
            bullet = NULL;
        }
    }

}


void Plane::ResetBulletPlane()
{

    bullet_list.erase(bullet_list.begin(), bullet_list.end());
    type_spell = 1;

}
