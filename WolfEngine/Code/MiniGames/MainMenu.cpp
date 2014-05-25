#include "MainMenu.h"
#include "MainMenu\MenuItem.h"

void MainMenu::Start()
{
	background = Image::Load("MainMenu/Background.png");
	for (int i = 0; i < numGames; i++)
	{
		buttons.push_back(ObjectManager::NewGameObject("Button"));
		buttons[i]->AddComponent<SpriteRenderer>();
		buttons[i]->AddComponent<MenuItem>();
	}
}

void MainMenu::Update()
{
	SDL_RenderCopy(Screen::mainCamera->screen, background, 0, 0);
}

void MainMenu::Exit()
{
	SDL_DestroyTexture(background);
}