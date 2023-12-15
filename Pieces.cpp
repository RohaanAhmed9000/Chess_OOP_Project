#include "Pieces.hpp"

bool Pieces::move(int file, int rank, int prev_file, int prev_rank){
    movRect.x = (file*91+35);
    movRect.y = (rank*91+35);
    return true;
}

// void Pieces::move(int x, int y){

// }


// void Pieces::select(int x, int y){

    
// }