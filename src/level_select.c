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


void	*button_level_trigger(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t length)
{
	t_context *context;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		context = self->meta;

		context->init_fn = first_level_init;
		context->scene = SDL_FALSE;
	}

	return (NULL);
}

void	*level_select_init(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	context->scene = SDL_TRUE;
	scene->background = SDLX_Sprite_Static(ASSETS"p8_level_select.png");
	SDLX_set_background(&(scene->background));

	SDLX_Button_Init(&(scene->play), fetch_ui_sprite, PLAY_NORM, (SDL_Rect){50, 10, 23 * 2, 11 * 2}, NULL);

	SDLX_Style_Button(&(scene->play), PLAY_NORM, PLAY_HOVER);
	SDLX_Button_Set_fn(&(scene->play), SDLX_Button_onHoverFocus, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn, button_level_trigger, SDLX_Button_NULL_fn);

	context->close_fn = level_select_close;
	context->update_fn = level_select_update;

	scene->play.meta = context;
	return (NULL);
}

void	*level_select_close(SDL_UNUSED t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = level;
	SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);

	SDL_free(scene->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*level_select_update(SDL_UNUSED t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = level;

	SDLX_Button_Update(&(scene->play));
	return (NULL);
}