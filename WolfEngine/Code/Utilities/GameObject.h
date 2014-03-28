#include "Component.h"
class GameObject
{
	public:
		void Update();
		void Load();
		Component GetComponent(char* name);
		void AddComponent(Component component);

	private:
		Component* components;
		int numComponents;
};
