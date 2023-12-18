#include "game.hpp"
// //#include "logic.cpp"
// //#include <SDL.h>
// // #include "GhostBuster.hpp"
// #include "Board.hpp"


char ** grid = NULL;
int rows=8;
int cols=8;
const int width = 800, height = 800;
void initial();

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//sWindow = gWindow = SDL_CreateWindow("menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			//sRenderer = SDL_CreateRenderer(sWindow, -2, SDL_RENDERER_ACCELERATED);
			
			if (gRenderer == NULL )
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//SDL_SetRenderDrawColor(sRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia(string path)
{
	// Loading success flag
	bool success = true;

	// assets = loadTexture("assets.png");
	gTexture = loadTexture(path);
	//sTexture = loadTexture ("menu.png");
	if ( gTexture == NULL  )
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// quitGhostBuster();
	// Free loaded images
	// SDL_DestroyTexture(assets);
	assets = NULL;
	//SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	// SDL_DestroyRenderer(sRenderer);
	// SDL_DestroyWindow(sWindow);
	// sWindow = NULL;
	// sRenderer = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}



void Game::run()
{
	bool quit = false;
	SDL_Event e;
	// initial();

	//int click=0;
	while (!quit)
	{
		// Handle events on queue
		int xMouse=1000, yMouse=1000;
		position* cur_pos;
		static int click = 0;

		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&xMouse, &yMouse);
	
				if (click==1){ //there was a piece selected on the last move
					myBoard.move(xMouse, yMouse, cur_pos->x, cur_pos->y); //movement and interaction of the pieces
					cur_pos=nullptr;
					click=0;
					break;
				}

				if (!(xMouse>760 || yMouse>760 || xMouse<35 || yMouse<35) && click==0){

					cur_pos = &(myBoard.select(xMouse,yMouse)); // selecting a piece
					if (cur_pos->piece){ //checking if there is a piece on the selected square
						click=1;
					}
				}
			}
		}

		SDL_RenderClear(gRenderer); // removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
    
		static int count=0;

    	if (count==0){
			myBoard.assets = loadTexture("spritesheet.png");
			myBoard.gRenderer = gRenderer;
			myBoard.initialize();
			myBoard.setCoordinates();
			count++;
		}
		
        myBoard.draw();

		SDL_RenderCopy(gRenderer, assets, &srcRect, &movRect);

		//****************************************************************
		SDL_RenderPresent(gRenderer); // displays the updated renderer

		SDL_Delay(200); // causes sdl engine to delay for specified miliseconds
	}
}

void Game::transition()
{
    string path = "menu.png";
    string music;
    // music = "E:/SEM 3/OOP/oop project/Chess_OOP_Project-u/Chess_OOP_Project-u/board.mp3";
    // Mix_PlayMusic(music, -1);
    // game.close();
    bool quit = false;
    SDL_Event e;
    // initial();

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int xMouse, yMouse;

                SDL_GetMouseState(&xMouse, &yMouse);
                if ((xMouse >= 154 && xMouse <= 346) && (yMouse >= 331 && yMouse <= 365))  // for start
                    {
                        // code for main screen
                        loadMedia("background.png");
                        Game::run();
                        // string music;
                        // music = "E:\SEM 3\OOP\oop project\Chess_OOP_Project-u\Chess_OOP_Project-u\board.mp3";
                        // backgroundmusic = Mix_LoadWAV(music);
                    }
                    else if ((xMouse >= 466 && xMouse <= 658) && (yMouse >= 331 && yMouse <= 366)) {
                        // code for exit
                        // std::cout<<'close';
                        close();  // this gives errors
                    }
            }

            SDL_RenderClear(gRenderer);
            // SDL_RenderClear(mRenderer);

            // removes everything from renderer
            // SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
            //***********************draw the objects here********************
            SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
            // SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);

            // myBoard.assets = loadTexture("spritesheet.png");
            myBoard.gRenderer = gRenderer;
            // SDL_RenderCopy(sRenderer, sTexture, NULL, NULL);
            // drawBlocks(gRenderer, assets);

            assets = loadTexture("spritesheet.png");

            // movRect = {100, 100, 50, 50};
            // srcRect = {7, 8, 54, 53};

            myBoard.initialize();

            SDL_RenderCopy(gRenderer, assets, &srcRect, &movRect);

            //****************************************************************
            SDL_RenderPresent(gRenderer);  // displays the updated renderer

            SDL_Delay(200);  // causes sdl engine to delay for specified miliseconds
        }
    }
}
