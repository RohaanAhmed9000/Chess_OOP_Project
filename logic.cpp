#pragma once
#include "logic.hpp"

void Pawn::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+27;
    movRect.y = (file*91+35)+24;
}

Pawn :: Pawn(Allpieces type, SDL_Rect mover) {

    movRect = mover;
    piece_type=type;

    if (type==black_pawn){
        srcRect= {219,12,38,49};
    }
    else if (type==white_pawn){
        srcRect = {627, 12, 38, 49};
    }
}


void Bishop::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+21;
    movRect.y = (file*91+35)+19;
}

Bishop:: Bishop(Allpieces type, SDL_Rect mover) {
    movRect = mover; 
    piece_type=type;
    if (piece_type==black_bishop){
        srcRect={7,8,54,53};
    }
    else if (piece_type==white_bishop){
        srcRect = {415, 8, 54, 53};
    }
}


void Rook::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+25;
    movRect.y = (file*91+35)+24;
}

Rook :: Rook(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type=type;

    if (piece_type==black_rook){
        srcRect={352,12,44,49};
    }
    else if (piece_type==white_rook){
        srcRect = {760, 12, 44, 49};
    }
}


void King::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+21;
    movRect.y = (file*91+35)+15;
}


King :: King(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type=type;
    if (piece_type==black_king){
        srcRect={75,7,54,54};
    }
    else if (piece_type=white_king){
        srcRect = {483, 7, 54, 54};
    }
}


void Queen::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+15;
    movRect.y = (file*91+35)+18;
}

Queen :: Queen(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type = type;
    if (piece_type==black_queen){
        srcRect= {276,7,60,54};
    }
    else if (piece_type==white_queen){
        srcRect = {684, 7, 60, 54};
    }
}


void Knight::move(int rank, int file){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+19;
    movRect.y = (file*91+35)+21;
}

Knight :: Knight(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type = type;
    if (piece_type==black_knight){
        srcRect= {143,9,52,52}; 
    }
    else if (piece_type==white_knight){
        srcRect = {551, 9, 52, 52};
    }
    
    
}