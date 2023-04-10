#include "ChickenWave.h"


void Chicken_Wave_1(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{



}


void Chicken_Wave_2(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave2; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(2);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(80 + i*(CHICKEN_WIDTH + 96), -CHICKEN_HEIGHT);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(100);
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_3(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave3; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_do.png", ren);
        chicken->set_type(3);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(200, -CHICKEN_HEIGHT*(i+1) - 50);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(50 + i*(CHICKEN_HEIGHT + 50));
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave3; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_do.png", ren);
        chicken->set_type(3);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(SCREEN_WIDTH - 200, -CHICKEN_HEIGHT*(i+1) - 50);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(50 + i*(CHICKEN_HEIGHT + 50));
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

}


/*void Chicken_Wave_4(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(4);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->Chicken::SetPosition(SCREEN_WIDTH + i*(CHICKEN_WIDTH + 50), 100);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(500);
        chicken->set_x_limit(60);

        chicken_list.push_back(chicken);
    }

}*/


void Chicken_Wave_4(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(4);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(-CHICKEN_WIDTH - i*(CHICKEN_WIDTH + 80), 100);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(200 + i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(5);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(SCREEN_WIDTH + CHICKEN_WIDTH + i*(CHICKEN_WIDTH + 80), 200);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(SCREEN_WIDTH - 200 - CHICKEN_WIDTH - i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(4);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(-CHICKEN_WIDTH - i*(CHICKEN_WIDTH + 80), 400);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(SCREEN_WIDTH - 200 - CHICKEN_WIDTH*2 - 80 + i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(5);
        chicken->set_angle(90);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(SCREEN_WIDTH + CHICKEN_WIDTH + i*(CHICKEN_WIDTH + 80), 300);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(200 + CHICKEN_WIDTH + 80 - i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_5(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{



}


void Chicken_Wave_6(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave6; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Meteorite.png", ren);
        chicken->set_type(11);
        chicken->set_angle(90);
        chicken->set_health(3);
        chicken->Chicken::SetPosition (0 + i*(METEORITE_WIDTH + 25), (-METEORITE_HEIGHT - i*(METEORITE_HEIGHT + 150)));
        chicken->SetWidthHeight(METEORITE_WIDTH, METEORITE_HEIGHT);
        chicken->set_x_limit(0);
        chicken->set_y_limit(0);

        chicken_list.push_back(chicken);
    }

}


void SwapWave(vector<Chicken*> &chicken_list, SDL_Renderer* ren, int& wave, bool& victory)
{

    if (chicken_list.size() <= 0)
    {
        if (wave <= 2)
        {
            wave += 1;
            if (mod(wave, 3) == 1)
            {
                Chicken_Wave_2(chicken_list, ren);
            }
            if (mod(wave, 3) == 2)
            {
                Chicken_Wave_3(chicken_list, ren);
            }
            if (mod(wave, 3) == 3)
            {
                Chicken_Wave_4(chicken_list, ren);
            }
        }
        else
            victory = true;
    }

}
