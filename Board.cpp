#include "Board.hpp"
#include <vector>
void Board::initialize(){
    vector <Pieces> myPieces;
    ;
    // myPieces.push_back(Rook (white_rook));
    // myPieces.push_back(Rook (white_rook));
    // myPieces.push_back(Rook (black_rook));
    // myPieces.push_back(Rook (black_rook));

    // myPieces.push_back(Bishop (white_bishop));
    // myPieces.push_back(Bishop (white_bishop));
    // myPieces.push_back(Bishop (black_bishop));
    // myPieces.push_back(Bishop (black_bishop));

    // myPieces.push_back(Knight (white_knight));
    // myPieces.push_back(Knight (white_knight));
    // myPieces.push_back(Knight (black_knight));
    // myPieces.push_back(Knight (black_knight));

    // myPieces.push_back(Queen (white_queen));
    // myPieces.push_back(Queen (black_queen));

    // myPieces.push_back(King (white_king));
    // myPieces.push_back(King (black_king));

    SDL_Rect myMover = {50, 50, 50, 50};
    myPieces.push_back(Pawn (white_pawn, myMover));

    for (int i=0; i<myPieces.size(); i++){
        display(myPieces[i].srcRect, myPieces[i].movRect);
    }


    // myPieces.push_back(Pawn (white_pawn, myMover));
    // myPieces.push_back(Pawn (white_pawn, myMover));
    // myPieces.push_back(Pawn (white_pawn, myMover));
    // myPieces.push_back(Pawn (white_pawn, myMover));
    // myPieces.push_back(Pawn (white_pawn, myMover));
    // myPieces.push_back(Pawn (white_pawn));
    // myPieces.push_back(Pawn (white_pawn));
    
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));
    // myPieces.push_back(Pawn (black_pawn));

}

void Board::display(SDL_Rect& srcRect, SDL_Rect& movRect){
    SDL_RenderCopy(Board::gRenderer, Board::assets, &srcRect, &movRect);
}