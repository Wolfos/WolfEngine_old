#ifndef _MUSIC_H
#define _MUSIC_H
#include "../Includes.h"
///
/// For playing music
/// Music is streamed but only one can be played at the same time
/// For sounds that can be played at the same time, see Sound
///
class Music
{
public:
	Music(char* filename);
	void Play(int loop = 0);
	void Stop();
	~Music();
private:
	Mix_Music* music;
};
#endif