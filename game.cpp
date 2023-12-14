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

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	// assets = loadTexture("assets.png");
	gTexture = loadTexture("background.png");
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

	while (!quit)
	{
		// Handle events on queue
		int xMouse=1000, yMouse=1000;
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				// this is a good location to add pigeon in linked list.
				int xMouse=1000, yMouse=1000;
				SDL_GetMouseState(&xMouse, &yMouse);

				// std::cout<<xMouse<<" "<<yMouse<<endl;
				// if (e.button.button == SDL_BUTTON_LEFT)
				// 	huntGhost(xMouse, yMouse);
				// else
				// 	bustGhost(xMouse, yMouse);
			}
		}

		SDL_RenderClear(gRenderer); // removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
    
		int count=0;

		// to check whether a piece is selected
		bool slct= false;

		int I=-1,J=-1,K=-1;
		
    	if (count==0){
			myBoard.assets = loadTexture("spritesheet.png");
			myBoard.gRenderer = gRenderer;
			myBoard.initialize();
			myBoard.setCoordinates();
			count++;
		}

		int cur_rank, cur_file = 0;
		// static int click = 0;
		std::cout<<xMouse<<" "<<yMouse<<endl;
		if ((xMouse>=35 and xMouse<=762) and (yMouse>=35 and yMouse<=762)){
			// cur_rank, cur_file = myBoard.select(xMouse,yMouse);
			// Pieces* cur_piece = myBoard.blocks[cur_rank][cur_file].piece;
			// click = 1;
			// std::cout<<cur_rank<<" "<<cur_file<<endl;s
		}
// 
		// if (click==1){
		myBoard.move(xMouse, yMouse, cur_rank, cur_file);
			// count = 0;
		// }

		// else {
		// 	count = 0;
		// }
		// slct,I,J,K=myBoard.select(xMouse,yMouse);
		// if (slct){
		// 	std::cout<<I<<", "<<J<<endl;
		// 	slct,I,J,K=myBoard.move(xMouse,yMouse,I,J,K);
		// }
		
        myBoard.draw();

		SDL_RenderCopy(gRenderer, assets, &srcRect, &movRect);

		//****************************************************************
		SDL_RenderPresent(gRenderer); // displays the updated renderer

		SDL_Delay(200); // causes sdl engine to delay for specified miliseconds
	}
}






// void initial()
// {
//     for (int i=0; i<rows ; i++ )
//     {
//         for (int j=0; j< cols ; j++)
//         {
//             if (i==1 || i==0)
//             {
//                 if(i==1){
//                     grid[i][j]='P';
//                 }
//                 else{
//                     switch(j)
//                     {
//                         case 0:grid[i][j]='R'; break;
//                         case 1:grid[i][j]='N'; break;
//                         case 2:grid[i][j]='B'; break;
//                         case 3:grid[i][j]='Q'; break;
//                         case 4:grid[i][j]='K'; break;
//                         case 5:grid[i][j]='B'; break;
//                         case 6:grid[i][j]='N'; break;
//                         case 7:grid[i][j]='R'; break;
//                     }
                
//                 }
//             }
//             else if(i==6 || i==7)
//             {
//                 if(i==6){
//                     grid[i][j]='p';
//                 }
//                 else{
//                     switch(j){
//                         case 0:grid[i][j]='r'; break;
//                         case 1:grid[i][j]='n'; break;
//                         case 2:grid[i][j]='b'; break;
//                         case 3:grid[i][j]='q'; break;
//                         case 4:grid[i][j]='k'; break;
//                         case 5:grid[i][j]='b'; break;
//                         case 6:grid[i][j]='n'; break;
//                         case 7:grid[i][j]='r'; break;
//                     }    
//                 }
//             }
//         }
//     }
// }

// void drawOneBlock(SDL_Renderer* renderer, SDL_Texture* texture, int row, int col, char sym)
// {
//     int xbox = 800/cols;
//     int ybox = 800/rows;
//     SDL_Rect src;
//     switch(sym){
//     // BLACK IS CAPITAL YANI UPPER CASE !
//         case 'P': src = {219, 12, 38, 49}; break; // pawn
//         case 'B': src = {7, 8, 54, 53}; break;  // bishop
//         case 'K': src = {75, 7, 54, 54}; break;
//         case 'Q': src = {276, 7, 60, 56}; break; // 54
//         case 'R': src = {352, 12, 44, 49}; break;
//         case 'N': src = {143, 9, 52, 52}; break; // knight
//         // white
//         case 'p': src = {627, 12, 38, 49}; break;
//         case 'b': src = {415, 8, 54, 53}; break;
//         case 'k': src = {483, 7, 54, 54}; break;
//         case 'q': src = {684, 7, 60, 54}; break;
//         case 'r': src = {760, 12, 44, 49}; break;
//         case 'n': src = {551, 9, 52, 52}; break;
//     }
//     SDL_Rect mov = { xbox*col, ybox*row, xbox - 10, ybox - 10};
//     SDL_RenderCopy(renderer, texture, &src, &mov);

// }

// void drawBlocks(SDL_Renderer* renderer, SDL_Texture* texture){
//     // Call drawOneBlock for all of the blocks of grid
//     // for example to draw a snake over block (3, 5) you call it this way:
//     // drawOneBlock(renderer, texture, 3, 5, 'S');
//     if(grid == NULL) return;
//     for(int i=0;i<rows; i++){
//         for(int j=0;j<cols; j++){
//             drawOneBlock(renderer, texture, i, j, grid[i][j]);
//         }   
//     }
// }