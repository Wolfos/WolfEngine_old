#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H
#include "GameObject.h"
#include "../Includes.h"
#include <vector>

///
///	Static class that manages all GameObjects
///
class ObjectManager{
	public:
		/// Static, updates all GameObjects that have been registered with the ObjectManager
		static void Update();
		/// Static, looks for SpriteRenderer components and calls their Render() function in order by layer
		static void Render();
		/// Cleans up after itself by destroying all GameObjects
		static void Exit();
		///	Returns a new GameObject with a transform component attached
		static GameObject* NewGameObject(char* name);
		///	Deletes a GameObject
		static void DeleteObject(GameObject* object);

	private:
		static std::vector<GameObject*> gameObjects;
};

#endif