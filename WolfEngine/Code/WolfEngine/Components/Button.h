#ifndef _BUTTON_H
#define _BUTTON_H
#include "../ECS/Component.h"
#include "../Includes.h"
#include "Transform.h"
#include "SpriteRenderer.h"

///
///	Tells us when the entity is clicked
///
class Button : public Component
{
public:
	SDL_Rect hitBox;
	virtual void Start();
	virtual void Update();
	bool clicked = false;

private:
	Transform* transform;
	SpriteRenderer* renderer;
};
#endif