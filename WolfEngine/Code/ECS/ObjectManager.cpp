#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "ObjectManager.h"
#include <malloc.h>
#include "../Utilities/Debug.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Screen.h"

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

	newObject->name = name;

	gameObjects = (GameObject**)realloc(gameObjects, (numObjects + 1)*sizeof(GameObject*));
	gameObjects[numObjects] = newObject;
	newObject->Load();
	numObjects++;

	return newObject;
}

