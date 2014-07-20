#include "Button.h"
#include "../ECS/GameObject.h"
#include "../Models/Point.h"
#include "../Input/Input.h"

void Button::Start()
{
	transform = gameObject->GetComponent<Transform>();
	renderer = gameObject->GetComponent<SpriteRenderer>();

	if (!renderer) throw "No SpriteRenderer is present on the GameObject";
	if (!renderer) //Seriously, there is no spriterenderer present

	hitBox = { transform->position.x, 
		transform->position.y, 
		transform->position.x + renderer->frameWidth * transform->scale.x, 
		transform->position.y + renderer->frameHeight * transform->scale.y 
	};
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
	if (Collide({ Input::mousePosition.x, Input::mousePosition.y }, hitBox) && Input::mouseClick)
	{
		clicked = true;
	}
	else
	{
		clicked = false;
	}
}