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

	result = SDL_calloc(14, sizeof(*result));
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

	return (result);
}

int		fetch_slime_sprite(SDLX_Sprite_Data **dst, SDL_UNUSED int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_slime_sprite();

	*dst = &(sprite_arr[0]);

	return (EXIT_SUCCESS);
}