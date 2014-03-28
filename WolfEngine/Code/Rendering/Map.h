#ifndef _MAP_H
#define _MAP_H

#include "../Includes.h"
#include "../Rendering/Camera.h"

///
/// A WolfEngine map object
///
class Map{
	public:
		int width; /// Map width
		int height; /// Map height
		int layers; /// Number of layers in the map
		int *data; /// Pointer to the map's tiledata array
		//int *events; /// Pointer to the map's event data array
		void Load(char* filename);
		void Render(SDL_Surface* target, int layer, SDL_Surface* spritesheet,
			int tilewidth, int tileheight, int offset, Camera camera);
		void Write(char* filename);
		int Get(int x, int y, int l);
};


#endif