#include "../Includes.h"
#include "../Map/MapLoad.h"
#include "../Map/Map.h"

SDL_Surface* screen = NULL;
struct Map* map;

//Called only once when the game starts
void Game_Start()
{
	map = LoadMap("../Maps/Test.WolfMap");
	//printf("%d",map->height);
}

///
/// The game's main loop
///
void Game_Update()
{

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
