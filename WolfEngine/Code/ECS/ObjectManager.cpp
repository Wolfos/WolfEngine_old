#include "ObjectManager.h"
#include <malloc.h>
#include "../Utilities/Debug.h"

GameObject** ObjectManager::gameObjects;
int ObjectManager::numObjects = 0;

void ObjectManager::Load()
{
}

void ObjectManager::Update()
{
	for (int i = 0; i<numObjects; i++)
	{
		static_cast<GameObject*>(gameObjects[i])->Update();
	}
}
GameObject* ObjectManager::NewGameObject(char* name)
{
	GameObject* newObject = (GameObject*)malloc(sizeof(GameObject));
	newObject = new GameObject;

	gameObjects = (GameObject**)realloc(gameObjects, (numObjects + 1)*sizeof(GameObject*));
	gameObjects[numObjects] = newObject;
	newObject->Load();
	numObjects++;

	newObject->name = name;
	//Check if name was available in the first place
	for (int i = 0; i < numObjects; i++)
	{
		if (gameObjects[i]->name == name)
		{
			newObject->name = name + 1;
		}
	}
	return newObject;
}