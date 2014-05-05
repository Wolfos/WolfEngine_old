#include "GameMain.h"
#include "WolfEngine/WolfEngine.h"
#include "GameManager.h"
#include "MiniGames/Memory.h"

void GameMain::Start()
{
	GameManager::StartMiniGame<Memory>();
}

void GameMain::Update()
{
	GameManager::UpdateMiniGame();
}

void GameMain::Exit()
{
	GameManager::ExitMiniGame();
}
