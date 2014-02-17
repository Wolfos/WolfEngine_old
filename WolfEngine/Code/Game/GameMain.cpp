#include "../Includes.h"
#include "../Map/Map.h"
#include "../Rendering/Image.h"
#include "../Input/Input.h"

#include "../Scripting/ScriptMain.h"


SDL_Surface* screen = NULL;
SDL_Surface* spritesheet;
Camera camera;

Map map;

//Called only once when the game starts
void Game_Start()
{
	ScriptMain();
	map.Load("../Maps/Test.WolfMap");
	spritesheet = Image::Load("../Sprites/tiles_spritesheet.png",screen->format);
	camera.x = 0;
	camera.y = 0;
	camera.w = screen->w;
	camera.h = screen->h;
	//printf("%d",map->height);
}

///
/// The game's main loop
///
void Game_Update()
{
	//Fill screen with black to clear it before rendering
	SDL_FillRect(screen, &screen->clip_rect, 0);

	map.Render(screen, &map, 0, spritesheet, 70, 70, 2, camera);

	if (Input::keys.ArrowLeft)camera.x--;
	if (Input::keys.ArrowUp)camera.y--;
	if (Input::keys.ArrowDown)camera.y++;
	if (Input::keys.ArrowRight)camera.x++;
}

void Game_Exit()
{
    SDL_FreeSurface(screen);
}

SDL_Surface* Game_GetScreen()
{
	return screen;
}

void Game_SetScreen(SDL_Surface* source)
{
	screen = source;
}
