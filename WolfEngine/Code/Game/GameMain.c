#include "../includes.h"

SDL_Surface* screen = NULL;

///
/// The game's main loop
///
void GameMain()
{
	printf("Hello!");
	SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0xFF, 0x00, 0x00 ) );
}

SDL_Surface* Game_GetScreen()
{
	return screen;
}

void Game_SetScreen(SDL_Surface* source)
{
	screen = source;
}