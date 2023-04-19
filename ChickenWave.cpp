#include "ChickenWave.h"


void Chicken_Wave_1(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave1_small_hang13; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_small.png", ren);
        chicken->set_type(1);
        chicken->set_health(1);
        chicken->set_score(30);
        chicken->Chicken::SetPosition(1500 + i*(CHICKEN_SMALL_WIDTH + 100), 50);
        chicken->SetWidthHeight(CHICKEN_SMALL_WIDTH, CHICKEN_SMALL_HEIGHT);
        chicken->set_x_limit(395 + i*(CHICKEN_SMALL_WIDTH + 100));
        chicken->set_y_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave1_small_hang13; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_small.png", ren);
        chicken->set_type(2);
        chicken->set_health(1);
        chicken->set_score(30);
        chicken->Chicken::SetPosition(1500 + i*(CHICKEN_SMALL_WIDTH + 100), 357);
        chicken->SetWidthHeight(CHICKEN_SMALL_WIDTH, CHICKEN_SMALL_HEIGHT);
        chicken->set_x_limit(395 + i*(CHICKEN_SMALL_WIDTH + 100));
        chicken->set_y_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave1_small_hang2; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_small.png", ren);
        chicken->set_type(3);
        chicken->set_health(1);
        chicken->set_score(30);
        chicken->Chicken::SetPosition(-700 + 2*i*(CHICKEN_SMALL_WIDTH + 100), 203.5);
        chicken->SetWidthHeight(CHICKEN_SMALL_WIDTH, CHICKEN_SMALL_HEIGHT);
        chicken->set_x_limit(395 + 2*i*(CHICKEN_SMALL_WIDTH + 100));
        chicken->set_y_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave1_big; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(4);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(395 + (2*i + 1)*(CHICKEN_SMALL_WIDTH + 100) - 13, -900);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_x_limit(0);
        chicken->set_y_limit(195);

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_2(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave2; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(5);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(80 + i*(CHICKEN_WIDTH + 96), -CHICKEN_HEIGHT - 100);
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
        chicken->set_type(6);
        chicken->set_health(1);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(200, -250 + (CHICKEN_HEIGHT + 50)*(i+1));
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(50 + i*(CHICKEN_HEIGHT + 50));
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave3; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_do.png", ren);
        chicken->set_type(6);
        chicken->set_health(1);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(SCREEN_WIDTH - 200 - CHICKEN_WIDTH, -250 + (CHICKEN_HEIGHT + 50)*(i+1));
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
        chicken->set_type(7);
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
        chicken->set_type(7);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(-250 + i*(80 + CHICKEN_WIDTH), 100);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(200 + i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(8);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(1700 - i*(80 + CHICKEN_WIDTH), 200);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(SCREEN_WIDTH - 200 - CHICKEN_WIDTH - i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(7);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(-250 + i*(80 + CHICKEN_WIDTH), 400);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(SCREEN_WIDTH - 200 - CHICKEN_WIDTH*2 - 80 + i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave4; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(8);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(1700 - i*(80 + CHICKEN_WIDTH), 300);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(0);
        chicken->set_x_limit(200 + CHICKEN_WIDTH + 80 - i*(CHICKEN_WIDTH + 80));

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_5(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    Chicken* chicken = new Chicken();
    chicken->loadIMG("bin/Debug/assets/Egg_spell.png", ren);
    chicken->set_type(10);
    chicken->set_health(50);
    chicken->set_score(200);
    chicken->Chicken::SetPosition((SCREEN_WIDTH - 180)/2, -300);
    chicken->SetWidthHeight(180, 240);
    chicken->set_y_limit(150);
    chicken->set_x_limit(0);

    chicken_list.push_back(chicken);

}


void Chicken_Wave_6(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave6_big; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_UFO.png", ren);
        chicken->set_type(12);
        chicken->set_angle_rotate_speed(10);
        chicken->set_chieu(i);
        chicken->set_health(5);
        chicken->set_score(150);
        chicken->Chicken::SetPosition (400 + i*490, -250);
        chicken->SetWidthHeight(150, 90);
        chicken->set_x_limit(0);
        chicken->set_y_limit(150);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave6_small; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanhla.png", ren);
        chicken->set_type(11);
        chicken->set_health(2);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(200, -250 + (CHICKEN_HEIGHT + 50)*(i+1));
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(50 + i*(CHICKEN_HEIGHT + 50));
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave6_small; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanhla.png", ren);
        chicken->set_type(11);
        chicken->set_health(2);
        chicken->set_score(70);
        chicken->Chicken::SetPosition(SCREEN_WIDTH - 200 - CHICKEN_WIDTH, -250 + (CHICKEN_HEIGHT + 50)*(i+1));
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(50 + i*(CHICKEN_HEIGHT + 50));
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }
}


void Chicken_Wave_7(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave7; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Meteorite.png", ren);
        chicken->set_type(13);
        chicken->set_health(3);
        chicken->set_score(100);
        chicken->Chicken::SetPosition (GetRandom_wave7(), (-METEORITE_HEIGHT - i*(METEORITE_HEIGHT + 150)));
        chicken->SetWidthHeight(METEORITE_WIDTH, METEORITE_HEIGHT);
        chicken->set_x_limit(0);
        chicken->set_y_limit(0);

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_8(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave8_shield; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_shield.png", ren);
        chicken->set_type(16);
        chicken->set_health(3);
        chicken->set_score(0);
        chicken->Chicken::SetPosition(70 + i*230, -200);
        chicken->SetWidthHeight(150, 100);
        chicken->set_y_limit(400);
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave8_small; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_xanh.png", ren);
        chicken->set_type(14);
        chicken->set_health(1);
        chicken->set_score(50);
        chicken->Chicken::SetPosition(80 + i*(CHICKEN_WIDTH + 96), -300);
        chicken->SetWidthHeight(CHICKEN_WIDTH, CHICKEN_HEIGHT);
        chicken->set_y_limit(300);
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave8_big; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_ninja.png", ren);
        chicken->set_type(15);
        chicken->set_health(5);
        chicken->set_score(150);
        chicken->Chicken::SetPosition(SCREEN_WIDTH/2 - 75, -600);
        chicken->SetWidthHeight(150, 150);
        chicken->set_y_limit(100);
        chicken->set_x_limit(0);

        chicken_list.push_back(chicken);
    }

}


void Chicken_Wave_9(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    for (int i = 0; i < Number_of_chickenwave9; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_alien.png", ren);
        chicken->set_type(17);
        chicken->set_health(3);
        chicken->set_score(100);
        chicken->Chicken::SetPosition(-800 + 170*i, 100);
        chicken->SetWidthHeight(70, 70);
        chicken->set_y_limit(0);
        chicken->set_x_limit(345 + i*170);

        chicken_list.push_back(chicken);
    }

    for (int i = 0; i < Number_of_chickenwave9; i++)
    {
        Chicken* chicken = new Chicken();
        chicken->loadIMG("bin/Debug/assets/Chicken_alien.png", ren);
        chicken->set_type(18);
        chicken->set_health(3);
        chicken->set_score(100);
        chicken->Chicken::SetPosition(1490 + 170*i, 270);
        chicken->SetWidthHeight(70, 70);
        chicken->set_y_limit(0);
        chicken->set_x_limit(345 + i*170);

        chicken_list.push_back(chicken);
    }

}


void Chicken_Boss(vector<Chicken*> &chicken_list, SDL_Renderer* ren)
{

    Chicken* chicken = new Chicken();
    chicken->loadIMG("bin/Debug/assets/Big_Chicken.png", ren);
    chicken->set_type(20);
    chicken->set_x_speed(5);
    chicken->set_y_speed(5);
    chicken->set_health(50);
    chicken->set_score(1000);
    chicken->Chicken::SetPosition((SCREEN_WIDTH - 250)/2, -350);
    chicken->SetWidthHeight(250, 225);
    chicken->set_y_limit(100);
    chicken->set_x_limit(0);

    chicken_list.push_back(chicken);

}


void SwapWave(vector<Chicken*> &chicken_list, SDL_Renderer* ren, int& wave, bool& victory)
{

    if (chicken_list.size() <= 0)
    {
        if (wave < 10)
        {
            wave += 1;
            if (mod(wave, 10) == 1)
            {
                Chicken_Wave_1(chicken_list, ren);
            }
            if (mod(wave, 10) == 2)
            {
                Chicken_Wave_2(chicken_list, ren);
            }
            if (mod(wave, 10) == 3)
            {
                Chicken_Wave_3(chicken_list, ren);
            }
            if (mod(wave, 10) == 4)
            {
                Chicken_Wave_4(chicken_list, ren);
            }
            if (mod(wave, 10) == 5)
            {
                Chicken_Wave_5(chicken_list, ren);
            }
            if (mod(wave, 10) == 6)
            {
                Chicken_Wave_6(chicken_list, ren);
            }
            if (mod(wave, 10) == 7)
            {
                Chicken_Wave_7(chicken_list, ren);
            }
            if (mod(wave, 10) == 8)
            {
                Chicken_Wave_8(chicken_list, ren);
            }
            if (mod(wave, 10) == 9)
            {
                Chicken_Wave_9(chicken_list, ren);
            }
            if (mod(wave, 10) == 10)
            {
                Chicken_Boss(chicken_list, ren);
            }

        }
        else
            victory = true;
    }

}
