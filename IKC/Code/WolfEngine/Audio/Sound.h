#ifndef _SOUND_H
#define _SOUND_H
#include "../Includes.h"
class Sound
{
public:
	Sound(char* filename);
	void Play(int loop = 0);
	void Stop();
	~Sound();
private:
	Mix_Music* sound;
};
#endif