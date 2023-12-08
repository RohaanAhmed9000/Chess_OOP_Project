// DO NOT CHANGE THIS FILE
#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Pieces.hpp"
#include "logic.hpp"
#include "Board.hpp"


class Game
{
    // Screen dimension constants
     int SCREEN_WIDTH = 800;
     int SCREEN_HEIGHT = 800;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;
    

    // The window renderer
    SDL_Renderer *gRenderer = NULL;

    // Current displayed texture
    SDL_Texture *gTexture = NULL;
    // global reference to png image sheets
    SDL_Texture *assets = NULL;

    SDL_Rect srcRect, movRect;

    SDL_Window *sWindow = NULL;

    SDL_Renderer *sRenderer = NULL;

    // Current displayed texture
    SDL_Texture *sTexture = NULL;

public:
    Board myBoard;

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};

// class DraWpieces
// {
//     public:
//     SDL_Rect srcRect, moverRect;

// };