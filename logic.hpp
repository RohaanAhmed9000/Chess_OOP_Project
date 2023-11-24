#pragma once
#include <SDL.h>
#include <iostream>
#include "pieces.hpp"
#include "game.hpp"
using namespace std;
/*
we are using namespace std
first letter of classes capital
*/

class Pawn: public Pieces // 99% inheritence public
{
};

class Bishop: public Pieces // 99% inheritence public
{
};
class Knight: public Pieces // 99% inheritence public
{
};
class Rook: public Pieces // 99% inheritence public
{

};
class King: public Pieces // 99% inheritence public
{

};
class Queen: public Pieces // 99% inheritence public
{

};

class Interaction
{
};

class Movement // 99% inheritence public
{
};

class Board
{
};


// making GRID
// void initial()
// {
//     for (int i=0;i<rows ; i++)
//     {
//         for(int j=0;j<cols ; j++)
//         {
//             grid[i][j]='L';
//         }
//     }
// }   

// switch(sym){
//     // BLACK IS CAPITAL YANI UPPER CASE !
//         case 'P': src = {219, 12, 38, 49}; break; // pawn
//         case 'B': src = {7, 8, 54, 53}; break;  // bishop
//         case 'K': src = {75, 7, 54, 54}; break;
//         case 'Q': src = {276, 7, 60, 56}; break; // 54
//         case 'R': src = {352, 12, 44, 49}; break;
//         case 'N': src = {143, 9, 52, 52}; break; // knight
//         // white
//         case 'p': src = {627, 12, 38, 49}; break;
//         case 'b': src = {415, 8, 54, 53}; break;
//         case 'k': src = {483, 7, 54, 54}; break;
//         case 'q': src = {684, 7, 60, 54}; break;
//         case 'r': src = {760, 12, 44, 49}; break;
//         case 'n': src = {551, 9, 52, 52}; break;
//     }
// void drawPieces(SDL_Renderer* gRenderer, SDL_Texture* assets ) // assests is texture
// {
    
// }
// void drawOneBlock(SDL_Renderer* renderer, SDL_Texture* texture, int row, int col, char sym)
// {
//     int xbox = 800/cols;
//     int ybox = 800/rows;
//     SDL_Rect src;
//     switch(sym){
//     // BLACK IS CAPITAL YANI UPPER CASE !
//         case 'P': src = {219, 12, 38, 49}; break; // pawn
//         case 'B': src = {7, 8, 54, 53}; break;  // bishop
//         case 'K': src = {75, 7, 54, 54}; break;
//         case 'Q': src = {276, 7, 60, 56}; break; // 54
//         case 'R': src = {352, 12, 44, 49}; break;
//         case 'N': src = {143, 9, 52, 52}; break; // knight
//         // white
//         case 'p': src = {627, 12, 38, 49}; break;
//         case 'b': src = {415, 8, 54, 53}; break;
//         case 'k': src = {483, 7, 54, 54}; break;
//         case 'q': src = {684, 7, 60, 54}; break;
//         case 'r': src = {760, 12, 44, 49}; break;
//         case 'n': src = {551, 9, 52, 52}; break;
//     }
//     SDL_Rect mov = { xbox*col, ybox*row, xbox - 10, ybox - 10};
//     SDL_RenderCopy(renderer, texture, &src, &mov);

// }

// void drawBlocks(SDL_Renderer* renderer, SDL_Texture* texture){
//     // Call drawOneBlock for all of the blocks of grid
//     // for example to draw a snake over block (3, 5) you call it this way:
//     // drawOneBlock(renderer, texture, 3, 5, 'S');
//     if(grid == NULL) return;
//     for(int i=0;i<rows; i++){
//         for(int j=0;j<cols; j++){
//             drawOneBlock(renderer, texture, i, j, grid[i][j]);
//         }   
//     }
// }

