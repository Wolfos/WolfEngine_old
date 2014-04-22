#ifndef _INPUT_H
#define _INPUT_H
#include "Keys.h"
#include "../Models/Point.h"
#include "../Includes.h"

///
/// Handles all input
///
class Input{
	public:
		static Keys keys; /// What keys are currently being pressed?
		static Point mousePosition;
		static int mouseKeyDown;
		void Update(SDL_Event * eventHandler); 
};
#endif