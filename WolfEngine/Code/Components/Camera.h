#ifndef _CAMERA_H
#define _CAMERA_H
#include "../ECS/Component.h"
#include "../Includes.h"
class Camera : public Component
{
public:
	SDL_Surface* screen;
	int width = 0;
	int height = 0;
	virtual void Start();
	virtual void Update();
};
#endif