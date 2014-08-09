#include "TilePicker.h"
#include <math.h>

void TilePicker::Added()
{
	//Background
	guiBox = new GUIBox({ gameObject->transform->position.x, gameObject->transform->position.y }, { 256, 256 });

	button = guiBox->renderer->AddComponent<Button>();

	//tileSheet = new GUISprite("Terrain.png", { gameObject->transform->position.x + 3, gameObject->transform->position.y + 3 }, { 250, 250 });
	tilesheet = Image::Load("Terrain.png");

	tilesheetRect.x = 0;
	tilesheetRect.y = 0;
	SDL_QueryTexture(tilesheet, NULL, NULL, &tilesheetRect.w, &tilesheetRect.h);

	tilesheetRect.w = tilesheetRect.w * zoom;
	tilesheetRect.h = tilesheetRect.w;
}


void TilePicker::Update()
{
	int mouseX = Input::mousePosition.x - gameObject->transform->position.x + 2;
	int mouseY = Input::mousePosition.y - gameObject->transform->position.y + 2;

	//Actual size of tiles on the screen
	int screentileWidth = tileWidth / (tilesheetRect.w / 252);
	int screentileHeight = tileHeight / (tilesheetRect.h / 252);

	if (button->clicked)
	{
		int x = floor(mouseX / screentileWidth);
		int y = floor(mouseY / screentileHeight);
		printf("%d, %d \n", x, y);
		selected = x + y * ((tilesheetRect.w / zoom)/tileWidth);
		printf("Selected: %d\n\n", selected);
	}
}

void TilePicker::LateUpdate()
{
	SDL_Rect destRect = { gameObject->transform->position.x + 2, gameObject->transform->position.y + 2, 252, 252 };
	SDL_RenderCopy(Screen::mainCamera->screen, tilesheet, &tilesheetRect, &destRect);
}