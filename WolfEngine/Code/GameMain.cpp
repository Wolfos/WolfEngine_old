#include "GameMain.h"
#include "WolfEngine/WolfEngine.h"
#include "GameManager.h"
#include "MiniGames/Memory.h"
#include "MiniGames/MainMenu.h"

void GameMain::Start()
{
	GameManager::StartMiniGame<MainMenu>();
}

void GameMain::Update()
{
	GameManager::UpdateMiniGame();
}

void GameMain::Exit()
{
	GameManager::ExitMiniGame();
}
