#include "EditorMain.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"
#include "../Components/SpriteRenderer.h"
#include "../Components/Camera.h"


//Called only once when the editor starts
void EditorMain::Start()
{
	test = ObjectManager::NewGameObject("Test");
	test->AddComponent<SpriteRenderer>();
	test->GetComponent<SpriteRenderer>()->spriteSheet = Image::Load("../Sprites/tiles_spritesheet.png", editorScreen->format);
	test->GetComponent<SpriteRenderer>()->width = 70;
	test->GetComponent<SpriteRenderer>()->height = 70;
	test->GetComponent<SpriteRenderer>()->frame = 0;
}

///
/// The game's main loop
///
void EditorMain::Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(editorScreen, &editorScreen->clip_rect, 0);
}

void EditorMain::Exit()
{
	SDL_FreeSurface(editorScreen);
}

SDL_Surface* EditorMain::GetScreen()
{
	return editorScreen;
}

void EditorMain::SetScreen(SDL_Surface* source)
{
	editorScreen = source;
}
