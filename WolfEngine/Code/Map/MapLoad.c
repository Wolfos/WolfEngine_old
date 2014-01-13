#define _CRT_SECURE_NO_DEPRECATE //So MSVC doesn't bitch about fopen()
#include "../Includes.h"
#include "../Map/Map.h"

struct Map* LoadMap(char *filename)
{
	char * filedata; //The whole file as a single string
	long filesize; //Total number of characters in file
	char * strval;
	int * filearray = NULL; //All the data from the file as an array
	

	int layers = 0, width = 0, height = 0;

	struct Map *map = malloc(sizeof(struct Map));
	int *mapdata;
	int *events;

	int i = 0;

	FILE* file = fopen(filename, "r");
	if(!file)
	{
		printf("Error while opening file!\n");
		return 0;
	}

	//Get size of file, then read the file into a c string
	fseek(file,0,SEEK_END);
	filesize = ftell(file);
	fseek(file,0,SEEK_SET);
	filedata = malloc(sizeof(char)*filesize);
	fread(filedata, 1, filesize, file);


	//Separate all the values (and convert them to integers) by looping through the string using strtok
	strval = strtok(filedata, ";");
	while(strval)
	{
		filearray = realloc(filearray, sizeof(int*) * (i+1));
		filearray[i] = atoi(strval);
		strval = strtok(NULL, ";");
		i++;
	}

	layers=filearray[0];
	width=filearray[1];
	height=filearray[2];

	//printf("%d\n%d\n%d\n",layers,width,height);

	mapdata = calloc(width*height*layers,sizeof(int));
	events = calloc(width*height,sizeof(int));

	//Load mapdata
	i=0;
	while(i<layers*width*height)
	{
		mapdata[i]=filearray[i+3]; //Using i+3 because the first 3 values are width, height and number of layers
		i++;
	}

	//Load eventdata
	i=0;
	while(i<width*height)
	{
		events[i]=filearray[i+3+layers*width*height];
		i++;
	}

	map->width = width;
	map->height = height;
	map->layers = layers;
	map->data = mapdata;
	map->events = events;
	 
	return map;
}