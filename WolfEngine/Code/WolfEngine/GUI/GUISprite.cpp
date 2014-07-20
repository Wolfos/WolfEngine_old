#include "GUISprite.h"
#include "../ECS/ObjectManager.h"
#include "../Components/SpriteRenderer.h"
#include "../Rendering/Image.h"
#include "../Rendering/Screen.h"
GUISprite::GUISprite(char* filename, Point location, Point size)
{
	SDL_Texture* sprite = Image::Load(filename);
	int spritewidth, spriteheight;
	SDL_QueryTexture(sprite, 0, 0, &spritewidth, &spriteheight);

	renderer = ObjectManager::NewGameObject(filename);

	renderer->AddComponent<SpriteRenderer>();
	renderer->GetComponent<SpriteRenderer>()->spriteSheet = sprite;
	renderer->GetComponent<SpriteRenderer>()->frameWidth = spritewidth;
	renderer->GetComponent<SpriteRenderer>()->frameHeight = spriteheight;

	renderer->transform->position = location;
	renderer->transform->scale.x = (float)size.x / spritewidth;
	renderer->transform->scale.y = (float)size.y / spriteheight;
}

GUISprite::GUISprite(SDL_Texture* image, Point location, Point size)
{
	int spritewidth, spriteheight;
	SDL_QueryTexture(image, 0, 0, &spritewidth, &spriteheight);

	renderer = ObjectManager::NewGameObject("GUI Sprite");
	
	renderer->AddComponent<SpriteRenderer>();
	renderer->GetComponent<SpriteRenderer>()->spriteSheet = image;
	renderer->GetComponent<SpriteRenderer>()->frameWidth = spritewidth;
	renderer->GetComponent<SpriteRenderer>()->frameHeight = spriteheight;

	renderer->transform->position = location;
	renderer->transform->scale.x = (float)size.x / spritewidth;
	renderer->transform->scale.y = (float)size.y / spriteheight;
}

GUISprite::~GUISprite()
{
	ObjectManager::DeleteObject(renderer);
}