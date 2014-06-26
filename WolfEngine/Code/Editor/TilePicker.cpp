#include "TilePicker.h"

void TilePicker::Start()
{
	//Background
	guiBox = new GUIBox({ gameObject->transform->position.x, gameObject->transform->position.y }, { 256, 256 });

	//tileSheet = new GUISprite("Terrain.png", { gameObject->transform->position.x + 3, gameObject->transform->position.y + 3 }, { 250, 250 });
	tileSheet = Image::LoadSurface("Terrain.png");

	renderSheet = SDL_CreateRGBSurface(0, 1024, 1024, 32, NULL, NULL, NULL, NULL);

	guiSpriteSheet = new GUISprite(Image::ToTexture(renderSheet), { gameObject->transform->position.x + 3, gameObject->transform->position.y + 3 }, { 250, 250 });
}


void TilePicker::Update()
{
	SDL_Rect srcRect = { 0, 0, 1024, 1024 };
	SDL_Rect dstRect = { 0, 0, 1024, 1024 };
	SDL_BlitSurface(tileSheet, &srcRect, renderSheet, &dstRect);
	guiSpriteSheet->renderer->GetComponent<SpriteRenderer>()->spriteSheet = Image::ToTexture(renderSheet);
}