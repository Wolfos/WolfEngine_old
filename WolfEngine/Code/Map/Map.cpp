#define _CRT_SECURE_NO_DEPRECATE //So MSVC doesn't bitch about fopen()
#include "Map.h"

void Map::Load(char *filename)
{
	char * filedata; //The whole file as a single string
	long filesize; //Total number of characters in file
	char * strval;
	int * filearray = NULL; //All the data from the file as an array

	int i = 0;

	FILE* file = fopen(filename, "r");
	if (!file)
	{
		printf("Error while opening file: %s\n", filename);
		return;
	}

	//Get size of file, then read the file into a c string
	fseek(file, 0, SEEK_END);
	filesize = ftell(file);
	fseek(file, 0, SEEK_SET);
	filedata = (char*)malloc(sizeof(char)*filesize);
	fread(filedata, 1, filesize, file);

	fclose(file);


	//Separate all the values (and convert them to integers) by looping through the string using strtok
	strval = strtok(filedata, ";");
	while (strval)
	{
		filearray = (int*)realloc(filearray, sizeof(int*)* (i + 1));
		filearray[i] = atoi(strval);
		strval = strtok(NULL, ";");
		i++;
	}

	free(filedata);

	layers = filearray[0];
	width = filearray[1];
	height = filearray[2];

	//printf("%d\n%d\n%d\n",layers,width,height);

	data = (int*)calloc(width*height*layers, sizeof(int));
	events = (int*)calloc(width*height, sizeof(int));

	//Load mapdata
	i = 0;
	while (i<layers*width*height)
	{
		data[i] = filearray[i + 3]; //Using i+3 because the first 3 values are width, height and number of layers
		i++;
	}

	//Load eventdata
	i = 0;
	while (i<width*height)
	{
		events[i] = filearray[i + 3 + layers*width*height];
		i++;
	}

	free(filearray);
}

void Map::Render(SDL_Surface* target, struct Map* map, int layer, SDL_Surface* spritesheet,
	int tilewidth, int tileheight, int offset, Camera camera)
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

	//printf("%d,%d\n",clip[1].x,clip[1].y);

	sourcerect.w = tilewidth;
	sourcerect.h = tileheight;
	targetrect.w = tilewidth;
	targetrect.h = tileheight;


	//Occlussion culling, but need to make sure we CAN cull first
	//If we can't cull (ergo, the map is too small or we're off the map), we just render the whole map
	if (camera.x >= 0)startX = camera.x / tilewidth;
	else startX = 0;

	if (camera.y >= 0)startY = camera.y / tileheight;
	else startY = 0;

	if (((camera.x + camera.w) / tilewidth) + 1 <= map->width)endX = ((camera.x + camera.w) / tilewidth) + 1;
	else endX = map->width;

	if (((camera.y + camera.h) / tileheight) + 1 <= map->height)endY = ((camera.y + camera.h) / tileheight) + 1;
	else endY = map->height;

	i = startX + startY * endY;
	for (y = startY; y<endY; y++)
	{
		for (x = startX; x<endX; x++)
		{
			targetrect.x = x*tilewidth - camera.x;
			targetrect.y = y*tileheight - camera.y;

			sourcerect.x = clip[map->data[i*(layer + 1)]].x;
			sourcerect.y = clip[map->data[i*(layer + 1)]].y;

			SDL_BlitSurface(spritesheet, &sourcerect, target, &targetrect);

			//i = x + y*endY;
			i++;
		}
		//Skip over the tiles we're not rendering
		i += startX;
		i += map->width - endX;
	}

	//SDL_BlitSurface(spritesheet,NULL,target,NULL);

	free(clip);
}