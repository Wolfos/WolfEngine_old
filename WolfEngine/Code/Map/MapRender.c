#include "MapRender.h"

SDL_Rect* clip;

void MapRender(SDL_Surface* target, struct Map* map, int layer, SDL_Surface* spritesheet, 
	int tilewidth, int tileheight, int offset, Camera camera)
{

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

	if (((camera.x + camera.w) / tilewidth) + 1 <= map->width)endX = ((camera.x + camera.w) / tilewidth) + 1;
	else endX = map->width;

	if (((camera.y + camera.h) / tileheight) + 1 <= map->height)endY = ((camera.y + camera.h) / tileheight) + 1;
	else endY = map->height;

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
		//Skip over the tiles we're not rendering
		i += startX; 
		i += map->width - endX;
	}

	//SDL_BlitSurface(spritesheet,NULL,target,NULL);

	free(clip);
}
