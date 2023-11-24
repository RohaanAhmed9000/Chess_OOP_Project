#include "display.hpp"

void Pieces::display(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);    
}
