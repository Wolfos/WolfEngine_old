#ifndef _SPRITERENDERER_H
#define _SPRITERENDERER_H
#include "../ECS/Component.h"
#include "../Includes.h"
class SpriteRenderer : public Component
{
public:
	SDL_Texture* spriteSheet;
	char* filename;
	int width = 0;
	int height = 0;
	int frame = 0;
	int sheetOffset = 0;
	SDL_Point* center;
	virtual void Start();
	virtual void Update();
private:
	int sheetwidth, sheetheight;
	SDL_Rect* clip;
};
#endif