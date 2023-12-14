#pragma once
#include<SDL.h>
#include <vector>
#include <SDL_image.h>
#include "Pieces.hpp"
#include "logic.hpp"

struct position{
    int x, y;
    //bool occupy=false;
    Pieces* piece = nullptr;
};


class Board{
    public :
    position blocks[8][8];

    vector <Pieces> myPieces;
    SDL_Renderer* gRenderer;
    //global reference to png image sheets

    int a1_x, a1_y = 35;

    SDL_Texture* assets;

    void initialize(); 

    void setCoordinates();

    void draw();

    void display(SDL_Rect& srcRect, SDL_Rect& movRect);

    void move(int x, int y, int srank, int file);

    int select(int x, int y);

};


