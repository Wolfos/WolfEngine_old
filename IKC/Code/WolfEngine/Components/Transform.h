#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "../ECS/Component.h"
#include "../Models/Point.h"
class Transform : public Component
{
public:
	Point position;
	PointF scale;
	void Move(int x, int y);
	double angle = 0;
	virtual void Start();
	virtual void Update();
};
#endif