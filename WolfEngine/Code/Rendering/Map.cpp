#define _CRT_SECURE_NO_DEPRECATE //So MSVC doesn't bitch about fopen()
#include "Map.h"
#include "../Utilities/Debug.h"
#include "../Components/Transform.h"

///
/// Loads the map from a file
///
void Map::Load(char *filename)
{
	FILE *f = fopen(filename, "rb");

	if (!f)
	{
		Debug::Log("Could not load %s", filename);
		return;
	}

	int w, h, l;

	fread(&w, sizeof(int), 1, f);
	fread(&h, sizeof(int), 1, f);
	fread(&l, sizeof(int), 1, f);

	layers = l;
	width = w;
	height = h;

	data = (int*)calloc(width*height*layers, sizeof(int));

	for (int i = 0; i < width*height*layers; i++)
	{
		fread(&data[i], sizeof(int), 1, f);
	}

	fclose(f);
}

void Map::Write(char* filename)
{
	FILE *f = fopen(filename, "wb");
	if (!f)
	{
		Debug::Log("Error opening %s for writing", filename);
	}

	fwrite(&width, sizeof(int), 1, f);
	fwrite(&height, sizeof(int), 1, f);
	fwrite(&layers, sizeof(int), 1, f);
	fwrite(data, sizeof(int), width*height*layers, f);

	fclose(f);
}

int Map::Get(int x, int y, int l)
{
	int pos = x + (y*width);

	//Move to correct layer
	pos += (width*height)*l;

	int val = data[pos];

	return val;
}

///
/// Renders the map to an SDL_Surface you specify as a target
///
void Map::Render(SDL_Surface* target, int layer, SDL_Surface* spritesheet,
	int tilewidth, int tileheight, int offset, GameObject* camera)
{
	SDL_Rect* clip;


	//Tiles to start and finish render on
	int startX;
	int startY;
	int endX;
	int endY;

	SDL_Rect sourcerect;
	SDL_Rect targetrect;
	int x, y, i;

	int sheetwidth;
	int sheetheight;

	sheetwidth = spritesheet->clip_rect.w / tilewidth;
	sheetheight = spritesheet->clip_rect.h / tileheight;

	clip = (SDL_Rect*)calloc(sheetwidth*sheetheight, sizeof(SDL_Rect));

	i = 0;
	//Clip contains the position of each possible tile
	//X and Y are inverted because we read from left to right
	for (y = 0; y<sheetheight; y++)
	{
		for (x = 0; x<sheetwidth; x++)
		{
			clip[i].x = x*tilewidth + (offset*x);
			clip[i].y = y*tileheight + (offset*y);
			clip[i].w = tilewidth;
			clip[i].h = tileheight;
			i++;
		}
	}


	sourcerect.w = tilewidth;
	sourcerect.h = tileheight;
	targetrect.w = tilewidth;
	targetrect.h = tileheight;


	//Occlusion culling, but need to make sure we CAN cull first
	//If we can't cull (ergo, the map is too small or we're off the map), we just render the whole map
	if (camera->transform->position.x >= 0)startX = camera->transform->position.x / tilewidth;
	else startX = 0;

	if (camera->transform->position.y >= 0)startY = camera->transform->position.y / tileheight;
	else startY = 0;


	if (((camera->transform->position.x + camera->transform->scale.x) / tilewidth) + 1 <= width)
	{
		endX = ((camera->transform->position.x + camera->transform->scale.x) / tilewidth) + 1;
	}
	else endX = width;

	if (((camera->transform->position.y + camera->transform->scale.y) / tileheight) + 1 <= height)
	{
		endY = ((camera->transform->position.y + camera->transform->scale.y) / tileheight) + 1;
	}
	else endY = height;

	i = startX + startY * endY;
	for (y = startY; y<endY; y++)
	{
		for (x = startX; x<endX; x++)
		{
			targetrect.x = x*tilewidth - camera->transform->position.x;
			targetrect.y = y*tileheight - camera->transform->position.y;

			int val = Get(x, y, layer);
			if (val<=sheetwidth*sheetheight)
			{
				sourcerect.x = clip[val].x;
				sourcerect.y = clip[val].y;

				SDL_BlitSurface(spritesheet, &sourcerect, target, &targetrect);
			}

			//i = x + y*endY;
			i++;
		}
		//Skip over the tiles we're not rendering
		i += startX;
		i += width - endX;
	}

	//SDL_BlitSurface(spritesheet,NULL,target,NULL);

	free(clip);
}