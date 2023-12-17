#include "Board.hpp"
#include <vector>

bool Board::isPathClear(int startRow, int startCol, int endRow, int endCol, int deltaRow, int deltaCol) const {

    if (deltaCol==0 and deltaRow==0){
        return true;
    }
    for (int i = startRow + deltaRow, j = startCol + deltaCol; i != endRow || j != endCol; i += deltaRow, j += deltaCol) {
        if (blocks[i][j].piece) {
            return false; // Path is not clear
        }
    }
    return true; // Path is clear
}



position& Board::select(int x, int y){

    int file = (x-35)/91; 
    int rank = (y-35)/91;
    // std::cout<<rank<<" "<<file<<endl;
    return blocks[rank][file];
}


void Board::move(int x, int y, int prev_x, int prev_y){

    int cur_file = (x-35)/91;
    int cur_rank = (y-35)/91; 

    int prev_file = (prev_x-35)/91;
    int prev_rank = (prev_y-35)/91; 
    
    int file_diff = cur_file-prev_file;
    int rank_diff = cur_rank-prev_rank;
    
    int path_file = prev_file;
    int path_rank = prev_rank;

    int file_change=0;
    int rank_change=0;

    if (rank_diff == 0) {
        file_change = (file_diff < 0) ? -1 : 1;
    } 
    else if (file_diff == 0) {
        rank_change = (rank_diff < 0) ? -1 : 1;          
    }    
    else if ((abs(rank_diff) == abs(file_diff) and (not rank_diff==0 and not file_diff==0))) {
        file_change = (file_diff < 0) ? -1 : 1;
        rank_change = (rank_diff < 0) ? -1 : 1;
    } 
        

    if (blocks[cur_rank][cur_file].piece){

        if (isPathClear(prev_rank, prev_file, cur_rank, cur_file, rank_change, file_change)){

            if ((blocks[prev_rank][prev_file].piece->piece_type==black_pawn) or (blocks[prev_rank][prev_file].piece->piece_type==white_pawn)){
                if ((blocks[prev_rank][prev_file].piece->piece_type==black_pawn and blocks[cur_rank][cur_file].piece->is_white()) or (blocks[prev_rank][prev_file].piece->piece_type==white_pawn and not blocks[cur_rank][cur_file].piece->is_white())) 
                {
                    if (blocks[prev_rank][prev_file].piece->taking(cur_file,cur_rank, prev_file, prev_rank)){
                        blocks[cur_rank][cur_file].piece = blocks[prev_rank][prev_file].piece;
                        blocks[prev_rank][prev_file].piece = nullptr;
                    }
                }
            }

            else if(blocks[prev_rank][prev_file].piece->move_possible(cur_file,cur_rank, prev_file, prev_rank)){
                if(blocks[prev_rank][prev_file].piece->is_white() and (not blocks[cur_rank][cur_file].piece->is_white())){
                blocks[prev_rank][prev_file].piece->move(cur_file,cur_rank);
                blocks[cur_rank][cur_file].piece = blocks[prev_rank][prev_file].piece;
                blocks[prev_rank][prev_file].piece = nullptr;
                }

            else if((not blocks[prev_rank][prev_file].piece->is_white()) and (blocks[cur_rank][cur_file].piece->is_white())){
                blocks[prev_rank][prev_file].piece->move(cur_file,cur_rank);
                blocks[cur_rank][cur_file].piece = blocks[prev_rank][prev_file].piece;
                blocks[prev_rank][prev_file].piece = nullptr;
                }
            }
        }
        
    }

    else if(blocks[prev_rank][prev_file].piece->move_possible(cur_file,cur_rank, prev_file, prev_rank)){

        if (isPathClear(prev_rank, prev_file, cur_rank, cur_file, rank_change, file_change)) {
                blocks[prev_rank][prev_file].piece->move(cur_file,cur_rank);
                blocks[cur_rank][cur_file].piece = blocks[prev_rank][prev_file].piece;
                blocks[prev_rank][prev_file].piece = nullptr;
            
        } 
        else {
            std::cout << "There is a piece in the way, can't move.\n";
        }
    }
}



void Board::setCoordinates(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            blocks[i][j].x = 35+j*91;
            blocks[i][j].y = 35+i*91;
        }
    }
}

void Board::initialize(){
        
    SDL_Rect myMover = {700, 700, 38, 49};
// for black pawns
    myMover = {60, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][0].piece = new Pawn (black_pawn, myMover);

    myMover = {152, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][1].piece = new Pawn (black_pawn, myMover);

    myMover = {244, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][2].piece = new Pawn (black_pawn, myMover);

    myMover = {336, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][3].piece = new Pawn (black_pawn, myMover);

    myMover = {428, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][4].piece = new Pawn (black_pawn, myMover);

    myMover = {520, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][5].piece = new Pawn (black_pawn, myMover);
    
    myMover = {612, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][6].piece = new Pawn (black_pawn, myMover);

    myMover = {702, 150, 38, 49};
    // myPieces.push_back(Pawn (black_pawn, myMover));
    blocks[1][7].piece = new Pawn (black_pawn, myMover);


    // for black bishops
    myMover = {236, 50, 54, 53};
    // myPieces.push_back(Bishop (black_bishop, myMover));
    blocks[0][2].piece = new Bishop (black_bishop, myMover);

    myMover = {512, 50, 54, 53};
    // myPieces.push_back(Bishop (black_bishop, myMover));
    blocks[0][5].piece = new Bishop (black_bishop, myMover);


    // for black Rooks
    myMover = {60, 50, 44, 49};
    // myPieces.push_back(Rook (black_rook, myMover));
    blocks[0][0].piece = new Rook (black_rook, myMover);

    myMover = {702, 50, 44, 49};
    // myPieces.push_back(Rook (black_rook, myMover));
    blocks[0][7].piece = new Rook (black_rook, myMover);


    // for black knights
    myMover = {145, 50, 52, 52};
    // myPieces.push_back(Knight (black_knight, myMover));
    blocks[0][1].piece = new Knight (black_knight, myMover);

    myMover = {605, 50, 52, 52};
    // myPieces.push_back(Knight (black_knight, myMover));
    blocks[0][6].piece = new Knight (black_knight, myMover);

    // for black queen
    myMover = {326, 50, 60, 56};
    // myPieces.push_back(Queen (black_queen, myMover));
    blocks[0][3].piece = new Queen (black_queen, myMover);


    // for black king
    myMover = {420, 50, 54, 54};
    myPieces.push_back(King (black_king, myMover));
    blocks[0][4].piece = new King (black_king, myMover);


    // for white pawns
    myMover = {60, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][0].piece = new Pawn (white_pawn, myMover);

    myMover = {152, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][1].piece = new Pawn (white_pawn, myMover);

    myMover = {244, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][2].piece = new Pawn (white_pawn, myMover);

    myMover = {336, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][3].piece = new Pawn (white_pawn, myMover);

    myMover = {428, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][4].piece = new Pawn (white_pawn, myMover);

    myMover = {520, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][5].piece = new Pawn (white_pawn, myMover);

    myMover = {612, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][6].piece = new Pawn (white_pawn, myMover);

    myMover = {702, 600, 38, 49};
    // myPieces.push_back(Pawn (white_pawn, myMover));
    blocks[6][7].piece = new Pawn (white_pawn, myMover);

    // for white bishops
    myMover = {236, 700, 54, 53};
    // myPieces.push_back(Bishop (white_bishop, myMover));
    blocks[7][2].piece = new Bishop (white_bishop, myMover);

    myMover = {512, 700, 54, 53};
    // myPieces.push_back(Bishop (white_bishop, myMover));
    blocks[7][5].piece = new Bishop (white_bishop, myMover);


    // for white rooks
    myMover = {60, 700, 44, 49};
    // myPieces.push_back(Rook (white_rook, myMover));
    blocks[7][0].piece = new Rook (white_rook, myMover);

    myMover = {702, 700, 44, 49};
    // myPieces.push_back(Rook (white_rook, myMover));
    blocks[7][7].piece = new Rook (white_rook, myMover);

    // for white knights
    myMover = {145, 700, 52, 52};
    // myPieces.push_back(Knight (white_knight, myMover));
    blocks[7][1].piece = new Knight (white_knight, myMover);

    myMover = {605, 700, 52, 52};
    // myPieces.push_back(Knight (white_knight, myMover));
    blocks[7][6].piece = new Knight (white_knight, myMover);


    // for white queen
    myMover = {326, 700, 60, 54};
    // myPieces.push_back(Queen (white_queen, myMover));
    blocks[7][3].piece = new Queen (white_queen, myMover);


    // for white king
    myMover = {420, 700, 54, 54};
    // myPieces.push_back(King (white_king, myMover));
    blocks[7][4].piece = new King (white_king, myMover);
}


void Board::draw(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            if (blocks[i][j].piece)
                display(blocks[i][j].piece->srcRect, blocks[i][j].piece->movRect);
        }
    }
}

void Board::display(SDL_Rect& srcRect, SDL_Rect& movRect){
    SDL_RenderCopy(Board::gRenderer, Board::assets, &srcRect, &movRect);
}