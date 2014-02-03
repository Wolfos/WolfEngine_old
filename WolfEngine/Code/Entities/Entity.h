#ifndef _ENTITY_H
#define _ENTITY_H

#include <stdio.h>

typedef struct
{
	char* name;
	int x, y, w, h;
	void(*Update)();
} Entity;

Entity NewEntity(char* name);

#endif