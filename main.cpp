// DO NOT CHANGE THIS FILE
#include "game.hpp"
#include <Windows.h>
#include <string>

void getMouseClickCoordinates(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
}
int  main(int argc, char *argv[])
{
    string path="menu.png";
    string music;
	music = "E:\SEM 3\OOP\oop project\Chess_OOP_Project-u\Chess_OOP_Project-u\board.mp3";
    while (true) {
        // if (GetAsyncKeyState(VK_LBUTTON) & 0x8001) {
        //     int x, y;
        //     getMouseClickCoordinates(x, y);
        //     std::cout << "Mouse clicked at: (" << x << ", " << y << ")\n";
        // }
    Game game;
    
    srand(time(NULL));
    if (!game.init()) // IDK WHAT TO DO IDK WHAT TO DO
    {
        // bool success=true;
        printf("Failed to initialize!\n");

        // if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        //         {
        //             printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        //             success = false;
        //         }
        //         return success;
        return 0;
    }
    // Load media
    if (!game.loadMedia(path))
    {
        printf("Failed to load media!\n");
        return 0;
    }
    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    // SDL_Log("SDL_mixer initialization error: %s", Mix_GetError());
    // SDL_Quit();
    // return -1;
    // }
    //Mix_FreeMusic(music);
    //Mix_CloseAudio();
    game.run();
    //Mix_PlayMusic(music, -1);
    game.close();

    return 0;
    
}
}


