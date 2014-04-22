#ifndef _COMPONENT_H
#define _COMPONENT_H

class GameObject;

class Component
{
	public:
		virtual void Start(void);
		virtual void Update(void);
		GameObject* gameObject;
};
#endif