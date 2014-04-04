#include "../Includes.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"
#include "../Input/Input.h"
#include "../Utilities/Time.h"
#include "../Includes/ECS.h"
#include "../Components/CameraMovement.h"

SDL_Surface* gameScreen = NULL;
SDL_Surface* spritesheet;
GameObject* camera;

//TTF_Font* testFont = NULL;

Map map;

//Called only once when the game starts
void Game_Start()
{
	map.Load("../Maps/map.WolfMap");
	spritesheet = Image::Load("../Sprites/tiles_spritesheet.png", gameScreen->format);

	camera = ObjectManager::NewGameObject("Camera");
	camera->transform->scale.x = gameScreen->w;
	camera->transform->scale.y = gameScreen->h;

	CameraMovement* cMovement = (CameraMovement*)malloc(sizeof(CameraMovement*));
	cMovement = new CameraMovement;
	camera->AddComponent(cMovement);
}

///
/// The game's main loop
///
void Game_Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(gameScreen, &gameScreen->clip_rect, 0);

	map.Render(gameScreen, 0, spritesheet, 70, 70, 2, camera);

	
}

void Game_Exit()
{
	SDL_FreeSurface(gameScreen);
}

SDL_Surface* Game_GetScreen()
{
	return gameScreen;
}

void Game_SetScreen(SDL_Surface* source)
{
	gameScreen = source;
}
