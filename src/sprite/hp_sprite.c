/***************************************************************************
 * FILENAME:    level_sprite.c
 * DESCRIPTION: Handles the Sprites for level buttons
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

SDLX_Sprite_Data *carve_hp_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(20, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"hp.png");

	i = 0;
	/* The HP */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Loss HP */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 16, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16, 16, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	while (i < 20)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 4) * 16, 32, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 16;
		i++;
	}

	return (result);
}

int		fetch_hp_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_hp_sprite();

	if (no == 1)		{ (*dst) = &(sprite_arr[0]); return (EXIT_SUCCESS); }
	else if (no == 1)	{ (*dst) = &(sprite_arr[1]); return (EXIT_SUCCESS); }
	else if (no == -1)	{ (*dst) = &(sprite_arr[2]); return (EXIT_SUCCESS); }
	else if (no == -2)	{ (*dst) = &(sprite_arr[3]); return (EXIT_SUCCESS); }
	else if (no == 3)	{ (*dst) = &(sprite_arr[4]); return (EXIT_SUCCESS); }
	else { return (EXIT_FAILURE); }
}