#ifndef _IMAGE_H
#define _IMAGE_H
#include "../Includes.h"

///
/// Contains functions regarding the loading of images from file
///
class Image{
	public:
		static SDL_Texture* Load(char* filename, SDL_Renderer* renderer);
};
#endif