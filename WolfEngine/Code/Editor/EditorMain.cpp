#include "EditorMain.h"
#include "TilePicker.h"

void EditorMain::Start()
{
	spritesheet = Image::Load("Terrain.png");
	map = new Map(10, 10, 3);
	
	tilewidth = 128;
	tileheight = 128;

	tilePicker = ObjectManager::NewGameObject("TilePicker");
	tilePicker->transform->position = { Screen::mainCamera->width - 256, 0 };
	tilePicker->AddComponent<TilePicker>();

	camera = Screen::mainCamera->gameObject->transform;
}

void EditorMain::Update()
{
	int xMPos = (Input::mousePosition.x + camera->position.x) / tilewidth;
	int yMPos = (Input::mousePosition.y + camera->position.y) / tileheight;

	int selected = tilePicker->GetComponent<TilePicker>()->selected;

	map->Render(Screen::mainCamera->screen, 0, spritesheet, tilewidth, tileheight, 0, Screen::mainCamera->gameObject);
	map->Render(Screen::mainCamera->screen, 1, spritesheet, tilewidth, tileheight, 0, Screen::mainCamera->gameObject);
	map->Render(Screen::mainCamera->screen, 2, spritesheet, tilewidth, tileheight, 0, Screen::mainCamera->gameObject);

	if (Input::mouseClick)
	{
		map->Put(xMPos, yMPos, layer, selected);
	}

	if (Input::keys.A > 0) layer = 0;
	if (Input::keys.B > 0) layer = 1;
	if (Input::keys.C > 0) layer = 2;
}

void EditorMain::Exit()
{

}