#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "../ECS/Component.h"
#include "../Models/Point.h"
///
/// Transform component, handles position, scale and rotation
///	Added to each GameObject by default, can be accessed through gameObject->transform
///
class Transform : public Component
{
public:
	///	The position in pixels
	Point position;
	/// The scale, not in pixels
	PointF scale;
	/// Move by pixels
	void Move(int x, int y);
	///	Rotation by degrees
	double angle = 0;
	virtual void Start();
	virtual void Update();

};
#endif