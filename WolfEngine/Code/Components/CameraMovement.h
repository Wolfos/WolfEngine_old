#ifndef _CAMERAMOVEMENT_H
#define _CAMERAMOVEMENT_H
#include "../ECS/Component.h"
#include "../Models/Point.h"
class CameraMovement : public Component
{
public:
	virtual void Start();
	virtual void Update();
};
#endif