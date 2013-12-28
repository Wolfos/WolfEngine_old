#include "../Includes.h"
#include "../Map/MapLoad.h"
#include "../Models/Map.h"

SDL_Surface* screen = NULL;
struct Map* map;

//Called only once when the game starts
void GameStart()
{
	map = LoadMap("Maps/Test.WolfMap");
}

///
/// The game's main loop
///
void GameMain()
{
	//SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0xFF, 0x00, 0x00 ) );
}

SDL_Surface* Game_GetScreen()
{
	return screen;
}

void Game_SetScreen(SDL_Surface* source)
{
	screen = source;
}
