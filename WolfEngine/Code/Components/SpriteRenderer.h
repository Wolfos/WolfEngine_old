#ifndef _SPRITERENDERER_H
#define _SPRITERENDERER_H
#include "../ECS/Component.h"
#include "../Includes.h"
class SpriteRenderer : public Component
{
public:
	SDL_Surface* spriteSheet;
	char* filename;
	int width = 0;
	int height = 0;
	int frame = 0;
	int offset = 0;
	virtual void Start();
	virtual void Update();
};
#endif