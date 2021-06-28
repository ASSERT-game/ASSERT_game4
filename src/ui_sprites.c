/***************************************************************************
 * FILENAME:    ui_sprites.c
 * DESCRIPTION: The manager for cutting up the ui texture and managing
 * returning the location of ui sprites.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 03Jun2021
***************************************************************************/

#include "main.h"

SDLX_Sprite_Data *carve_ui_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(19, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"buttons.png");

	i = 0;

	/* The Ability Button */
	while (i < 5)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){i * 16 * 3, 16, 16 * 3, 16 * 3};
		result[i].src = &(result[i]._src);
		result[i].cycle = 5;

		i++;
	}
	result[i - 1].skip = 4;

	/* The Pause Button */
	while (i < 5 + 8)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 5) * 32, 16 * 4, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;

		i++;
	}

	/* The Play Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 16 * 6, 23, 11};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){23, 16 * 6, 23, 11};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Credits Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 16 * 6 + 11, 35, 11};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){35, 16 * 6 + 11, 35, 11};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Empty Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16, 0, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Ability Select Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 16 * 8, 48, 48};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	return (result);
}

int		fetch_ui_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_ui_sprite();

	if (no == PLAY_NORM)		{ (*dst) = &(sprite_arr[13]); return (EXIT_SUCCESS); }
	else if (no == PLAY_HOVER)	{ (*dst) = &(sprite_arr[14]); return (EXIT_SUCCESS); }
	else if (no == CREDIT_NORM)	{ (*dst) = &(sprite_arr[15]); return (EXIT_SUCCESS); }
	else if (no == CREDIT_HOVER){ (*dst) = &(sprite_arr[16]); return (EXIT_SUCCESS); }
	else if (no == PAUSE_NORM)	{ (*dst) = &(sprite_arr[5]); return (EXIT_SUCCESS); }
	else if (no == EMPTY_UI)	{ (*dst) = &(sprite_arr[17]); return (EXIT_SUCCESS); }
	else if (no == ABILITY)		{ (*dst) = &(sprite_arr[0]); return (EXIT_SUCCESS); }
	else if (no == ABILITY_SEL)	{ (*dst) = &(sprite_arr[18]); return (EXIT_SUCCESS); }
	else { return (EXIT_FAILURE); }
}