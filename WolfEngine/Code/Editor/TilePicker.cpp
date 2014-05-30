#include "TilePicker.h"

void TilePicker::Start()
{
	//Background
	guiBox = new GUIBox({ gameObject->transform->position.x, gameObject->transform->position.y }, { 256, 256 });

	tileSheet = gameObject->AddComponent<SpriteRenderer>();
	tileSheet->Load("Terrain.png");

	tileSheet->width = 240;
	tileSheet->height = 240;
	tileSheet->layer = 30;
}

void TilePicker::Update()
{

}