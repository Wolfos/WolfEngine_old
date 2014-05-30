#ifndef _TILEPICKER_H
#define _TILEPICKER_H
#include "../WolfEngine/WolfEngine.h"

class TilePicker : public Component
{
	public:
		virtual void Start();
		virtual void Update();
	private:
		GUIBox* guiBox;
		SpriteRenderer* tileSheet;
};

#endif