/*
WolfEngine © 2013-2014 Robin van Ee
http://wolfengine.net
Contact:
rvanee@wolfengine.net
*/
#include "SpriteRenderer.h"
#include "../Rendering/Screen.h"
#include "../ECS/GameObject.h"
#include "../Utilities/Debug.h"
#include "../Rendering/Image.h"

void SpriteRenderer::Start()
{
	center = new SDL_Point;
}

void SpriteRenderer::Update()
{
	if (layer >= Screen::layers)
	{
		Screen::layers = layer + 1;
	}
}

void SpriteRenderer::Render()
{
	SDL_Rect* rect = new SDL_Rect;
	rect->w = width;
	rect->h = height;

	SDL_QueryTexture(spriteSheet, 0, 0, &sheetwidth, &sheetheight);
	if(width != 0) sheetwidth /= width;
	if(height != 0) sheetheight /= height;

	clip = (SDL_Rect*)calloc((sheetwidth*sheetheight) + 2 * sheetwidth, sizeof(SDL_Rect));

	int i = 0;
	for (int y = 0; y <= sheetheight; y++)
	{
		for (int x = 0; x<sheetwidth; x++)
		{
			clip[i].x = x*width + (sheetOffset*x);
			clip[i].y = y*height + (sheetOffset*y);
			clip[i].w = width;
			clip[i].h = height;
			i++;
		}
	}
	rect->x = clip[frame].x;
	rect->y = clip[frame].y;

	SDL_Rect* dst = new SDL_Rect;
	dst->x = gameObject->transform->position.x - Screen::mainCamera->gameObject->transform->position.x;
	dst->y = gameObject->transform->position.y - Screen::mainCamera->gameObject->transform->position.y;
	dst->w = (int)(width*gameObject->transform->scale.x);
	dst->h = (int)(height*gameObject->transform->scale.y);

	center->x = (int)((width*gameObject->transform->scale.x) / 2);
	center->y = (int)((width*gameObject->transform->scale.y) / 2);

	SDL_RenderCopyEx(Screen::mainCamera->screen, spriteSheet, rect, dst, gameObject->transform->angle, center, SDL_FLIP_NONE);
	free(clip);
	delete(dst);
	delete(rect);
}


void SpriteRenderer::Load(std::string filename)
{
	spriteSheet = Image::Load(filename);
}