#include "EditorMain.h"
#include "TilePicker.h"

void EditorMain::Start()
{
	GameObject* tilePicker = ObjectManager::NewGameObject("TilePicker");
	tilePicker->transform->position = { Screen::mainCamera->width - 256, 0 };
	tilePicker->AddComponent<TilePicker>();


}

void EditorMain::Update()
{

}

void EditorMain::Exit()
{

}