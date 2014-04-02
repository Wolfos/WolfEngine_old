#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "../ECS/Component.h"
class Transform : public Component
{
public:
	int x, y;
	void Move(int x, int y);
	virtual void Update();
};
#endif