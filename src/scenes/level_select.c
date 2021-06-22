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

	SDLX_button			play;
}				t_level_select;

void	*level_select_init(t_context *context, SDL_UNUSED void *level)
{
	t_level_select *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	context->scene = SDL_TRUE;
	scene->background = SDLX_Sprite_Static(ASSETS"p8_level_select.png");
	SDLX_set_background(&(scene->background));

	SDLX_Button_Init(&(scene->play), fetch_ui_sprite, PLAY_NORM, (SDL_Rect){50, 10, 23 * 2, 11 * 2}, NULL);

	SDLX_Style_Button(&(scene->play), PLAY_NORM, PLAY_HOVER);
	SDLX_Button_Set_fn(&(scene->play), SDLX_Button_onHoverFocus, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn, button_trigger_scene_switch, SDLX_Button_NULL_fn);
	scene->play.meta1 = first_level_init;

	context->close_fn = level_select_close;
	context->update_fn = level_select_update;

	scene->play.meta = context;
	return (NULL);
}

void	*level_select_close(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;
	SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);

	SDL_free(scene->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*level_select_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_level_select *scene;

	scene = vp_scene;

	SDLX_Button_Update(&(scene->play));
	return (NULL);
}