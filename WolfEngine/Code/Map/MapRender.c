#include "MapRender.h"

SDL_Surface* target = NULL;
SDL_Rect* clip;

void MapRender_Init(SDL_Surface* source)
{
	//Create a new surface for target
	target = SDL_CreateRGBSurface(0,source->w,source->h,source->format->BitsPerPixel,
		source->format->Rmask,source->format->Gmask,source->format->Bmask,source->format->Amask);
}

SDL_Surface* MapRender(struct Map* map, int layer, SDL_Surface* spritesheet, int tilewidth, int tileheight, int offset, Camera camera)
{
	//Fill target with black to clear it before rendering
	SDL_FillRect(target, &target->clip_rect, 0);

	//Tiles to start and finish render on
	int startX;
	int startY;
	int endX;
	int endY;

    SDL_Rect sourcerect;
    SDL_Rect targetrect;
	int x, y, i;
	
	int sheetwidth;
	int sheetheight;

	sheetwidth = spritesheet->clip_rect.w/tilewidth;
	sheetheight = spritesheet->clip_rect.h/tileheight;

	clip = calloc(sheetwidth*sheetheight,sizeof(SDL_Rect));

    i = 0;
    //Clip contains the position of each possible tile
	//X and Y are inverted because we read from left to right
    for(y = 0; y<sheetheight; y++)
    {
        for(x = 0; x<sheetwidth; x++)
        {
            clip[i].x = x*tilewidth+(offset*x);
            clip[i].y = y*tileheight+(offset*y);
            clip[i].w = tilewidth;
            clip[i].h = tileheight;
            i++;
        }
    }

	//printf("%d,%d\n",clip[1].x,clip[1].y);

	sourcerect.w = tilewidth;
	sourcerect.h = tileheight;
	targetrect.w = tilewidth;
	targetrect.h = tileheight;

	//Occlussion culling, but need to make sure we CAN cull first
	//If we can't cull (ergo, the map is too small or we're off the map), we just render the whole map
	if (camera.x >= 0)startX = camera.x/tilewidth;
	else startX = 0;

	if (camera.y >= 0)startY = camera.y/tileheight;
	else startY = 0;

	if ((camera.x + camera.w) / tilewidth <= map->width)endX = (camera.x + camera.w) / tilewidth;
	else endX = map->width;

	if ((camera.y + camera.h) / tileheight <= map->height)endY = (camera.y + camera.h) / tileheight;
	else endY = map->height;

	/*startX = 1;
	camera.x = tilewidth*startX;
	startY = 0;
	endX = map->width;
	endY = map->height;*/

    i = startX + startY * endY;
	for(y = startY; y<endY;y++)
	{
		for(x = startX; x<endX;x++)
		{
			targetrect.x = x*tilewidth - camera.x;
            targetrect.y = y*tileheight - camera.y;

            sourcerect.x = clip[map->data[i*(layer+1)]].x;
            sourcerect.y = clip[map->data[i*(layer+1)]].y;

            SDL_BlitSurface(spritesheet,&sourcerect,target,&targetrect);

			//i = x + y*endY;
			i++;
		}
		i += startX;
	}

	//SDL_BlitSurface(spritesheet,NULL,target,NULL);

	free(clip);

	return target;
}
