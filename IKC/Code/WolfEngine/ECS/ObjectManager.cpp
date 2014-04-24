/*
WolfEngine © 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "ObjectManager.h"
#include <malloc.h>
#include "../Utilities/Debug.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Screen.h"

GameObject** ObjectManager::gameObjects;
int ObjectManager::numObjects = 0;

void ObjectManager::Update()
{
	for (int i = 0; i<numObjects; i++)
	{
		static_cast<GameObject*>(gameObjects[i])->Update();
	}
}
void ObjectManager::Exit()
{
	for (int i = 0; i < numObjects; i++)
	{
		delete gameObjects[i];
	}
	if(gameObjects) free(gameObjects);
}

GameObject* ObjectManager::NewGameObject(char* name)
{
	GameObject* newObject = new GameObject;

	newObject->name = name;

	GameObject** oldPointer = gameObjects;
	gameObjects = (GameObject**)realloc(gameObjects, (numObjects + 1)*sizeof(GameObject*));
	if (!gameObjects)
	{
		free(oldPointer); //prevent the memory from being leaked in case realloc returns a nullpointer
		Debug::Log("Could not allocate memory for gameObjects array");
		return 0;
	}
	gameObjects[numObjects] = newObject;
	numObjects++;

	return newObject;
}

