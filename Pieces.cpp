#include "Pieces.hpp"

void Pieces::move(int rank, int file){
    movRect.x = file*91 + 35;
    movRect.y = rank*91 + 35;
}
// void Pieces::move(int x, int y){

// }


// void Pieces::select(int x, int y){

    
// }