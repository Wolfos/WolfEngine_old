#ifndef _MAPRENDER_H
	#define _MAPRENDER_H

	#include "../Includes.h"
	#include "../Rendering/Camera.h"
	#include "Map.h"

void MapRender(SDL_Surface* surface, struct Map* map, int layer, SDL_Surface* spritesheet, 
	int tilewidth, int tileheight, int offset, Camera camera);
#endif
