#pragma once
#include "logic.hpp"

bool Pawn::move(int file, int rank, int prev_file, int prev_rank){
    // std::cout<<"previous position: "<<prev_rank<<", "<<prev_file<<endl;
    // std::cout<<"new position: "<<rank<<", "<<file<<endl;

    bool moved=false;    

    int rank_diff = abs(prev_rank-rank);
    std::cout<<rank_diff;

    if(rank_diff==1 or (rank_diff==2 and first_move)){ //and file==prev_file){
        Pieces::move(file, rank, prev_file, prev_rank);
        movRect.x+=off_centre_x;
        movRect.y+=off_centre_y;
        moved=true;
        first_move=false;
    }
    return moved;
    
}

Pawn :: Pawn(Allpieces type, SDL_Rect mover) {

    movRect = mover;
    piece_type=type;
    off_centre_x = 24;
    off_centre_y = 27;

    if (type==black_pawn){
        srcRect= {219,12,38,49};
    }
    else if (type==white_pawn){
        srcRect = {627, 12, 38, 49};
    }
}


bool Bishop::move(int rank, int file, int prev_file, int prev_rank){
    //std::cout<<rank<<file<<"hre";
    movRect.x = (rank*91+35)+21;
    movRect.y = (file*91+35)+19;
    return true;
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


bool Rook::move(int rank, int file, int prev_file, int prev_rank){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+25;
    movRect.y = (file*91+35)+24;
    return true;
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


bool King::move(int rank, int file, int prev_file, int prev_rank){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+21;
    movRect.y = (file*91+35)+15;
    return true;

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


bool Queen::move(int rank, int file, int prev_file, int prev_rank){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+15;
    movRect.y = (file*91+35)+18;
    return true;
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


bool Knight::move(int rank, int file, int prev_file, int prev_rank){
    //std::cout<<rank<<file<<"hre";

    movRect.x = (rank*91+35)+19;
    movRect.y = (file*91+35)+21;
    return true;
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