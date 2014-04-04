#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H
#include "GameObject.h"

class ObjectManager{
	public:
		static void Load();
		static void Update();
		static GameObject* NewGameObject(char* name);

	private:
		static GameObject** gameObjects;
		static int numObjects;
};

#endif