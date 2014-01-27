#include "Entity.h"

void Update()
{
}

Entity NewEntity(char* name)
{
	Entity ent;
	ent.name = name;

	ent.Update = &Update;

	return ent;
}

