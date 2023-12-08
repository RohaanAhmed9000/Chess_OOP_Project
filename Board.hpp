#pragma once
#include<SDL.h>
#include <vector>
#include <SDL_image.h>
#include "Pieces.hpp"
#include "logic.hpp"

struct position{
    int x, y;
    bool occupy=false;
};

class Board{
    position blocks[8][8];

    public :
    vector <Pieces> myPieces;
    SDL_Renderer* gRenderer;
    //global reference to png image sheets

    int a1_x, a1_y = 35;

    SDL_Texture* assets;

    void initialize(); 

    void setCoordinates();

    void draw();

    void display(SDL_Rect& srcRect, SDL_Rect& movRect);

    bool move(int x, int y, int I, int J, int K);

    bool select(int x, int y);

};


