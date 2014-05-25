#ifndef _COMPONENT_H
#define _COMPONENT_H

class GameObject;

///	The baseclass for components
class Component
{
	public:
		///	Runs when a component is first added to a GameObject
		virtual void Start() = 0;
		///	Runs every frame
		virtual void Update() = 0;
		///	A pointer to the GameObject that contains this component
		GameObject* gameObject;
};
#endif