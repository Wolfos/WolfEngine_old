#include "MapRender.h"

SDL_Surface* Render(struct Map* map, int layer, SDL_Surface* spritesheet, int tilewidth, int tileheight, int offset)
{
    SDL_Surface* target = malloc(sizeof(SDL_Surface*));
    SDL_Rect sourcerect;
    SDL_Rect targetrect;
	int x, y, i;
	SDL_Rect* clip;
	int sheetwidth;
	int sheetheight;

	sheetwidth = spritesheet->clip_rect.w/tilewidth;
	sheetheight = spritesheet->clip_rect.h/tileheight;

	clip = calloc(sheetwidth*sheetheight,sizeof(SDL_Rect*));

    i = 0;
    //Clip contains the position of each possible tile
    for(x = 0; x<sheetwidth; x++)
    {
        for(y = 0; y<sheetheight; y++)
        {
            clip[i].x = x*tilewidth+(offset*x);
            clip[i].y = y*tileheight+(offset*y);
            clip[i].w = tilewidth;
            clip[i].h = tileheight;
            i++;
        }
    }

	sourcerect.w = tilewidth;
	sourcerect.h = tileheight;
	targetrect.w = tilewidth;
	targetrect.h = tileheight;

    i = 0;
	for(x = 0; x<map->width;x++)
	{
		for(y = 0; y<map->height;y++)
		{
            targetrect.x = x*tilewidth;
            targetrect.y = x*tileheight;

            sourcerect.x = clip[map->data[i*layer]].x;
            sourcerect.y = clip[map->data[i*layer]].y;

            SDL_BlitSurface(spritesheet,&sourcerect,target,&targetrect);

            i++;
		}
	}

	return target;
}
