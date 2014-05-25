#ifndef _INPUT_H
#define _INPUT_H
#include "Keys.h"
#include "../Models/Point.h"
#include "../Includes.h"

///
/// Static class that handles all input
///
class Input{
	public:
		/// What keys are currently being pressed?
		static Keys keys; 
		///	Current mouse position
		static Point mousePosition;
		///	Is a mouse key down?
		static int mouseKeyDown;
		///	Mouse key up, this frame
		static int mouseClick;
		///	Updates all the input variables
		void Update(SDL_Event * eventHandler); 
};
#endif