// DO NOT CHANGE THIS FILE
#include "game.hpp"
#include <Windows.h>

void getMouseClickCoordinates(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
}
int  main(int argc, char *argv[])
{
    while (true) {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8001) {
            int x, y;
            getMouseClickCoordinates(x, y);
            std::cout << "Mouse clicked at: (" << x << ", " << y << ")\n";
        }
    Game game;
    
    srand(time(NULL));
    if (!game.init())
    {
        printf("Failed to initialize!\n");
        return 0;
    }
    // Load media
    if (!game.loadMedia())
    {
        printf("Failed to load media!\n");
        return 0;
    }

    game.run();
    game.close();

    return 0;
    
}
}


