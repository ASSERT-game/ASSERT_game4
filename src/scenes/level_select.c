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

	SDLX_button			level_1;
	SDLX_button			level_2;
	SDLX_button			level_3;
	SDLX_button			level_4;
	SDLX_button			level_5;
}				t_level_select;

void	*level_select_init(t_context *context, SDL_UNUSED void *level)
{
	t_level_select *scene;

	context->close_fn = level_select_close;
	context->update_fn = level_select_update;

	scene = new_scene(sizeof(*scene), context, ASSETS"p8_level_select.png");

	SDLX_Button_Init(&(scene->level_1), fetch_level_select_sprite, 1, (SDL_Rect){50, 50, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->level_1), 1, -100);
	scene->level_1.meta = context;
	scene->level_1.meta1 = first_level_init;
	scene->level_1.trigger_fn = button_trigger_scene_switch;

	SDLX_Button_Init(&(scene->level_2), fetch_level_select_sprite, LOCK_NORM, (SDL_Rect){82, 50, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->level_2), LOCK_NORM, LOCK_HOVER);
	scene->level_2.meta = context;
	scene->level_2.meta1 = first_level_init;
	// scene->level_2.trigger_fn = button_trigger_scene_switch;

	return (NULL);
}

void	*level_select_close(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;

	SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer);
	SDL_free(context->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*level_select_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;

	SDLX_Button_Update(&(scene->level_1));
	SDLX_Button_Update(&(scene->level_2));
	// SDLX_Button_Update(&(scene->level_3));
	// SDLX_Button_Update(&(scene->level_4));
	// SDLX_Button_Update(&(scene->level_5));
	return (NULL);
}