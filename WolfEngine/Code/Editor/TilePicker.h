#ifndef _TILEPICKER_H
#define _TILEPICKER_H
#include "../WolfEngine/WolfEngine.h"

class TilePicker : public Component
{
	public:
		virtual void Start();
		virtual void Update();
		int selected = 0;
	private:
		GUIBox* guiBox;
		SDL_Surface* tileSheet;
		SDL_Surface* renderSheet;
		SDL_Texture* texSheet;
		GUISprite* guiSpriteSheet;
		Button* button;
};

#endif