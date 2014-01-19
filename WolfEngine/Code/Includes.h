
// Global includes for each platform

#ifndef _INCLUDES_H
	#define _INCLUDES_H
	#ifdef _WIN32
		#include <SDL.h>
		#include <SDL_image.h>
	#else
		#include <SDL2/SDL.h>
		#include <SDL2/SDL_image.h>
	#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif
