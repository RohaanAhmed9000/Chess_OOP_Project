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
public:
    Allpieces piece_type;
    SDL_Rect srcRect, movRect;

    bool virtual move_possible(int file, int rank, int prev_file, int prev_rank);

    void virtual move(int file, int rank);

    bool virtual taking(int file, int rank, int prev_file, int prev_rank);

    bool is_white();
protected:
    int off_centre_x, off_centre_y;

    // void move(int x, int y);
    // void select(int x, int y);    
};

