#ifndef _INPUT_H
#define _INPUT_H
#include "Keys.h"
#include "../Includes.h"

extern Keys Input_Keys;

void Input_Update(SDL_Event * eventHandler);

#endif