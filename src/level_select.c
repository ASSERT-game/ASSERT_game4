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
	SDLX_RenderQueue	*queue;

}				t_level_select;

void	*level_select_init(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	scene->background = SDLX_Sprite_Static(ASSETS"p8_level_select.png");
	SDLX_set_background(&(scene->background));
	scene->queue = &(context->queue);

	context->close_fn = level_select_close;
	context->update_fn = level_select_update;
	return (NULL);
}

void	*level_select_close(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = context->meta;
	SDLX_RenderQueue_flush(scene->queue, SDLX_GetDisplay()->renderer);

	SDL_free(scene);

	return (NULL);
}

void	*level_select_update(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_level_select *scene;

	scene = context->meta;
	return (NULL);
}