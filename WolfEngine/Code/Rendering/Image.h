#ifndef _IMAGE_H
	#define _IMAGE_H
	#include "../Includes.h"
	class Image{
		public:
			static SDL_Surface* Load(char* filename, SDL_PixelFormat* format);
	};
#endif