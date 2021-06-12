/***************************************************************************
 * FILENAME:    first_level.c
 * DESCRIPTION: The first level.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 11Jun2021
***************************************************************************/

#include "main.h"

typedef struct	s_firt_level
{
	SDLX_Sprite			background;
	SDLX_RenderQueue	*queue;

	SDLX_button			pause;

	SDLX_Sprite			player;
	SDLX_Sprite			crosshair;
}				t_firt_level;

void	*first_level_init(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_firt_level *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	context->scene = SDL_TRUE;

	scene->background = SDLX_Sprite_Static(ASSETS"level_one.png");
	SDLX_set_background(&(scene->background));
	scene->queue = &(context->queue);

	SDLX_Button_Init(&(scene->pause), fetch_ui_sprite, PAUSE_NORM, (SDL_Rect){256 - 21, 5, 16, 16}, scene->queue);

	scene->player = SDLX_Sprite_Static(ASSETS"bunny.png");
	scene->player.dst = &(scene->player._dst);
	scene->player._dst = (SDL_Rect){7 * 16, 7 * 16, 40, 40};
	scene->crosshair = SDLX_Sprite_Static(ASSETS"crosshair.png");
	scene->crosshair.dst = &(scene->crosshair._dst);
	scene->crosshair.dst = &(scene->crosshair._dst);
	scene->crosshair._dst = (SDL_Rect){130, 100, 40, 40};
	scene->crosshair.center = &(scene->crosshair._center);
	scene->crosshair._center.x = 0;
	scene->crosshair._center.y = 80;
	scene->crosshair.angle = 0;

	context->close_fn = first_level_close;
	context->update_fn = first_level_update;

	return (NULL);
}

void	*first_level_close(SDL_UNUSED t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_firt_level	*scene;

	scene = level;
	SDLX_RenderQueue_flush(scene->queue, SDLX_GetDisplay()->renderer);

	SDL_free(scene->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*first_level_update(SDL_UNUSED t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_firt_level	*scene;

	scene = level;

	SDLX_RenderQueue_add(scene->queue, &(scene->player));
	SDLX_RenderQueue_add(scene->queue, &(scene->crosshair));
	scene->crosshair.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - 130, 140 - g_GameInput.GameInput.primary.y) * 180 / M_PI) - 45;

	SDLX_Button_Update(&(scene->pause));

	return (NULL);
}
