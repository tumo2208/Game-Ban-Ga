#include "Entity.h"


Entity::Entity()
{

    texture = NULL;
    rect = {0, 0, 0, 0};
    text = "";
    color = {255, 166, 77};

}


Entity::~Entity()
{
    Free();
}


void Entity::loadIMG(const string& path, SDL_Renderer* ren)
{

    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(ren, loadSurface);

    SDL_FreeSurface(loadSurface);

}


void Entity::MoveBackground(SDL_Renderer* ren)
{

    rect.y += SCREEN_SPEED;
    if (rect.y >= SCREEN_HEIGHT)
        rect.y = 0;

    SDL_Rect a = {rect.x, rect.y, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect b = {rect.x, rect.y - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_RenderCopy(ren, texture, NULL, &a);
    SDL_RenderCopy(ren, texture, NULL, &b);

}


void Entity::Display(SDL_Renderer* ren, int index)
{

    //SDL_RenderCopy(ren, texture, NULL, &rect);

    SDL_RenderCopyEx(ren, texture, NULL, &rect, index, NULL, SDL_FLIP_NONE);

}


void Entity::Free()
{

    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

}


bool Entity::Click()
{
    bool click;

    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h)
        click = false;
    else click = true;

	return click;

}


void Entity::loadText(TTF_Font* font, SDL_Renderer* ren)
{

    SDL_Surface* loadSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(ren, loadSurface);

    SDL_FreeSurface(loadSurface);

}

