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

	result = SDL_calloc(44, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"level_select.png");

	i = 0;
	/* The Lock Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16 * 2, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Back Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16 * 3, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16 * 4, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	j = 0;
	while (j < 20)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){16 * (j % 5), 16 * (j / 4) + 16, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 1;
		i++;

		result[i].texture = texture;
		result[i]._src = (SDL_Rect){16 * (j % 5), 16 * (j / 4) + (16 * 6), 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 1;
		i++;

		j++;
	}

	return (result);
}

int		fetch_level_select_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;
	int		which;

	if (sprite_arr == NULL)
		sprite_arr = carve_level_select_sprite();

	if (no == LOCK_NORM)		{ (*dst) = &(sprite_arr[0]); return (EXIT_SUCCESS); }
	else if (no == LOCK_HOVER)	{ (*dst) = &(sprite_arr[1]); return (EXIT_SUCCESS); }
	else if (no == BACK_NORM)	{ (*dst) = &(sprite_arr[2]); return (EXIT_SUCCESS); }
	else if (no == BACK_HOVER)	{ (*dst) = &(sprite_arr[3]); return (EXIT_SUCCESS); }
	else if (no == -100)	{ (*dst) = &(sprite_arr[5]); return (EXIT_SUCCESS); }
	else {
		which = (no - 4) * 2;
		if (no <= 0)
		{
			which = (no + 4) * -2;
			(*dst) = &(sprite_arr[which + 4 + 1]); return (EXIT_SUCCESS);
		}
		else
		{
			(*dst) = &(sprite_arr[which + 4]); return (EXIT_SUCCESS);
		}
	}
}