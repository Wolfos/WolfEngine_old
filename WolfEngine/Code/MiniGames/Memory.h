#ifndef _MEMORY_H
#define _MEMORY_H
#include "MiniGame.h"
#include "../WolfEngine/WolfEngine.h"
class Memory : public MiniGame
{

private:
	SDL_Texture* spritesheet;
	int numCards = 15;
	GameObject** cards;
	Point cardSize;
	SDL_Texture* background;

public:
	virtual void Start();
	virtual void Update();
	virtual void Exit();
};
#endif