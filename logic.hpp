#pragma once
#include <SDL.h>
#include <iostream>
#include "Pieces.hpp"

using namespace std;
/*
we are using namespace std
first letter of classes capital
*/

class Pawn: public Pieces 
{
protected:
    bool first_move=true;
public:
    Pawn(Allpieces type, SDL_Rect mover);
    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
    bool taking(int file, int rank, int prev_file, int prev_rank) override;
};

class Bishop: public Pieces 
{
    public:
    Bishop(Allpieces type, SDL_Rect mover);

    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
};


class Knight: public Pieces // 99% inheritence public
{
    public:
    Knight(Allpieces type, SDL_Rect mover);

    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
};

class Rook: public Pieces // 99% inheritence public
{
    public: 
    Rook(Allpieces type, SDL_Rect mover);
    bool first_move=true;

    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
    
};

class King: public Pieces 
{
    public:
    King(Allpieces type, SDL_Rect mover);
    bool first_move=true;

    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
};

class Queen: public Pieces // 99% inheritence public
{
    public:
    Queen(Allpieces type, SDL_Rect mover);

    void move(int rank, int file) override;
    bool move_possible(int rank, int file, int prev_file, int prev_rank) override;
};