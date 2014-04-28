#include "GUIBox.h"
#include "../ECS/ObjectManager.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Image.h"
#include "../Rendering/Screen.h"
GUIBox::GUIBox(Point location, Point scale)
{
	SDL_Texture* sprite = Image::Load("GUI/Box.png", Screen::mainCamera->screen);
	int spritewidth, spriteheight;
	SDL_QueryTexture(sprite, 0, 0, &spritewidth, &spriteheight);

	renderer = ObjectManager::NewGameObject("Box");

	renderer->AddComponent<SpriteRenderer>();
	renderer->GetComponent<SpriteRenderer>()->spriteSheet = sprite;
	renderer->GetComponent<SpriteRenderer>()->width = spritewidth;
	renderer->GetComponent<SpriteRenderer>()->height = spriteheight;

	renderer->transform->position = location;
	renderer->transform->scale.x = (float)scale.x / spritewidth;
	renderer->transform->scale.y = (float) scale.y / spriteheight;
}

GUIBox::~GUIBox()
{
	ObjectManager::DeleteObject(renderer);
}