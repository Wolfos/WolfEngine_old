#include "GameObject.h"
#include "stdlib.h"
void GameObject::Update()
{
	for(int i = 0; i<numComponents; i++)
	{
		//components[i].Update();
		Component comp;
		comp.Update();
	}
}

void GameObject::Load()
{
	numComponents = 0;
}

Component GameObject::GetComponent(char* name)
{
	for(int i = 0; i < numComponents; i++)
	{
		if(components[i].name == name)
		{
			return components[i];
		}
	}
	Component component;
	component.name = "NULL";
	return component;
}

void GameObject::AddComponent(Component component)
{
	components = (Component*)realloc(components, numComponents*sizeof(Component*));
	components[numComponents] = component;
	numComponents++;
}
