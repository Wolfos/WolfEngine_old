#include "../Includes.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"
#include "../Input/Input.h"


SDL_Surface* screen = NULL;
SDL_Surface* spritesheet;
Camera camera;

TTF_Font* testFont = NULL;

Map map;

//Called only once when the game starts
void Game_Start()
{
	testFont = TTF_OpenFont("../Fonts/Oregon LDO.ttf", 20);
	map.Load("../Maps/Test.WolfMap");
	spritesheet = Image::Load("../Sprites/tiles_spritesheet.png",screen->format);
	camera.x = 0;
	camera.y = 0;
	camera.w = screen->w;
	camera.h = screen->h;
	//printf("%d",map->height);
}

///
/// The game's main loop
///
void Game_Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(screen, &screen->clip_rect, 0);

	map.Render(screen, 0, spritesheet, 70, 70, 2, camera);

	int camspeed = 5;

	if (Input::keys.ArrowLeft)camera.x-=camspeed;
	if (Input::keys.ArrowUp)camera.y -= camspeed;
	if (Input::keys.ArrowDown)camera.y += camspeed;
	if (Input::keys.ArrowRight)camera.x += camspeed;
}

void Game_Exit()
{
    SDL_FreeSurface(screen);
}

SDL_Surface* Game_GetScreen()
{
	return screen;
}

void Game_SetScreen(SDL_Surface* source)
{
	screen = source;
}
