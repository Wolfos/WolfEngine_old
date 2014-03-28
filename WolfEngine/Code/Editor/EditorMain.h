#ifndef _EDITORMAIN_H
#define _EDITORMAIN_H
#include "../Includes.h"
void Editor_Start();
void Editor_Update();
void Editor_Exit();
SDL_Surface* Editor_GetScreen();
void Editor_SetScreen(SDL_Surface* source);
#endif