#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include "Component.h"
#include "../Components/Transform.h"
#include <typeinfo> 
#include <unordered_map>
class GameObject
{
	private:
		std::unordered_map<const std::type_info*, Component*> components;
	public:
		Transform* transform;
		char* name;
		int id;

		void Update();
		GameObject();
		~GameObject();

		template <typename C>
		C* GetComponent()
		{
			if (components.count(&typeid(C)) != 0)
			{
				return static_cast<C*>(components[&typeid(C)]);
			}
			else
			{
				return 0;
			}
		}

		template <typename C>
		C* AddComponent()
		{
			C* component = new C;
			components[&typeid(*component)] = component;
			component->gameObject = this;
			component->Start();
			return component;
		}

		template <typename C>
		void RemoveComponent()
		{
			if (components.count(&typeid(C)) != 0)
			{
				C* component = components[&typeid(C)];
				components.erase(component);
				free(component);
			}
		}


};
#endif