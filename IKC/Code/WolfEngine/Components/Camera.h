#ifndef _CAMERA_H
#define _CAMERA_H
#include "../ECS/Component.h"
#include "../Includes.h"
class Camera : public Component
{
public:
	SDL_Renderer* screen;
	int width = 0;
	int height = 0;
	SDL_Window* window;
	virtual void Start();
	virtual void Update();
};
#endif