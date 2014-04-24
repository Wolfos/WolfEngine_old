#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H
#include "GameObject.h"
#include "../Includes.h"

class ObjectManager{
	public:
		static void Update();
		static void Exit();
		static GameObject* NewGameObject(char* name);

	private:
		static GameObject** gameObjects;
		static int numObjects;
};

#endif