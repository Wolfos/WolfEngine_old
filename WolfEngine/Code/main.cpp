#include "Includes.h"
#include "Game/GameMain.h"
#include "Models/Window.h"
#include "Input/Input.h"
#include "Utilities/Time.h"

//Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

int Init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return 0;
	}
	else
	{
		window = SDL_CreateWindow( "WolfEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return 0;
		}
		else
		{
			//Initialize SDL_Image
			int imgflags = IMG_INIT_PNG;
			if(!(IMG_Init(imgflags) & imgflags))
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				return 0;
			}
			else
			{
				screenSurface = SDL_GetWindowSurface( window );
			}
		}
	}
	return 1;
}

///
/// WolfEngine main loop
///
void MainLoop(enum Window mode)
{
	int quit = 0;
	SDL_Event eventHandler;
	Uint32 curFrameTime = 0;
	Uint32 lastFrameTime  = 0;
	Input input;

	while (!quit)
	{
		curFrameTime = SDL_GetTicks();
		Time_deltaTime = (float)(curFrameTime - lastFrameTime) * 1000;

		//printf("%d\n", 1 / ((curFrameTime - lastFrameTime) * 1000));

		while(SDL_PollEvent(&eventHandler)!=0)
		{
			input.Update(&eventHandler);
			if(eventHandler.type == SDL_QUIT)
			{
				quit = 1;
			}
		}
		switch(mode){
			case game:
			{
				Game_Update();
				//Blit the game screen to the main screen so that GameMain has full control over what to render there
				SDL_BlitSurface(Game_GetScreen(), NULL, screenSurface, NULL);
				break;
			}
		}


		SDL_UpdateWindowSurface(window);
		lastFrameTime = curFrameTime;
	}
}

int main( int argc, char* args[] )
{
	enum Window mode = game; //What mode are we going to run this in? Game or Editor?

	if(!Init())
	{
		printf("WolfEngine has failed to initialize. \n");
		return 1;
	}
	Game_SetScreen(SDL_GetWindowSurface(window)); //Initializes the game screen
	switch(mode){
		case game:
		{
			Game_Start();
		}
	}
	MainLoop(mode);

	Game_Exit();

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
