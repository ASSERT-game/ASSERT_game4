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

	t_bullet			bullet;
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
	scene->crosshair._dst = (SDL_Rect){130, 100, 40, 40};
	scene->crosshair.center = &(scene->crosshair._center);
	scene->crosshair._center.x = 0;
	scene->crosshair._center.y = 80;
	scene->crosshair.angle = 0;

	scene->bullet.fired = SDL_FALSE;
	scene->bullet.sprite = SDLX_Sprite_Static(ASSETS"laser.png");
	scene->bullet.sprite.dst = &(scene->bullet.sprite._dst);
	scene->bullet.sprite._dst = (SDL_Rect){130, 7 * 16 + 8, 16, 16};
	scene->bullet.sprite.center = &(scene->bullet.sprite._center);
	scene->bullet.sprite._center.x = 8;
	scene->bullet.sprite._center.y = 32;
	scene->bullet.sprite.angle = 0;

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

	if (scene->bullet.fired == SDL_FALSE)
		scene->bullet.sprite.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (scene->bullet.sprite._dst.x + 4), (scene->bullet.sprite._dst.y + 16) - g_GameInput.GameInput.primary.y) * 180 / M_PI);
	else
	{
		scene->bullet.sprite._dst.x += scene->bullet.vel.x;
		scene->bullet.sprite._dst.y += scene->bullet.vel.y;
	}

	double	angle;

	if (g_GameInput.GameInput.button_primleft == SDL_TRUE && scene->bullet.fired == SDL_FALSE)
	{
		scene->bullet.fired = SDL_TRUE;
		angle = SDL_atan2(g_GameInput.GameInput.primary.x - (scene->bullet.sprite._dst.x + 4), (scene->bullet.sprite._dst.y + 16) - g_GameInput.GameInput.primary.y);

		scene->bullet.vel.x = SDL_sin(angle) * 9;
		scene->bullet.vel.y = SDL_cos(angle) * -9;
	}

	SDL_Rect	play_area;
	SDL_Rect	b_real;

	play_area = (SDL_Rect){0, 0, 32 * 16, 32 * 16};
	b_real = scene->bullet.sprite._dst;

	b_real.x *= 2;
	b_real.y *= 2;
	b_real.w *= 2;
	b_real.h *= 2;

	if (SDL_HasIntersection(&(b_real), &(play_area)) == SDL_FALSE)
	{
		scene->bullet.fired = SDL_FALSE;
		scene->bullet.sprite._dst = (SDL_Rect){130, 7 * 16 + 8, 16, 16};
	}
	if (scene->bullet.fired)
		SDLX_RenderQueue_add(scene->queue, &(scene->bullet.sprite));

	SDLX_Button_Update(&(scene->pause));

	return (NULL);
}
