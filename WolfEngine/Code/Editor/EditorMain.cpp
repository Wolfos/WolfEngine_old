#include "../Includes.h"
#include "../Rendering/Map.h"
#include "../Rendering/Image.h"

SDL_Surface* editorScreen = NULL;


//Called only once when the editor starts
void Editor_Start()
{

}

///
/// The game's main loop
///
void Editor_Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(editorScreen, &editorScreen->clip_rect, 0);

}

void Editor_Exit()
{
	SDL_FreeSurface(editorScreen);
}

SDL_Surface* Editor_GetScreen()
{
	return editorScreen;
}

void Editor_SetScreen(SDL_Surface* source)
{
	editorScreen = source;
}
