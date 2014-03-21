#ifndef _INPUT_H
#define _INPUT_H
#include "Keys.h"
#include "../Includes.h"

///
/// Handles all input
///
class Input{
	public:
		static Keys keys; /// What keys are currently being pressed?
		void Update(SDL_Event * eventHandler); 
};
#endif