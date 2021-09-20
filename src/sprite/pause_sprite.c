/***************************************************************************
 * FILENAME:    level_sprite.c
 * DESCRIPTION: Handles the Sprites for pause menu
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

SDLX_Sprite_Data *carve_pause_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(7, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"pause.png");

	i = 0;

	/* The Menu Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){32, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Restart Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){64, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){64 + 32, 0, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Play Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 32, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){32, 32, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Background menu */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 64, 64, 64 + 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;



	return (result);
}

int		fetch_pause_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_pause_sprite();

	if 		(no == MMENU_NORM)	{ (*dst) = &(sprite_arr[0]); return (EXIT_SUCCESS); }
	else if (no == MMENU_HOVER)	{ (*dst) = &(sprite_arr[1]); return (EXIT_SUCCESS); }
	else if (no == MREDO_NORM)	{ (*dst) = &(sprite_arr[2]); return (EXIT_SUCCESS); }
	else if (no == MREDO_HOVER)	{ (*dst) = &(sprite_arr[3]); return (EXIT_SUCCESS); }
	else if (no == MPLAY_NORM)	{ (*dst) = &(sprite_arr[4]); return (EXIT_SUCCESS); }
	else if (no == MPLAY_HOVER)	{ (*dst) = &(sprite_arr[5]); return (EXIT_SUCCESS); }
	else if (no == MBACK)	{ (*dst) = &(sprite_arr[6]); return (EXIT_SUCCESS); }
	else { return (EXIT_FAILURE); }
}