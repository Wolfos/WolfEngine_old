#ifndef _TILEPICKER_H
#define _TILEPICKER_H
#include "../WolfEngine/WolfEngine.h"

class TilePicker : public Component
{
	public:
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		int selected = 0;
	private:
		float zoom = 0.4f;
		SDL_Rect tilesheetRect;
		GUIBox* guiBox;
		SDL_Texture* tilesheet;
		Button* button;
};

#endif