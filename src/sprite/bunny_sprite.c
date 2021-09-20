/***************************************************************************
 * FILENAME:    level_sprite.c
 * DESCRIPTION: Handles the Sprites for bunnys
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 22Jun2021
***************************************************************************/

#include "main.h"

SDLX_Sprite_Data *carve_bunny_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(22, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"bunny_m.png");

	i = 0;
	while (i < 9)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * i, 0, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 120;
		i++;
	}
	result[i - 1].skip = -8;

	while (i < 4 + 8 + 1)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * (i - 8), 32, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 4;
		i++;
	}
	result[i - 1].skip = -11;

	size_t	jx;

	jx = 0;
	while (jx < 8)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * (jx), 64, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		i++;
		jx++;
	}
	result[i - 1].skip = -11 - 8;

	return (result);
}

int		fetch_bunny_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_bunny_sprite();

	if (no == 0)
		*dst = &(sprite_arr[0]);
	else if (no == 1)
		*dst = &(sprite_arr[8]);
	else if (no == 2)
		*dst = &(sprite_arr[14]);


	return (EXIT_SUCCESS);
}