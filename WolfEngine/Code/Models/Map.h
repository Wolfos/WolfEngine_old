#ifndef _MAP_H
#define _MAP_H
///
/// Where all the data from the map files is stored
///
struct Map{
	int width;
	int height;
	int layers;
	int *data;
};
#endif