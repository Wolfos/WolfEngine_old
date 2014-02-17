#include "../Includes.h"
#include "../Map/MapLoad.h"
#include "../Map/Map.h"
#include "../Map/MapRender.h"
#include "../Rendering/Image.h"
#include "../Input/Input.h"



SDL_Surface* screen = NULL;
SDL_Surface* spritesheet;
Camera camera;

struct Map* map;

//Called only once when the game starts
void Game_Start()
{
	map = LoadMap("../Maps/Test.WolfMap");
	spritesheet = LoadImage("../Sprites/tiles_spritesheet.png",screen->format);
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

	MapRender(screen, map, 0, spritesheet, 70, 70, 2, camera);

	if (Input_Keys.ArrowLeft)camera.x--;
	if (Input_Keys.ArrowUp)camera.y--;
	if (Input_Keys.ArrowDown)camera.y++;
	if (Input_Keys.ArrowRight)camera.x++;
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
