/*
WolfEngine © 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "Image.h"
#include "../Utilities/Debug.h"
#include <string.h>

///
///	Returns a pointer to an SDL_Surface from a filename
///
SDL_Texture* Image::Load(char* filename, SDL_Renderer* renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;
#ifdef ANDROID
	char newFilename[1024] = "Sprites/";
#else
	char newFilename[1024] = "../Assets/Sprites/";
#endif
	strcat(newFilename, filename);

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(newFilename);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", newFilename, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", newFilename, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}