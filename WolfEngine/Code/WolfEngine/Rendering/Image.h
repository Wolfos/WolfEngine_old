#ifndef _IMAGE_H
#define _IMAGE_H
#include "../Includes.h"
#include <string>

///
/// Contains functions regarding the loading of images from file
///
class Image{
	public:
		///	Returns a pointer to an SDL_Texture from a filename
    static SDL_Texture* Load(std::string filename);
};
#endif