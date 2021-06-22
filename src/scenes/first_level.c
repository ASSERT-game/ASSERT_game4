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

	SDLX_button			pause;

	SDLX_Sprite			crosshair;

	t_bullet			bullet;

	t_player			player;

	t_enemy				slime;
}				t_firt_level;

void	*first_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_firt_level *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	context->scene = SDL_TRUE;

	scene->background = SDLX_Sprite_Static(ASSETS"level_one.png");
	SDLX_set_background(&(scene->background));

	SDLX_Button_Init(&(scene->pause), fetch_ui_sprite, PAUSE_NORM, (SDL_Rect){256 - 21, 5, 16, 16}, NULL);

	player_init(&(scene->player));

	scene->crosshair = SDLX_Sprite_Static(ASSETS"crosshair.png");
	scene->crosshair.dst = &(scene->crosshair._dst);
	scene->crosshair._dst = (SDL_Rect){130, 100, 32, 32};
	scene->crosshair.center = &(scene->crosshair._center);
	scene->crosshair._center.x = 0;
	scene->crosshair._center.y = 64;
	scene->crosshair.angle = 0;

	context->close_fn = first_level_close;
	context->update_fn = first_level_update;

	scene->slime.sprite = SDLX_Sprite_Static(ASSETS"slime.png");
	scene->slime.sprite.dst = SDLX_NULL_SELF;
	scene->slime.sprite._dst = (SDL_Rect){10, 10, 32, 32};

	scene->slime.enemy_hurtbox.originator = &(scene->slime);
	scene->slime.enemy_hurtbox.detect_meta1 = &(scene->slime.sprite._dst);
	scene->slime.enemy_hurtbox.engage_meta1 = &(scene->slime);
	scene->slime.enemy_hurtbox.type = SLIMES;
	scene->slime.enemy_hurtbox.detect = slime_detect_collision;
	scene->slime.enemy_hurtbox.engage = slime_collide;

	scene->slime.hp = 5;
	scene->slime.meta = (void *)1;

	return (NULL);
}

void	*first_level_close(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_firt_level	*scene;

	scene = vp_scene;
	SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);

	SDL_free(scene->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*first_level_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_firt_level	*scene;

	scene = vp_scene;

	slime_update(&(scene->slime));

	scene->crosshair.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - 130, 140 - g_GameInput.GameInput.primary.y) * 180 / M_PI) - 45;

	projectile_update(&(scene->player.attacks));
	SDLX_RenderQueue_add(NULL, &(scene->slime.sprite));
	player_update(&(scene->player));
	SDLX_RenderQueue_add(NULL, &(scene->crosshair));

	SDLX_Button_Update(&(scene->pause));

	size_t	i = 0;

	while (i < default_CollisionBucket.index)
	{
		SDLX_attempt_CollisionBucket(default_CollisionBucket.content[i], &(default_CollisionBucket));
		i++;
	}
	default_CollisionBucket.index = 0;

	// SDL_SetRenderDrawColor(SDLX_GetDisplay()->renderer, 100, 255, 100, 255);
	// SDL_Rect	playarea = {0, 0, 256 * 2, 256 * 2};
	// SDL_RenderDrawRect(SDLX_GetDisplay()->renderer, &(playarea));

	return (NULL);
}
