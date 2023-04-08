#ifndef ENTITY_H
#define ENTITY_H

#include "ConstVal.h"


class Entity
{
    public:
        Entity();
        ~Entity();

        void loadIMG(const string& path, SDL_Renderer* ren);
        void MoveBackground(SDL_Renderer* ren);
        void Display(SDL_Renderer* ren, int index = 0);
        void Free();
        bool Click();
        SDL_Rect GetRect() const {return rect;}
        void SetPosition(const int& x, const int& y) {rect.x = x; rect.y = y;}
        void SetWidthHeight(const int& w, const int& h) {rect.w = w; rect.h = h;}

        void set_text(const string& Text) {text = Text;}
        void set_color(Uint8 r, Uint8 b, Uint8 g) {color = {r, b, g};}
        void loadText(TTF_Font* font, SDL_Renderer* ren);


    protected:
        SDL_Texture* texture;
        SDL_Rect rect;
        string text;
        SDL_Color color;

};

#endif // ENTITY_H
