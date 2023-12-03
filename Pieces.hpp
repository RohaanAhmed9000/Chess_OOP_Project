#pragma once
#include <SDL.h>
#include <SDL_image.h>


enum Allpieces {
    black_rook,
    black_bishop,
    black_king,
    black_queen,
    black_pawn,
    black_knight,
    white_rook,
    white_bishop,
    white_king,
    white_queen,
    white_pawn,
    white_knight
};

class Pieces 
{
protected:
    Allpieces piece_type;

public:
    SDL_Rect srcRect, movRect;

private:
    // void move(int x, int y);
    // void select(int x, int y);    
};

