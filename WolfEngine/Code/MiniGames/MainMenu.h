#ifndef _MAINMENU_H
#define _MAINMENU_H
#include "MiniGame.h"
#include "../WolfEngine/WolfEngine.h"
#include <vector>
class MainMenu : public MiniGame
{
private:
	SDL_Texture* background;
	std::vector<GameObject*> buttons;
	int numGames = 4;
public:
	virtual void Start();
	virtual void Update();
	virtual void Exit();
};
#endif