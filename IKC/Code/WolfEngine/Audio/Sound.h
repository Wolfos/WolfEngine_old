#ifndef _SOUND_H
#define _SOUND_H
#include "../Includes.h"
///
/// For playing sound effects
/// Not streamed but many can be played at the same time
/// For streamed audio, see Music
///
class Sound
{
public:
	Sound(char* filename);
	void Play(int loop = 0);
	void Stop();
	~Sound();
private:
	Mix_Chunk* sound;
	int channel;
};
#endif