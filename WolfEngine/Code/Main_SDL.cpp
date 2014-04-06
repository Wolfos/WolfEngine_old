#include "Includes.h"
#include "Game/GameMain.h"
#include "Editor/EditorMain.h"
#include "Input/Input.h"
#include "Utilities/Time.h"
#include "Utilities/Debug.h"
#include "ECS/ObjectManager.h"
#include "Rendering\Screen.h"

//Screen dimension constants
int SCREEN_WIDTH = 960;
int SCREEN_HEIGHT = 640;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

EditorMain editorMain;
GameMain gameMain;

ObjectManager objMgr;

const int MAXFPS = 60; //FPS to cap at. Set to -1 to disable

//List of modes the application can run in
enum Window{
	game, editor
};

int Init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		Debug::Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	else
	{
		window = SDL_CreateWindow("WolfEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
		if( window == NULL )
		{
			Debug::Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return 1;
		}
		else
		{
			//Initialize SDL_Image
			int imgflags = IMG_INIT_PNG;
			if(!(IMG_Init(imgflags) & imgflags))
			{
				Debug::Log("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				return 1;
			}
			else
			{
				screenSurface = SDL_GetWindowSurface( window );
			}

			//Initialize SDL_TTF
			if (TTF_Init())
			{
				Debug::Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", SDL_GetError());
				return 1;
			}
		}
	}
	return 0;
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
		//Debug::Log("%d\n",fps);

		//Fill screen with black to clear it before rendering
		SDL_FillRect(screenSurface, &Screen::mainCamera->screen->clip_rect, 0);

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
				gameMain.Update();
				break;
			}
			case editor:
			{
				editorMain.Update();
				break;
			}	
		}

		//Update the gameObjects
		ObjectManager::Update();

		SDL_UpdateWindowSurface(window);
		lastFrameTime = curFrameTime;

		if (MAXFPS!=-1 && SDL_GetTicks() - curFrameTime < 1000 / MAXFPS)
			SDL_Delay((1000 / MAXFPS) - (SDL_GetTicks() - curFrameTime));
	}
}

int main( int argc, char* args[] )
{
	Window mode = game; //What mode are we going to run this in? Game or Editor?

	if(Init())
	{
		Debug::Log("WolfEngine has failed to initialize.\n");
		Debug::Log("¦¦¦¦¦¦¦¦¦_¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¦¦¦¦	Wow!\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¯¦¦¦¦¦\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¯¦¦¦¦¦¦¦\n¦¦¦¦¦¦¦¦_¯¦¦¯¯¯¯___¯¦¦¦¦¦¦¦¦¦\n¦¦¦¦¦__¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¦¦¦¦¦¦\n¦¦¦_¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯¦¦¯¦¦¦¦¦\n¦¦¦¦¦¦__¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯_¦¦¦¦¦		Much error :(\n¦¦¦¦¦¦¦¯¦¦¦¦¦_¯¦_¦¦¦¦¦¦¦¦¦¦¦¦\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯¦¦¦¦¦¦¦¦¯_¦¦\n¦¦¦¦_¦¦_¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¯¦¯¦_¦_¦¦_¦¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦¦¦¦¯¦¯¦¦__¦_¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦¦¦¦¯¯__¦¦¦_¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦¦¦¦¦¦¦¦¯¯¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦	Many wrong\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¦¦¦¦¦\n¦¦¯_¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¦¦¦¦¦¦¦\n¦¦¦¦¯_¦¦¦¦¦¦¦¦¦¦___¯¦¦¦¦_¯¦¦¦\n¦¦¦¦¦¦¯______¯¯¯¦¦¦¦¦__¯¦¦¦¦¦\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯¯¦¦¦¦¦¦¦¦\n");
		return 1;
	}
	editorMain.SetScreen(SDL_GetWindowSurface(window));

	//Initialize the camera
	GameObject* camera = ObjectManager::NewGameObject("Camera");
	camera->AddComponent<Camera>();
	camera->GetComponent<Camera>()->screen = SDL_GetWindowSurface(window);
	camera->GetComponent<Camera>()->width = screenSurface->w;
	camera->GetComponent<Camera>()->height = screenSurface->h;

	ObjectManager::Load();
	switch(mode){
		case game:
		{
			gameMain.Start();
			break;
		}
		case editor:
		{
			editorMain.Start();
			break;
		}
	}

	MainLoop(mode);

	gameMain.Exit();

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
