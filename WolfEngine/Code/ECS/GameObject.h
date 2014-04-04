#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include "Component.h"
#include "../Components/Transform.h"
#include <typeinfo> 
#include<unordered_map>
class GameObject
{
	private:
		std::unordered_map<const std::type_info*, Component*> components;
	public:
		Transform* transform;
		void Update();
		void Load();
		template <typename T>
		T* GetComponent()
		{
			if (components.count(&typeid(T)) != 0)
			{
				return static_cast<T*>(components[&typeid(T)]);
			}
			else
			{
				return 0;
			}
		}
		void AddComponent(Component* component);

		char* name;

};
#endif