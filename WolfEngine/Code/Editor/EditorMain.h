#ifndef _EDITORMAIN_H
#define _EDITORMAIN_H

#include "../WolfEngine/WolfEngine.h"

class EditorMain
{
	public:
		void Start();
		void Update();
		void Exit();

	private:
		Map* map;
		SDL_Texture* spritesheet;
		GameObject* tilePicker;
		int tilewidth;
		int tileheight;
		bool dragging = false;
		Point initMousePos;
		Transform* camera;
};


#endif