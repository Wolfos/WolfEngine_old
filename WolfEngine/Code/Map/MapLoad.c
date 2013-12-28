#define _CRT_SECURE_NO_DEPRECATE //So MSVC doesn't bitch about fopen()
#include "../Includes.h"
#include "../Models/Map.h"

struct Map* LoadMap(char *filename)
{
	int layers;
	int width;
	int height;	

	struct Map *map = malloc(sizeof(struct Map));
	int *mapdata;

	int i, counter = 0;

	FILE* file = fopen(filename, "r");
	if(!file)
	{
		printf("Error while opening file!\n");
		return 0;
	}

	//Read layers, width and height
	while(fscanf(file,"%i;", &i)>0)
	{
		if(counter==0)layers = i;
		else if(counter==1)width = i;
		else if(counter==2)height = i;
		else break;
		counter++;
	}

	mapdata = calloc(width*height*layers,sizeof(int));

	counter=0;
	//Read the mapdata, fscanf continues where it left off
	while(fscanf(file, "%i;", &i)>0)
	{
		if(counter>width*height*layers)
		{
			printf("ERROR: specified map file is probably corrupt (got more values than expected)\n");
			break;
		}
		mapdata[counter]=i;
		counter++;
	}

	map->width = width;
	map->height = height;
	map->layers = layers;
	map->data = mapdata;
	 
	return map;
}