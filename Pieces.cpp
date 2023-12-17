#include "Pieces.hpp"
#include <iostream>

void Pieces::move(int file, int rank){
    movRect.x = (file*91+35)+off_centre_x;
    movRect.y = (rank*91+35)+off_centre_y;
}
bool Pieces::move_possible(int file, int rank, int prev_file, int prev_rank){
    return false;
}

bool Pieces::taking(int file, int rank, int prev_file, int prev_rank){
    std::cout<<"takes takes takes, takes takes \n";
    return false;
}

bool Pieces::is_white(){
    if(piece_type>5){
        return true;
    }
    else{
        return false;
    }
}
// void Pieces::move(int x, int y){

// }


// void Pieces::select(int x, int y){

    
// }