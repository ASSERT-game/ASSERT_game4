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

SDLX_Sprite_Data *carve_level_select_sprite(void)
{
	size_t				i;
	size_t				j;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(50, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"level_select.png");

	i = 0;
	j = 0;
	while (j < 20)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * (j % 5), 32 * (j / 5), 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 1;
		i++;

		result[i].texture = texture;
		result[i]._src = (SDL_Rect){32 * (j % 5), 32 * (j / 5) + 8 * 16, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 1;
		i++;

		j++;
	}

	/* The Lock Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 19 * 16, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){32, 19 * 16, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Frame */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 16 * 16, 36, 39};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	j = 0;
	while (j < 6)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){36 + (j * 36), 16 * 16, 36, 39};
		result[i].src = &(result[i]._src);
		result[i].cycle = 6;
		i++;

		j++;
	}


	return (result);
}

int		fetch_level_select_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_level_select_sprite();

	// else if (no == -100)	{ (*dst) = &(sprite_arr[5]); return (EXIT_SUCCESS); }

	if (no == LOCK_NORM)		{ (*dst) = &(sprite_arr[40]); return (EXIT_SUCCESS); }
	else if (no == LOCK_HOVER)	{ (*dst) = &(sprite_arr[41]); return (EXIT_SUCCESS); }
	else if (no == INCO_FRAME)	{ (*dst) = &(sprite_arr[42]); return (EXIT_SUCCESS); }
	else if (no == COMP_FRAME)	{ (*dst) = &(sprite_arr[43]); return (EXIT_SUCCESS); }
	else if (no >> 8 == 6)
	{
		no ^= (6 << 8);
		(*dst) = &(sprite_arr[no * 2 + 1]); return (EXIT_SUCCESS);
	}
	else
	{
		(*dst) = &(sprite_arr[no * 2]); return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}