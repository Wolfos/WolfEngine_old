#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "../Includes.h"
#include "Key.h"
#include "Keys.h"
#include <vector>

class Keyboard
{
public:
	static void Init();
	static bool KeyDown(int key);
	static bool KeyReleased(int key);
	static bool KeyClicked(int key);
	static void Update(SDL_Event* eventHandler);

	static std::vector<Key> keys;

private:
	static void Down(int key);
	static void Up(int key);
};

#endif