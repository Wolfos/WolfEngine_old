#ifndef _GAMEMAIN_H
#define _GAMEMAIN_H
#include "../Includes.h"

void GameStart();
void GameMain();

SDL_Surface* Game_GetScreen();
void Game_SetScreen(SDL_Surface* source);

#endif
