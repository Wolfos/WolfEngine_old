#include "Includes.h"
#include "Game/GameMain.h"
#include "Editor/EditorMain.h"
#include "Models/Window.h"
#include "Input/Input.h"
#include "Utilities/Time.h"

//Screen dimension constants
int SCREEN_WIDTH = 960;
int SCREEN_HEIGHT = 640;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

const int MAXFPS = 60; //FPS to cap at. Set to -1 to disable

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
		window = SDL_CreateWindow("WolfEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
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

			//Initialize SDL_TTF
			if (TTF_Init())
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", SDL_GetError());
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
		
		Time::frameTimeS = (float)(curFrameTime - lastFrameTime) / 1000;
		int fps = 1.f / Time::frameTimeS;

		printf("%d\n", fps);

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
			case editor:
			{
				Editor_Update();
				//Blit the editor screen to the main screen so that EditorMain has full control over what to render there
				SDL_BlitSurface(Editor_GetScreen(), NULL, screenSurface, NULL);
				break;
			}
		}
		

		SDL_UpdateWindowSurface(window);
		lastFrameTime = curFrameTime;

		if (MAXFPS!=-1 && SDL_GetTicks() - curFrameTime < 1000 / MAXFPS)
			SDL_Delay((1000 / MAXFPS) - (SDL_GetTicks() - curFrameTime));
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
	Editor_SetScreen(SDL_GetWindowSurface(window));
	switch(mode){
		case game:
		{
			Game_Start();
			break;
		}
		case editor:
		{
			Editor_Start();
			break;
		}
	}
	MainLoop(mode);

	Game_Exit();

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
