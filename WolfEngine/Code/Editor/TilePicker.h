#ifndef _TILEPICKER_H
#define _TILEPICKER_H
#include "../WolfEngine/WolfEngine.h"

class TilePicker : public Component
{
	public:
		virtual void Added();
		virtual void Update();
		virtual void LateUpdate();
		int selected = 0;
	private:
		int tileWidth = 128;
		int tileHeight = 128;
		float zoom = 0.5f;
		SDL_Rect tilesheetRect;
		GUIBox* guiBox;
		SDL_Texture* tilesheet;
		Button* button;
};

#endif