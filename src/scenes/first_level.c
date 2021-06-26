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

typedef struct	s_first_level
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
	int					score;

	SDL_Texture			*pbackground;
}				t_first_level;

void	*first_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_first_level	*scene;

	scene = new_scene(sizeof(*scene), context, ASSETS"level_one.png", first_level_close, first_level_update);
	scene->pbackground = NULL;
	scene->score = 0;

	scene->bottom_ui = SDLX_Sprite_Static(ASSETS"bottom_ui.png");
	scene->bottom_ui.dst = SDLX_NULL_SELF;
	scene->bottom_ui._dst = (SDL_Rect){0, (320 - 16 * 5), 256, 16 * 5};

	SDLX_Button_Init(&(scene->pause), fetch_ui_sprite, PAUSE_NORM, (SDL_Rect){256 - 24, 8, 16, 16}, NULL);
	scene->pause.trigger_fn = button_pause;
	scene->pause.meta = &(scene->paused_hint);

	SDLX_Button_Init(&(scene->lmenu_resume), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 150, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->lmenu_resume), BACK_NORM, BACK_HOVER);
	scene->lmenu_resume.trigger_fn = button_resume;
	scene->lmenu_resume.meta = &(scene->paused);
	scene->lmenu_resume.meta1 = &(scene->pbackground);

	SDLX_Button_Init(&(scene->lmenu_selectscene), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 200, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->lmenu_selectscene), BACK_NORM, BACK_HOVER);
	scene->lmenu_selectscene.trigger_fn = button_trigger_scene_switch;
	scene->lmenu_selectscene.meta = context;
	scene->lmenu_selectscene.meta1 = level_select_init;

	player_init(&(scene->player));
	scene->player.scene_end = &(context->scene);

	scene->crosshair = SDLX_Sprite_Static(ASSETS"crosshair.png");
	scene->crosshair.dst = &(scene->crosshair._dst);
	scene->crosshair._dst = (SDL_Rect){(256 / 2) - 32, 120 - 32, 64, 64};
	scene->crosshair.angle = 0;

	slime_init(&(scene->slime));
	scene->slime.enemy_hurtbox.engage_meta2 = &(scene->score);

	scene->paused = SDL_FALSE;
	scene->paused_hint = SDL_FALSE;
	return (NULL);
}

void	*first_level_close(t_context *context, void *vp_scene)
{
	t_first_level	*scene;

	scene = vp_scene;

	if (scene->pbackground != NULL)
		SDL_DestroyTexture(scene->pbackground);

	if (scene->player.hp <= 0)
	{
		context->redo_init_fn = context->init_fn;
		context->init_fn = death_level_init;
	}

	SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);
	SDL_free(context->background.sprite_data);
	SDL_free(scene->bottom_ui.sprite_data);
	SDL_free(scene);

	(void)context;
	return (NULL);
}

void	*first_level_update(t_context *context, void *vp_scene)
{
	size_t	i;
	t_first_level	*scene;

	scene = vp_scene;

	if (scene->paused == SDL_FALSE)
	{
		SDL_SetRenderDrawColor(SDLX_GetDisplay()->renderer, 255, 0, 0, 255);
		SDL_Rect	playarea = {16, 220 * DISPLAY_SCALE, lerp32(scene->player.hp / 100.0, 0, 480), 10};

		SDL_RenderFillRect(SDLX_GetDisplay()->renderer, &(playarea));

		SDLX_RenderQueue_Add(NULL, &(scene->bottom_ui));
		SDLX_Button_Update(&(scene->pause));

		scene->crosshair.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y) * 180 / M_PI) - 45;
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
		scene->pause.sprite_fn(&(scene->pause.sprite.sprite_data), EMPTY_UI);
		scene->pbackground = SDLX_CaptureScreen(NULL, 0, SDL_TRUE);
		scene->pause.sprite_fn(&(scene->pause.sprite.sprite_data), PAUSE_NORM);

		scene->paused_hint = SDL_FALSE;
		scene->paused = SDL_TRUE;
		SDL_Log("Kill count: %d", scene->score);
	}

	if (scene->player.hp <= 0)
	{
		int cap = default_RenderQueue.index;
		context->death_capture_sceen = SDLX_CaptureScreen(NULL, 0, SDL_TRUE);
		default_RenderQueue.index = cap;
	}

	if (scene->score == 42)
	{
		context->scene = SDL_FALSE;
		context->init_fn = loot_level_init;
	}
	// SDL_Log("This: %p", text);


	return (NULL);
}
