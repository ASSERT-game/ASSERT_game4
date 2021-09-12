/***************************************************************************
 * FILENAME:    combo_sprite.c
 * DESCRIPTION: Fetches the combo sprites
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 02Sep2021
***************************************************************************/

#include "main.h"

SDLX_Sprite_Data *carve_combo_sprite(void)
{
	size_t				i;
	size_t				j;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(8 * 9, sizeof(*result));
	texture = SDLX_LoadTexture(ASSETS"combo.png");

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 8)
		{
			result[(i * 8) + j].texture = texture;
			result[(i * 8) + j]._src = (SDL_Rect){32 * j, 32 * i, 32, 32};
			result[(i * 8) + j].src = &(result[(i * 8) + j]._src);
			result[(i * 8) + j].cycle = 8;
			// result[(i * 8) + j].skip = 1;
			j++;
		}
		result[(i * 8) + j - 1].skip = 7;
		i++;
	}

	return (result);
}

int		fetch_combo_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_combo_sprite();

		 if (no == 2) { *dst = &(sprite_arr[0 * 8]); }
	else if (no == 3) { *dst = &(sprite_arr[1 * 8]); }
	else if (no == 4) { *dst = &(sprite_arr[2 * 8]); }
	else if (no == 5) { *dst = &(sprite_arr[3 * 8]); }
	else if (no == 6) { *dst = &(sprite_arr[4 * 8]); }
	else if (no == 7) { *dst = &(sprite_arr[5 * 8]); }
	else if (no == 8) { *dst = &(sprite_arr[6 * 8]); }
	else if (no == 9) { *dst = &(sprite_arr[7 * 8]); }
	else if (no >  9) { *dst = &(sprite_arr[8 * 8]); }
	else { return (EXIT_FAILURE); }

	return (EXIT_SUCCESS);
}