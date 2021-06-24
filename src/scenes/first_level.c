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
	SDLX_Sprite			bottom_ui;

	SDLX_button			pause;
	SDL_bool			paused_hint;
	SDL_bool			paused;

	SDLX_button			lmenu_resume;
	SDLX_button			lmenu_selectscene;

	SDLX_Sprite			crosshair;

	t_player			player;

	t_enemy				slime;

	SDL_Texture			*pbackground;
}				t_firt_level;

void	*first_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_firt_level *scene;

	context->close_fn = first_level_close;
	context->update_fn = first_level_update;

	scene = new_scene(sizeof(*scene), context, ASSETS"level_one.png");

	scene->bottom_ui = SDLX_Sprite_Static(ASSETS"bottom_ui.png");
	scene->bottom_ui.dst = SDLX_NULL_SELF;
	scene->bottom_ui._dst = (SDL_Rect){0, (320 - 16 * 5), 256, 16 * 5};

	SDLX_Button_Init(&(scene->pause), fetch_ui_sprite, PAUSE_NORM, (SDL_Rect){256 - 21, 5, 16, 16}, NULL);
	scene->pause.trigger_fn = button_pause;
	scene->pause.meta = &(scene->paused_hint);

	SDLX_Button_Init(&(scene->lmenu_resume), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 150, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->lmenu_resume), BACK_NORM, BACK_HOVER);
	scene->lmenu_resume.meta = &(scene->paused);
	scene->lmenu_resume.meta1 = &(scene->pbackground);
	scene->lmenu_resume.trigger_fn = button_resume;

	SDLX_Button_Init(&(scene->lmenu_selectscene), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 200, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->lmenu_selectscene), BACK_NORM, BACK_HOVER);
	scene->lmenu_selectscene.meta = context;
	scene->lmenu_selectscene.meta1 = level_select_init;
	scene->lmenu_selectscene.trigger_fn = button_trigger_scene_switch;

	player_init(&(scene->player));

	scene->crosshair = SDLX_Sprite_Static(ASSETS"crosshair.png");
	scene->crosshair.dst = &(scene->crosshair._dst);
	scene->crosshair._dst = (SDL_Rect){130, 100, 32, 32};
	scene->crosshair.center = &(scene->crosshair._center);
	scene->crosshair._center.x = 0;
	scene->crosshair._center.y = 64;
	scene->crosshair.angle = 0;


	scene->slime.sprite = SDLX_Sprite_Static(ASSETS"slime.png");
	scene->slime.sprite.dst = SDLX_NULL_SELF;
	scene->slime.sprite._dst = (SDL_Rect){10, 10, 32, 32};

	scene->slime.enemy_hurtbox.originator = &(scene->slime);
	scene->slime.enemy_hurtbox.detect_meta1 = &(scene->slime.sprite._dst);
	scene->slime.enemy_hurtbox.engage_meta1 = &(scene->slime);
	scene->slime.enemy_hurtbox.type = SLIMES;
	scene->slime.enemy_hurtbox.detect = slime_detect_collision;
	scene->slime.enemy_hurtbox.engage = slime_collide;

	scene->slime.hp = 2;
	scene->slime.meta = (void *)1;

	scene->paused = SDL_FALSE;
	scene->paused_hint = SDL_FALSE;
	return (NULL);
}

void	*first_level_close(t_context *context, void *vp_scene)
{
	t_firt_level	*scene;

	scene = vp_scene;

	if (scene->pbackground != NULL)
		SDL_DestroyTexture(scene->pbackground);

	SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);
	SDL_free(context->background.sprite_data);
	SDL_free(scene->bottom_ui.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*first_level_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	size_t	i;
	t_firt_level	*scene;

	scene = vp_scene;

	if (scene->paused == SDL_FALSE)
	{
		SDLX_RenderQueue_Add(NULL, &(scene->bottom_ui));
		SDLX_Button_Update(&(scene->pause));

		scene->crosshair.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - 130, 140 - g_GameInput.GameInput.primary.y) * 180 / M_PI) - 45;
		SDLX_RenderQueue_Add(NULL, &(scene->crosshair));

		player_update(&(scene->player));
		projectile_update(&(scene->player.attacks));
		slime_update(&(scene->slime));

		i = 0;
		while (i < default_CollisionBucket.index)
		{
			SDLX_attempt_CollisionBucket(default_CollisionBucket.content[i], &(default_CollisionBucket));
			i++;
		}
		default_CollisionBucket.index = 0;
	}
	else
	{
		SDL_RenderCopy(SDLX_GetDisplay()->renderer, scene->pbackground, NULL, NULL);
		SDLX_Button_Update(&(scene->lmenu_resume));
		SDLX_Button_Update(&(scene->lmenu_selectscene));
	}

	if (scene->paused_hint == SDL_TRUE)
	{
		scene->pbackground = SDL_CreateTexture(SDLX_GetDisplay()->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, WIN_WIDTH, WIN_HEIGHT);
		SDL_SetRenderTarget(SDLX_GetDisplay()->renderer, scene->pbackground);

		SDL_RenderClear(SDLX_GetDisplay()->renderer);

		SDLX_Sprite *background;
		background = SDLX_get_background();
		SDLX_DrawAnimation(SDLX_GetDisplay()->renderer, background);

		SDLX_RenderQueue_Flush(NULL, NULL, SDL_FALSE);

		SDL_SetRenderTarget(SDLX_GetDisplay()->renderer, NULL);
		scene->paused = SDL_TRUE;
		scene->paused_hint = SDL_FALSE;
	}

	// SDL_Log("This: %p", text);

	// SDL_SetRenderDrawColor(SDLX_GetDisplay()->renderer, 100, 255, 100, 255);
	// SDL_Rect	playarea = {0, 0, 256 * 2, 256 * 2};
	// SDL_RenderDrawRect(SDLX_GetDisplay()->renderer, &(playarea));

	return (NULL);
}
