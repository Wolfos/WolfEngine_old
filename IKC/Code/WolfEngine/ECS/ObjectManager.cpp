/*
WolfEngine © 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#include "ObjectManager.h"
#include <malloc.h>
#include "../Utilities/Debug.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Screen.h"

std::vector<GameObject*> ObjectManager::gameObjects;

void ObjectManager::Update()
{
	for (unsigned int i = 0; i<gameObjects.size(); i++)
	{
		static_cast<GameObject*>(gameObjects[i])->Update();
	}
}

void ObjectManager::Render()
{
	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->GetComponent<SpriteRenderer>()!=NULL)
		{
			for (int j = 0; j < Screen::layers; j++)
			{
				if (gameObjects[i]->GetComponent<SpriteRenderer>()->layer == j)
				{
					gameObjects[i]->GetComponent<SpriteRenderer>()->Render();
				}
			}
		}
	}
}


void ObjectManager::Exit()
{
	gameObjects.clear();
}


GameObject* ObjectManager::NewGameObject(char* name)
{
	GameObject* newObject = new GameObject;

	newObject->name = name;
	newObject->id = gameObjects.size();

	gameObjects.push_back(newObject);

	return newObject;
}


void ObjectManager::DeleteObject(GameObject* object)
{
	gameObjects.erase(gameObjects.begin() + object->id);
	if(object)delete object;
}