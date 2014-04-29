/*
WolfEngine © 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "Music.h"

Music::Music(char* filename)
{
#ifdef ANDROID
	char newFilename[1024] = "Audio/";
#else
	char newFilename[1024] = "../Assets/Audio/";
#endif
	strcat(newFilename, filename);
	music = Mix_LoadMUS(newFilename);
	if (!music)
	{
		printf("Unable to load audio file %s! SDL_Mixer Error: %s\n", newFilename, Mix_GetError());
	}
}

void Music::Play(int loop)
{
	Mix_PlayMusic(music, loop);
}

void Music::Stop()
{
	Mix_HaltMusic();
}
Music::~Music()
{
	Mix_HaltMusic();
	Mix_FreeMusic(music);
}
