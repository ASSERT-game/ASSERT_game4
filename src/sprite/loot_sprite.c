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

SDLX_Sprite_Data *carve_loot_sprite(void)
{
	size_t				i;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(16, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"loot_scene.png");

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

	/* The Back Button */
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

	/* The Next Button */
	size_t jx = 0;
	while (jx < 6)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){64 + jx * 32, 0, 32, 32};
		result[i].src = &(result[i]._src);
		result[i].cycle = 6;
		i++;
		jx++;
	}

	result[i].texture = texture;
	result[i]._src = (SDL_Rect){64, 32, 32, 32};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Inventory Button */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 48, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){16, 48, 16, 16};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Background */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 64, 64, 64};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	/* The Death Background */
	result[i].texture = texture;
	result[i]._src = (SDL_Rect){0, 128, 64, 80};
	result[i].src = &(result[i]._src);
	result[i].cycle = 1;
	i++;

	return (result);
}

int		fetch_loot_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_loot_sprite();

	if (no == LMENU_NORM)		{ (*dst) = &(sprite_arr[0]); return (EXIT_SUCCESS); }
	else if (no == LMENU_HOVER)	{ (*dst) = &(sprite_arr[1]); return (EXIT_SUCCESS); }
	else if (no == LREDO_NORM)	{ (*dst) = &(sprite_arr[2]); return (EXIT_SUCCESS); }
	else if (no == LREDO_HOVER)	{ (*dst) = &(sprite_arr[3]); return (EXIT_SUCCESS); }
	else if (no == LNEXT_NORM)	{ (*dst) = &(sprite_arr[4]); return (EXIT_SUCCESS); }
	else if (no == LNEXT_HOVER)	{ (*dst) = &(sprite_arr[5 + 5]); return (EXIT_SUCCESS); }
	else if (no == LBACK_UI)	{ (*dst) = &(sprite_arr[8 + 5]); return (EXIT_SUCCESS); }
	else if (no == DBACK_UI)	{ (*dst) = &(sprite_arr[9 + 5]); return (EXIT_SUCCESS); }
	else { return (EXIT_FAILURE); }
}