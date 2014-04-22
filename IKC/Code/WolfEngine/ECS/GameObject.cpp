#include "GameObject.h"
#include "stdlib.h"
#include "../Utilities/Debug.h"
void GameObject::Update()
{
	for(unsigned i = 0; i!=components.bucket_count(); ++i)
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
	AddComponent<Transform>();
	transform = GetComponent<Transform>();
	transform->position.x = 0;
	transform->position.y = 0;
}


