#define _CRT_SECURE_NO_DEPRECATE //MICROSOOOOOOOOFT!
#include "Sound.h"

Sound::Sound(char* filename)
{
	#ifdef ANDROID
		char newFilename[1024] = "Audio/";
	#else
		char newFilename[1024] = "../Assets/Audio/";
	#endif
	strcat(newFilename, filename);
	sound = Mix_LoadMUS(newFilename);
	if (!sound)
	{
		printf("Unable to load audio file %s! SDL_Mixer Error: %s\n", newFilename, Mix_GetError());
	}
}

void Sound::Play(int loop)
{
	Mix_PlayMusic(sound, loop);
}

void Sound::Stop()
{
	Mix_HaltMusic();
}
Sound::~Sound()
{
	Mix_HaltMusic();
	Mix_FreeMusic(sound);
}
