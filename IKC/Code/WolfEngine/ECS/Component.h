#ifndef _COMPONENT_H
#define _COMPONENT_H

class GameObject;

class Component
{
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;
		GameObject* gameObject;
};
#endif