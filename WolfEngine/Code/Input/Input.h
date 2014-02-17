#ifndef _INPUT_H
#define _INPUT_H
#include "Keys.h"
#include "../Includes.h"

class Input{
	public:
		static Keys keys;
		void Update(SDL_Event * eventHandler);
};
#endif