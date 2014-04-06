#include "GameMain.h"
#include "../Includes.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"
#include "../Rendering/Screen.h"
#include "../Input/Input.h"
#include "../Utilities/Time.h"
#include "../Includes/ECS.h"
#include "../Components/CameraMovement.h"
#include "../Components/SpriteRenderer.h"

SDL_Surface* spritesheet;
GameObject* camera;

GameObject* test;

//TTF_Font* testFont = NULL;

Map map;

//Called only once when the game starts
void GameMain::Start()
{
	map.Load("../Maps/map.WolfMap");
	spritesheet = Image::Load("../Sprites/tiles_spritesheet.png", Screen::mainCamera->screen->format);

	camera = ObjectManager::NewGameObject("Camera");
	camera->transform->scale.x = Screen::mainCamera->screen->w;
	camera->transform->scale.y = Screen::mainCamera->screen->h;

	camera->AddComponent<CameraMovement>();

	Screen::mainCamera->gameObject->AddComponent<CameraMovement>();

	test = ObjectManager::NewGameObject("Test");
	test->AddComponent<SpriteRenderer>();
	test->GetComponent<SpriteRenderer>()->spriteSheet = spritesheet;
	test->GetComponent<SpriteRenderer>()->width = 70;
	test->GetComponent<SpriteRenderer>()->height = 70;
	test->GetComponent<SpriteRenderer>()->frame = 0;
}

///
/// The game's main loop
///
void GameMain::Update()
{

	//map.Render(Screen::mainCamera->screen, 0, spritesheet, 70, 70, 2, camera);
	//SDL_BlitSurface(test->GetComponent<SpriteRenderer>()->spriteSheet, 0, Screen::mainCamera->screen, 0);
	
}
void GameMain::Exit()
{

}
