#include "Board.hpp"
#include <vector>
void Board::initialize(){
    vector <Pieces> myPieces;
    ;
    
    
    

    
    
    
    



    SDL_Rect myMover = {700, 700, 38, 49};

    // for black pawns
    myMover = {60, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {152, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {244, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {336, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {428, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {520, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));
    
    myMover = {612, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    myMover = {702, 150, 38, 49};
    myPieces.push_back(Pawn (black_pawn, myMover));

    // for black bishops
    myMover = {236, 50, 54, 53};
    myPieces.push_back(Bishop (black_bishop, myMover));

    myMover = {512, 50, 54, 53};
    myPieces.push_back(Bishop (black_bishop, myMover));

    // for black Rooks
    myMover = {60, 50, 44, 49};
    myPieces.push_back(Rook (black_rook, myMover));

    myMover = {702, 50, 44, 49};
    myPieces.push_back(Rook (black_rook, myMover));

    // for black knights
    myMover = {145, 50, 52, 52};
    myPieces.push_back(Knight (black_knight, myMover));

    myMover = {605, 50, 52, 52};
    myPieces.push_back(Knight (black_knight, myMover));

    // for black queen
    myMover = {326, 50, 60, 56};
    myPieces.push_back(Queen (black_queen, myMover));

    // for black king
    myMover = {420, 50, 54, 54};
    myPieces.push_back(King (black_king, myMover));






    // for white pawns
    myMover = {60, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    myMover = {152, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    myMover = {244, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    myMover = {336, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    myMover = {428, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    myMover = {520, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));
    
    myMover = {612, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

     myMover = {702, 600, 38, 49};
    myPieces.push_back(Pawn (white_pawn, myMover));

    // for white bishops
    myMover = {236, 700, 54, 53};
    myPieces.push_back(Bishop (white_bishop, myMover));

    myMover = {512, 700, 54, 53};
    myPieces.push_back(Bishop (white_bishop, myMover));

    // for white rooks
    myMover = {60, 700, 44, 49};
    myPieces.push_back(Rook (white_rook, myMover));

    myMover = {702, 700, 44, 49};
    myPieces.push_back(Rook (white_rook, myMover));

    // for white knights
    myMover = {145, 700, 52, 52};
    myPieces.push_back(Knight (white_knight, myMover));

    myMover = {605, 700, 52, 52};
    myPieces.push_back(Knight (white_knight, myMover));

    // for white queen
    myMover = {326, 700, 60, 54};
    myPieces.push_back(Queen (white_queen, myMover));

    // for white king
    myMover = {420, 700, 54, 54};
    myPieces.push_back(King (white_king, myMover));





    // myMover = {60, 60, 38, 49};
    // myPieces.push_back(Rook (black_rook, myMover));

    // myMover = {152, 60, 38, 49};
    // myPieces.push_back(Knight (black_knight, myMover));


    // myPieces.push_back(Bishop (black_pawn));


    // myPieces.push_back(Queen (black_pawn));
    // myPieces.push_back(King (black_pawn));
    // myPieces.push_back(Bishop(black_pawn));
    // myPieces.push_back(Knight (black_pawn));
    // myPieces.push_back(Rook (black_pawn));


    for (int i=0; i<myPieces.size(); i++){
        display(myPieces[i].srcRect, myPieces[i].movRect);
    }

}

void Board::display(SDL_Rect& srcRect, SDL_Rect& movRect){
    SDL_RenderCopy(Board::gRenderer, Board::assets, &srcRect, &movRect);
}