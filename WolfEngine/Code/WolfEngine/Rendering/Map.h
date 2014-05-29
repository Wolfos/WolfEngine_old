#ifndef _MAP_H
#define _MAP_H

#include "../Includes.h"
#include "../Includes/ECS.h"

///
/// A WolfEngine map object, currently deprecated
///
class Map {
	public:
		int width; /// Map width
		int height; /// Map height
		int layers; /// Number of layers in the map
		int *data; /// Pointer to the map's tiledata array
		//int *events; /// Pointer to the map's event data array
		void Load(char* filename);
		void Render(SDL_Renderer* target, int layer, SDL_Texture* spritesheet,
			int tilewidth, int tileheight, int offset, GameObject* camera);
		void Write(char* filename);
		int Get(int x, int y, int l);
};


#endif