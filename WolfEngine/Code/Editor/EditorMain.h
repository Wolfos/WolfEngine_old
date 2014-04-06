#ifndef _EDITORMAIN_H
#define _EDITORMAIN_H
#include "../Includes.h"
#include "../Includes/ECS.h"
class EditorMain
{
	public:
		void Start();
		void Update();
		void Exit();
		SDL_Surface* GetScreen();
		void SetScreen(SDL_Surface* source);
	private:
		SDL_Surface* editorScreen = NULL;
		GameObject* test;
};
#endif