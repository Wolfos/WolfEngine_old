#include "Debug.h"
#ifdef __ANDROID__
	#include <android/log.h>
#else
	#include <stdio.h>
#endif
void Debug::Log(char* text, ...)
{
	#ifdef __ANDROID__
		__android_log_print(ANDROID_LOG_DEBUG, "WolfEngine", text);
	#else
		printf(text);
	#endif
}