#include "Pieces.hpp"

void Pieces::move(int file, int rank, int prev_file, int prev_rank){
    movRect.x = (rank*91+35);
    movRect.y = (file*91+35);
}

// void Pieces::move(int x, int y){

// }


// void Pieces::select(int x, int y){

    
// }