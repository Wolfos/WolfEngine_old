#ifndef _MAPRENDER_H
	#define _MAPRENDER_H

	#include "../Includes.h"
	#include "Map.h"

	SDL_Surface* Render(struct Map* map, int layer);
#endif