#include "TilePicker.h"

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
	int mouseX = Input::mousePosition.x;
	int mouseY = Input::mousePosition.y;

	if (button->clicked)
	{
		int x = ((mouseX - gameObject->transform->position.x + 2) / (128 * zoom)) * 2;
		int y = ((mouseY - gameObject->transform->position.y + 2) / (128 * zoom)) * 2;
		printf("%d, %d \n", x, y);
		selected = x + (y*(tilesheetRect.w / 128));
	}
}

void TilePicker::LateUpdate()
{
	SDL_Rect destRect = { gameObject->transform->position.x + 2, gameObject->transform->position.y + 2, 252, 252 };
	SDL_RenderCopy(Screen::mainCamera->screen, tilesheet, &tilesheetRect, &destRect);
}