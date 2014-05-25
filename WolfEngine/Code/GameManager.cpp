#include "GameManager.h"

MiniGame* GameManager::miniGame;

void GameManager::UpdateMiniGame()
{
	miniGame->Update();
}

void GameManager::ExitMiniGame()
{
	miniGame->Exit();
	delete miniGame;
}