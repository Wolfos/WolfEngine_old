#include "GameObject.h"
#include "stdlib.h"
#include "../Utilities/Debug.h"
void GameObject::Update()
{
	for(unsigned i = 0(); i!=components.bucket_count(); ++i)
	{
		for (auto local_it = components.begin(i); local_it != components.end(i); ++local_it)
		{
			local_it->second->Update();
		}
		
	}
}

void GameObject::Load()
{
	//Every GameObject gets a transform component
	Transform* t = (Transform*)malloc(sizeof(Transform*));
	t = new Transform;
	AddComponent(t);
	transform = GetComponent<Transform>();
	transform->position.x = 0;
	transform->position.y = 0;
}


void GameObject::AddComponent(Component* component)
{
	components[&typeid(*component)] = component;
	component->Start();
	component->gameObject = this;
}
