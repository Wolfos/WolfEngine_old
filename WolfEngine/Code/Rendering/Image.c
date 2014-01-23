#include "Image.h";

SDL_Surface* LoadImage(char* filename, SDL_PixelFormat* format)
{
	SDL_Surface* optimized = NULL;

	SDL_Surface* loaded = IMG_Load(filename);

	if(!loaded)
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError() );
	}
	else
	{
		optimized = SDL_ConvertSurface(loaded,format,NULL);
		if(!optimized)
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", filename, SDL_GetError() );
		}
		
		SDL_FreeSurface(loaded);
	}

	return optimized;
}