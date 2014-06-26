#ifndef _GUISPRITE_H
#define _GUISPRITE_H

#include "../Includes.h"
#include "../Models/Point.h"
#include "../ECS/GameObject.h"
///
/// Simple GUI Sprite object
///
class GUISprite
{
public:
	GUISprite(char* filename, Point location, Point size);
	GUISprite(SDL_Texture* image, Point location, Point size);
	~GUISprite();
	GameObject* renderer;
};

#endif