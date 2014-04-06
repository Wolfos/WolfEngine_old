#include "SpriteRenderer.h"
#include "../Rendering/Screen.h"
#include "../ECS/GameObject.h"
void SpriteRenderer::Start()
{
	
}

void SpriteRenderer::Update()
{
	SDL_Rect* rect = new SDL_Rect;
	rect->w = width;
	rect->h = height;

	int sheetwidth = spriteSheet->w / width;
	int sheetheight = spriteSheet->h / height;

	SDL_Rect* clip = (SDL_Rect*)calloc(sheetwidth*sheetheight, sizeof(SDL_Rect));

	int i = 0;
	for (int y = 0; y<sheetheight; y++)
	{
		for (int x = 0; x<sheetwidth; x++)
		{
			clip[i].w = width;
			clip[i].h = height;
			i++;
		}
	}

	rect->x = clip[frame].x;
	rect->y = clip[frame].y;

	SDL_Rect* dst = new SDL_Rect; //Destination rectangle
	dst->x = gameObject->GetComponent<Transform>()->position.x - Screen::mainCamera->gameObject->GetComponent<Transform>()->position.x;
	dst->y = gameObject->GetComponent<Transform>()->position.y - Screen::mainCamera->gameObject->GetComponent<Transform>()->position.y;

	SDL_BlitSurface(spriteSheet, rect, Screen::mainCamera->screen, dst);
}