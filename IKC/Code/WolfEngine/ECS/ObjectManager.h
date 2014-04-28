#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H
#include "GameObject.h"
#include "../Includes.h"
#include <vector>

class ObjectManager{
	public:
		static void Update();
		static void Render();
		static void Exit();
		static GameObject* NewGameObject(char* name);
		static void DeleteObject(GameObject* object);

	private:
		static std::vector<GameObject*> gameObjects;
};

#endif