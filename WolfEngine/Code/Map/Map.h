#ifndef _MAP_H
#define _MAP_H

#include "../Includes.h"
#include "../Rendering/Camera.h"
class Map{
	public:
		int width;
		int height;
		int layers;
		int *data;
		int *events;
		void Load(char* filename);
		void Render(SDL_Surface* target, struct Map* map, int layer, SDL_Surface* spritesheet,
			int tilewidth, int tileheight, int offset, Camera camera);
};


#endif