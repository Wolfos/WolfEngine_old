#ifndef _MAPRENDER_H
	#define _MAPRENDER_H

	#include "../Includes.h"
	#include "Map.h"

	SDL_Surface* Render(struct Map* map, int layer,SDL_Surface* spritesheet, int tilewidth, int tileheight, int offset);
#endif
