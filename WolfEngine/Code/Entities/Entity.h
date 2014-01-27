#ifndef _ENTITY_H
#define _ENTITY_H

#include <stdio.h>

typedef struct
{
	char* name;
	void(*Update)();
} Entity;

Entity NewEntity(char* name);

#endif