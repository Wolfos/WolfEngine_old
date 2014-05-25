#include "Card.h"

void Card::Start()
{
	card = gameObject->GetComponent<SpriteRenderer>()->frame;
	gameObject->GetComponent<SpriteRenderer>()->frame = 0;
	width = gameObject->GetComponent<SpriteRenderer>()->width;
	height = gameObject->GetComponent<SpriteRenderer>()->height;
}

void Card::Reset()
{
	timer = 0;
	reset = true;
	selected = false;
}

void Card::Update()
{
	if (Input::mouseClick&&!checked&&!reset)
	{
		if (Input::mousePosition.x > gameObject->transform->position.x && Input::mousePosition.x < gameObject->transform->position.x + width*gameObject->transform->scale.x)
		{
			if (Input::mousePosition.y>gameObject->transform->position.y && Input::mousePosition.y < gameObject->transform->position.y + height*gameObject->transform->scale.y)
			{
				gameObject->GetComponent<SpriteRenderer>()->frame = card;
				selected = true;
			}
		}
	}
	if (reset)
	{
		timer+=Time::frameTimeS;
		if (timer >= 1)
		{
			gameObject->GetComponent<SpriteRenderer>()->frame = 0;
			timer = 0;
			reset = false;
		}
	}
}
