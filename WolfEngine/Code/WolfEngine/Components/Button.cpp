#include "Button.h"
#include "../ECS/GameObject.h"
#include "../Models/Point.h"
#include "../Input/Input.h"

void Button::Added()
{
	transform = gameObject->GetComponent<Transform>();
	renderer = gameObject->GetComponent<SpriteRenderer>();

#ifndef __ANDROID__
	if (!renderer) throw "No SpriteRenderer is present on the GameObject";
#endif

	hitBox.x = transform->position.x;
	hitBox.y = transform->position.y;
	hitBox.w = renderer->frameWidth * transform->scale.x;
	hitBox.h = renderer->frameHeight * transform->scale.y;
}

bool Collide(Point point, SDL_Rect rect)
{
	if (point.x < rect.x) return false;
	if (point.y < rect.y) return false;
	if (point.x > rect.x + rect.w) return false;
	if (point.y > rect.y + rect.h) return false;

	return true;
}

void Button::Update()
{
	if (Input::mouseClick && Collide({ Input::mousePosition.x, Input::mousePosition.y }, hitBox))
	{
		clicked = true;
	}
	else
	{
		clicked = false;
	}
}