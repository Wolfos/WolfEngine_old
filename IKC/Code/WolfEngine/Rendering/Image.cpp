/*
WolfEngine � 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "Image.h"
#include "../Utilities/Debug.h"
#include <string.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif


SDL_Texture* Image::Load(char* filename, SDL_Renderer* renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;
#ifdef ANDROID
	char newFilename[1024] = "Sprites/";
#elif defined __APPLE__
    char newFilename[1024] = "WolfEngine.app/Contents/Resources/Assets/Sprites/";
#else
	char newFilename[1024] = "../Assets/Sprites/";
#endif
	strcat(newFilename, filename);

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(newFilename);
	if (!loadedSurface)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", newFilename, IMG_GetError());
		Debug::Log("Unable to load image");
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (!newTexture)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", newFilename, SDL_GetError());
			Debug::Log("Unable to create texture");
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}