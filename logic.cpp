#pragma once
#include "pieces.hpp"
#include "logic.hpp"
Pawn :: Pawn(Allpieces type, SDL_Rect mover) {

    movRect = mover;
    piece_type=type;
    if (piece_type=black_rook){
        srcRect= {219,12,38,49};
    }
    else if (piece_type=white_king){
        srcRect = {627, 12, 38, 49};
    }
}

Bishop:: Bishop(Allpieces type) {
    
    piece_type=type;
    if (piece_type=black_rook){
        srcRect={7,8,54,53};
    }
    else if (piece_type=white_king){
        srcRect = {415, 8, 54, 53};
    }
}

Rook :: Rook(Allpieces type) {
    piece_type=type;
    if (piece_type=black_rook){
        srcRect={352,12,44,49};
    }
    else if (piece_type=white_king){
        srcRect = {760, 12, 44, 49};
    }
}


King :: King(Allpieces type) {
    
    piece_type=type;
    if (piece_type=black_king){
        srcRect={75,7,54,54};
    }
    else if (piece_type=white_king){
        srcRect = {483, 7, 54, 54};
    }
}
Queen :: Queen(Allpieces type) {
    
    piece_type = type;
    if (piece_type=black_queen){
        srcRect= {276,7,60,56};
    }
    else if (piece_type=white_queen){
        srcRect = {684, 7, 50, 54};
    }
}
Knight :: Knight(Allpieces type) {
    
    piece_type = type;
    if (piece_type=black_knight){
        srcRect= {143,9,52,52}; 
    }
    else if (piece_type=white_knight){
        srcRect = {551, 9, 52, 52};
    }
    
    
}