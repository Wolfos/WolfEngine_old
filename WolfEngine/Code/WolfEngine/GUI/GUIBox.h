#ifndef _GUIBOX_H
#define _GUIBOX_H
#include "../Models/Point.h"
#include "../ECS/GameObject.h"
///
/// Simple GUI box object
///
class GUIBox
{
public:
	GUIBox(Point location, Point size);
	~GUIBox();
	GameObject* renderer;
};
#endif