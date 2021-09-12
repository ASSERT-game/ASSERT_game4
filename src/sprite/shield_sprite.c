/***************************************************************************
 * FILENAME:    shield_sprite.c
 * DESCRIPTION:
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

SDLX_Sprite_Data *carve_shield_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(3, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"weapons/shield.png");

	i = 0;

	/* The Cooldown Icon */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	/* The Treasure Icon */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){32, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Attack Sprite */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 32, 64, 64};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	return (result);
}

int		fetch_shield_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_shield_sprite();

	if (no == 0) { *dst = &(sprite_arr[0]); }
	else if (no == 1) { *dst = &(sprite_arr[1]); }
	else { *dst = &(sprite_arr[2]); }

	return (EXIT_SUCCESS);
}