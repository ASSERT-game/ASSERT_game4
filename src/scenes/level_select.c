/***************************************************************************
 * FILENAME:    level_select.c
 * DESCRIPTION: Manages the level screen for Blaster.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 04Jun2021
***************************************************************************/

#include "main.h"

typedef	struct	s_level_select
{
	SDLX_Sprite			background;

	SDLX_button			back;

	SDLX_button			levels[5][5];
}				t_level_select;

void	*level_select_init(t_context *context, SDL_UNUSED void *level)
{
	t_level_select *scene;

	scene = new_scene(sizeof(*scene), context, ASSETS"level_select_background.png", level_select_close, level_select_update);

	size_t	i;
	size_t	j;
	int		x;
	int		y;
	int		left_offset;
	int		up_offset;
	int		tile_padding;

	left_offset = 30;
	up_offset = 50;
	tile_padding = 5;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			x = j * (32 + tile_padding) + left_offset;
			y = i * (32 + tile_padding) + up_offset;
			SDLX_Button_Init(&(scene->levels[i][j]), fetch_level_select_sprite, LOCK_NORM, (SDL_Rect){x, y, 32, 32}, NULL);
			SDLX_Style_Button(&(scene->levels[i][j]), LOCK_NORM, LOCK_HOVER);
			scene->levels[i][j].meta = context;
			if (context->levels[i][j].unlocked == SDL_TRUE)
			{
				SDLX_Style_Button(&(scene->levels[i][j]), (i * 5 + j + 4), (i * 5 + j + 4) * -1);
				scene->levels[i][j].meta1 = context->levels[i][j].init_fn;
				scene->levels[i][j].trigger_fn = button_trigger_scene_switch;
				scene->levels[i][j].sprite_fn(&(scene->levels[i][j].sprite.sprite_data), scene->levels[i][j].norm_no);

			}
			j++;
		}
		i++;
	}
	// SDLX_Style_Button(&(scene->levels[0][0]), 4, -4);
	scene->levels[0][0].sprite_fn(&(scene->levels[0][0].sprite.sprite_data), scene->levels[0][0].norm_no);

	SDLX_Button_Init(&(scene->back), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){50, 200, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->back), BACK_NORM, BACK_HOVER);
	scene->back.meta = context;
	scene->back.meta1 = main_menu_init;
	scene->back.trigger_fn = button_trigger_scene_switch;

	return (NULL);
}

void	*level_select_close(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;

	SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);
	SDL_free(context->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*level_select_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;

	// SDLX_Button_Update(&(scene->level_1));
	// SDLX_Button_Update(&(scene->level_2));
	// SDLX_Button_Update(&(scene->level_3));
	// SDLX_Button_Update(&(scene->level_4));
	// SDLX_Button_Update(&(scene->level_5));

	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			SDLX_Button_Update(&(scene->levels[i][j]));
			j++;
		}
		i++;
	}

	SDLX_Button_Update(&(scene->back));

	return (NULL);
}