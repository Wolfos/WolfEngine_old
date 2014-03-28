#include "../Includes.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"
#include "../Input/Input.h"
#include "../Utilities/Time.h"

SDL_Surface* gameScreen = NULL;
SDL_Surface* spritesheet;
Camera camera;

TTF_Font* testFont = NULL;

Map map;

//Called only once when the game starts
void Game_Start()
{
	testFont = TTF_OpenFont("../Fonts/Oregon LDO.ttf", 20);
	map.Load("../Maps/map.WolfMap");
	spritesheet = Image::Load("../Sprites/tiles_spritesheet.png", gameScreen->format);
	camera.x = 0;
	camera.y = 0;
	camera.w = gameScreen->w;
	camera.h = gameScreen->h;
	//map.Render(gameScreen, 0, spritesheet, 70, 70, 2, camera);
}

///
/// The game's main loop
///
void Game_Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(gameScreen, &gameScreen->clip_rect, 0);

	map.Render(gameScreen, 0, spritesheet, 70, 70, 2, camera);

	int camspeed = 500;

	if (Input::keys.ArrowLeft)camera.x-=camspeed*Time::frameTimeS;
	if (Input::keys.ArrowUp)camera.y -= camspeed*Time::frameTimeS;
	if (Input::keys.ArrowDown)camera.y += camspeed*Time::frameTimeS;
	if (Input::keys.ArrowRight)camera.x += camspeed*Time::frameTimeS;
}

void Game_Exit()
{
	SDL_FreeSurface(gameScreen);
}

SDL_Surface* Game_GetScreen()
{
	return gameScreen;
}

void Game_SetScreen(SDL_Surface* source)
{
	gameScreen = source;
}
