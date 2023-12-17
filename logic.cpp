#pragma once
#include "logic.hpp"

bool Pawn::move_possible(int file, int rank, int prev_file, int prev_rank){
    bool moved=false;    

    int rank_diff = (prev_rank-rank);
    int file_diff = abs(prev_file-file);

    if (piece_type==black_pawn){
        if((rank_diff==-1 or (rank_diff==-2 and first_move)) and file_diff==0){ //and file==prev_file){
            // Pieces::move(file, rank, prev_file, prev_rank);
            moved=true;
            first_move=false;
        }
    }
    else if (piece_type==white_pawn){
        if((rank_diff==1 or (rank_diff==2 and first_move)) and file_diff==0){ //and file==prev_file){
            // Pieces::move(file, rank, prev_file, prev_rank);
            moved=true;
            first_move=false;
        }
    }
    return moved;   
}

void Pawn::move(int file, int rank){
    Pieces::move(file, rank);
}

bool Pawn::taking(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = prev_rank-rank;
    int file_diff = abs(prev_file-file);
    bool taken = false;
    if (piece_type==black_pawn){
        if((rank_diff==-1 /* or(rank_diff==-2 and first_move)*/) and file_diff==1){ //and file==prev_file){
            Pieces::move(file, rank);
            taken=true;
            first_move=false;
        }
    }
    else if (piece_type==white_pawn){
        if((rank_diff==1 /*or (rank_diff==2 and first_move)*/) and file_diff==1){ //and file==prev_file){
            Pieces::move(file, rank);
            taken=true;
            first_move=false;
        }
    }
    return taken;

}



Pawn :: Pawn(Allpieces type, SDL_Rect mover) {

    movRect = mover;
    piece_type=type;
    off_centre_x = 24;
    off_centre_y = 27;

    if (piece_type==black_pawn){
        srcRect= {219,12,38,49};
    }
    else if (piece_type==white_pawn){
        srcRect = {627, 12, 38, 49};
    }
}



bool Bishop::move_possible(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = abs(prev_rank-rank);
    int file_diff = abs(prev_file-file);
    bool moved = false;
    if (rank_diff==file_diff){
        moved = true;
    }
    return moved;
}

void Bishop::move(int file, int rank){
    Pieces::move(file, rank);
}

Bishop:: Bishop(Allpieces type, SDL_Rect mover) {
    movRect = mover; 
    piece_type=type;
    off_centre_x = 21;
    off_centre_y = 19;

    if (piece_type==black_bishop){
        srcRect={7,8,54,53};
    }
    else if (piece_type==white_bishop){
        srcRect = {415, 8, 54, 53};
    }
}



bool Rook::move_possible(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = abs(prev_rank-rank);
    int file_diff = abs(prev_file-file);
    bool moved = false ;
    if (rank_diff==0 or file_diff==0){
        moved = true;
    }
    return moved;
}

void Rook::move(int file, int rank){
    Pieces::move(file, rank);
}

Rook :: Rook(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type=type;
    off_centre_x = 24;
    off_centre_y = 27;
    if (piece_type==black_rook){
        srcRect={352,12,44,49};
    }
    else if (piece_type==white_rook){
        srcRect = {760, 12, 44, 49};
    }
}



bool King::move_possible(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = abs(prev_rank-rank);
    int file_diff = abs(prev_file-file);
    bool moved = false ;
    if (rank_diff<=1 and file_diff<=1 and rank_diff+file_diff>=1){
        moved = true;
    }
    return moved;
}
void King::move(int file, int rank){
    Pieces::move(file, rank);
}

King :: King(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type=type;
    off_centre_x = 21;
    off_centre_y = 15;
    if (piece_type==black_king){
        srcRect={75,7,54,54};
    }
    else if (piece_type=white_king){
        srcRect = {483, 7, 54, 54};
    }
}


bool Queen::move_possible(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = abs(prev_rank-rank);
    int file_diff = abs(prev_file-file);
    bool moved = false ;
    if (rank_diff==0 or file_diff==0 or rank_diff==file_diff){
        moved = true;
    }
    return moved;
}

void Queen::move(int file, int rank){
    Pieces::move(file, rank);
}

Queen :: Queen(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type = type;
    off_centre_x = 15;
    off_centre_y = 18;
    if (piece_type==black_queen){
        srcRect= {276,7,60,54};
    }
    else if (piece_type==white_queen){
        srcRect = {684, 7, 60, 54};
    }
}


bool Knight::move_possible(int file, int rank, int prev_file, int prev_rank){
    int rank_diff = abs(prev_rank-rank);
    int file_diff = abs(prev_file-file);
    bool moved = false ;
    if ((rank_diff==2 and file_diff==1)or (rank_diff==1 and file_diff==2)){
        moved = true;
    }
    
    return moved;
}

void Knight::move(int file, int rank){
    Pieces::move(file, rank);
}

Knight :: Knight(Allpieces type, SDL_Rect mover) {
    movRect = mover;
    piece_type = type;
    off_centre_x = 19;
    off_centre_y = 21;
    if (piece_type==black_knight){
        srcRect= {143,9,52,52}; 
    }
    else if (piece_type==white_knight){
        srcRect = {551, 9, 52, 52};
    }
    
    
}