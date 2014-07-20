#include "GUIBox.h"
#include "../ECS/ObjectManager.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Image.h"
#include "../Rendering/Screen.h"
GUIBox::GUIBox(Point location, Point size)
{
	SDL_Texture* sprite = Image::Load("GUI/Box.png");
	int spritewidth, spriteheight;
	SDL_QueryTexture(sprite, 0, 0, &spritewidth, &spriteheight);

	renderer = ObjectManager::NewGameObject("Box");

	renderer->AddComponent<SpriteRenderer>();
	renderer->GetComponent<SpriteRenderer>()->spriteSheet = sprite;
	renderer->GetComponent<SpriteRenderer>()->frameWidth = spritewidth;
	renderer->GetComponent<SpriteRenderer>()->frameHeight = spriteheight;

	renderer->transform->position = location;
	renderer->transform->scale.x = (float)size.x / spritewidth;
	renderer->transform->scale.y = (float)size.y / spriteheight;
}

GUIBox::~GUIBox()
{
	ObjectManager::DeleteObject(renderer);
}