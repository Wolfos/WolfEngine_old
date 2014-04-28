#ifndef _GUIBOX_H
#define _GUIBOX_H
#include "../Models/Point.h"
#include "../ECS/GameObject.h"
class GUIBox
{
public:
	GUIBox(Point location, Point scale);
	~GUIBox();
private:
	GameObject* renderer;
};
#endif