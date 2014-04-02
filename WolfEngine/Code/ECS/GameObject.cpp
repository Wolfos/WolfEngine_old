#include "GameObject.h"
#include "stdlib.h"
void GameObject::Update()
{
	for(int i = 0; i<numComponents; i++)
	{
		static_cast<Component*>(components[i])->Update();
	}
}

void GameObject::Load()
{
	numComponents = 0;
}

Component* GameObject::GetComponent(char* name)
{
	for(int i = 0; i < numComponents; i++)
	{
		if(components[i]->name == name)
		{
			return components[i];
		}
	}
	return 0;
}

void GameObject::AddComponent(Component* component)
{
	components = (Component**)realloc(components, numComponents*sizeof(Component*));
	components[numComponents] = component;
	numComponents++;
}
