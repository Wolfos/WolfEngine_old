#ifndef _MAPRENDER_H
	#define _MAPRENDER_H

	#include "../Includes.h"
	#include "Map.h"

	void MapRender_Init(SDL_Surface* source);
	SDL_Surface* MapRender(struct Map* map, int layer,SDL_Surface* spritesheet, int tilewidth, int tileheight, int offset);
#endif
