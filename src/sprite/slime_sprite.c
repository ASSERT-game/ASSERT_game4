/***************************************************************************
 * FILENAME:    level_sprite.c
 * DESCRIPTION: Handles the Sprites for slimes
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

SDLX_Sprite_Data *carve_slime_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(22, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"enemy/slime_blue.png");

	i = 0;
	while (i < 14)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * i, 0, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 14;
		i++;
	}

	size_t	jx;

	jx = 0;
	while (jx < 8)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * jx, 32, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		i++;
		jx++;
	}



	return (result);
}

int		fetch_slime_sprite(SDLX_Sprite_Data **dst, SDL_UNUSED int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_slime_sprite();

	if (no == 0) { *dst = &(sprite_arr[0]); }
	else if (no == 1) { *dst = &(sprite_arr[14]); }

	return (EXIT_SUCCESS);
}