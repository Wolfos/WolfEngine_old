#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "MiniGames/MiniGame.h"

class GameManager{
private:
	static MiniGame* miniGame;
public:
	template <typename T>
	static void StartMiniGame()
	{
		if (miniGame)miniGame->Exit();
		miniGame = new T;
		miniGame->Start();
	}

	static void UpdateMiniGame();
	static void ExitMiniGame();
};

#endif
