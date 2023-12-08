#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include "Pieces.hpp"
#include "logic.hpp"


class Board{
    public :
    SDL_Renderer* gRenderer;
    //global reference to png image sheets

    SDL_Texture* assets;

    void initialize(); 

    void display(SDL_Rect& srcRect, SDL_Rect& movRect);
};
