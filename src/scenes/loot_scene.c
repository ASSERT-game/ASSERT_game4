/***************************************************************************
 * FILENAME:    loot_scene.c
 * DESCRIPTION: Scene that displays upon winning a level.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 26Jun2021
***************************************************************************/

#include "main.h"

typedef struct	s_loot_scene
{
	SDLX_button	restart;
	SDLX_button	level_select;
	SDLX_button	next;

	SDLX_button	chest;

	SDLX_Sprite background;
	SDL_Texture	*level_capture;

	t_text level;
	t_text score;
	t_text time;
	t_text killed;

	int		score_at;
	int		time_at;
	int		killed_at;

	t_level_progress	*won;
}				t_loot_scene;

void	*loot_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_loot_scene	*scene;
	size_t			y_offset;

	y_offset = 25;
	scene = new_scene(sizeof(*scene), context, NULL, loot_level_close, loot_level_update);

	SDLX_Button_Init(&(scene->level_select), fetch_loot_sprite, LMENU_NORM, (SDL_Rect){(PLAY_WIDTH - 64) / 2 - 75, 232 + 16, 64, 64}, NULL);
	SDLX_Style_Button(&(scene->level_select), LMENU_NORM, LMENU_HOVER);
	scene->level_select.trigger_fn = button_trigger_scene_switch;
	scene->level_select.meta = context;
	scene->level_select.meta1 = level_select_init;

	SDLX_Button_Init(&(scene->restart), fetch_loot_sprite, LREDO_NORM, (SDL_Rect){(PLAY_WIDTH - 64) / 2, 232 + 16, 64, 64}, NULL);
	SDLX_Style_Button(&(scene->restart), LREDO_NORM, LREDO_HOVER);
	scene->restart.trigger_fn = button_trigger_scene_switch;
	scene->restart.meta = context;
	scene->restart.meta1 = context->redo_init_fn;

	SDLX_Button_Init(&(scene->next), fetch_loot_sprite, LNEXT_NORM, (SDL_Rect){(PLAY_WIDTH - 64) / 2 + 75, 232 + 16, 64, 64}, NULL);
	SDLX_Style_Button(&(scene->next), LNEXT_NORM, LNEXT_HOVER);
	scene->next.trigger_fn = button_trigger_scene_switch;
	scene->next.meta = context;
	scene->next.meta1 = context->next_init_fn;

	SDLX_new_Sprite(&(scene->background));
	fetch_loot_sprite(&(scene->background.sprite_data), LBACK_UI);
	scene->background._dst = (SDL_Rect){(PLAY_WIDTH - 64 * 3) / 2, 80 + y_offset, 64 * 3, 64 * 3};
	scene->background.dst = SDLX_NULL_SELF;

	SDLX_Button_Init(&(scene->chest), fetch_chest_sprite, 0, (SDL_Rect){(PLAY_WIDTH - 124) / 2, 20, 124, 124}, NULL);
	SDLX_Style_Button(&(scene->chest), 0, 1);
	scene->chest.trigger_fn = button_chest;
	scene->chest.update_fn = button_chest_update;
	// scene->chest.trigger_box = scene->background._dst;

	SDLX_Sprite		*treasure;
	size_t	wave_id;

	wave_id = context->wave_id;

	treasure = &(context->levels[wave_id / 5][wave_id % 5].treasure_w.treasure_sprite);
	treasure->dst = SDLX_NULL_SELF;
	treasure->_dst = (SDL_Rect){(PLAY_WIDTH - 80) / 2, 60, 32, 32};
	scene->chest.meta = treasure;

	if (context->next_init_fn == NULL)
	{
		scene->next.isDisabled = SDL_TRUE;
		fetch_ui_sprite(&(scene->next.sprite.sprite_data), EMPTY_UI);

		scene->level_select.sprite._dst.x =	MID_PLAY_WIDTH + 50;
		scene->restart.sprite._dst.x =		MID_PLAY_WIDTH - 50;
	}

	if (context->levels[wave_id / 5][wave_id % 5].wasReceived == SDL_TRUE ||
		context->levels[wave_id / 5][wave_id % 5].treasure_w.factory == NULL)
	{
		scene->chest.isDisabled = SDL_TRUE;
		scene->chest.sprite._dst.y = 0;
		scene->chest.isTriggered = SDL_TRUE;
	}

	context->levels[wave_id / 5][wave_id % 5].wasReceived = SDL_TRUE;
	context->wave_id = 0;


	char	buff[256];

	SDL_snprintf(buff, sizeof(buff), "Level %d", context->level);
	scene->score_at = 0;
	scene->time_at = 0;
	scene->killed_at = 0;
	create_text(&(scene->level),  0xFFFFFF00, (SDL_Rect){115, 132 + 0, 0, 0},   buff, .15, context->font);
	create_text(&(scene->score),  0xFFFFFF00, (SDL_Rect){83,  132 + 30, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);
	create_text(&(scene->time),   0xFFFFFF00, (SDL_Rect){83,  132 + 60, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);
	create_text(&(scene->killed), 0xFFFFFF00, (SDL_Rect){83,  132 + 90, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);


		 if (context->mainhand.factory == NULL && context->levels[wave_id / 5][wave_id % 5].treasure_w.type & B_MAINHAND) { context->mainhand = context->levels[wave_id / 5][wave_id % 5].treasure_w; }
	else if (context->defense.factory == NULL && context->levels[wave_id / 5][wave_id % 5].treasure_w.type & B_DEFENSE) { context->defense = context->levels[wave_id / 5][wave_id % 5].treasure_w; }
	else if (context->offhand.factory == NULL && context->levels[wave_id / 5][wave_id % 5].treasure_w.type & B_OFFHAND) { context->offhand = context->levels[wave_id / 5][wave_id % 5].treasure_w; }
	else if (context->special.factory == NULL && context->levels[wave_id / 5][wave_id % 5].treasure_w.type & B_SPECIAL) { context->special = context->levels[wave_id / 5][wave_id % 5].treasure_w; }

	if (context->levels[wave_id / 5][wave_id % 5].treasure_w.factory == faser_cannon().factory) { context->mainhand = context->levels[wave_id / 5][wave_id % 5].treasure_w; }

	return (NULL);
}

void	*loot_level_close(SDL_UNUSED t_context *context, SDL_UNUSED void *vp_scene)
{
	// t_loot_scene	*scene;

	// scene = vp_scene;
	SDLX_RenderQueue_Flush(NULL, NULL, SDL_FALSE);

	SDL_RenderCopy(SDLX_GetDisplay()->renderer, context->capture_texture, NULL, NULL);
	SDL_DestroyTexture(context->capture_texture);
	context->capture_texture = NULL;
	context->redo_init_fn = NULL;

	return (NULL);
}

void	*loot_level_update(SDL_UNUSED t_context *context, SDL_UNUSED void *vp_scene)
{
	t_loot_scene	*scene;
	char			buff[30];

	scene = vp_scene;

	SDL_RenderCopy(SDLX_GetDisplay()->renderer, context->capture_texture, NULL, NULL);
	SDLX_Button_Update(&(scene->chest));

	if (scene->chest.isTriggered == SDL_TRUE)
	{
		SDLX_Button_Update(&(scene->restart));
		SDLX_Button_Update(&(scene->level_select));
		SDLX_Button_Update(&(scene->next));

		if (scene->score_at < context->score) { scene->score_at++; }
		if (scene->score_at + 10 < context->score) { scene->score_at += 10; }
		if (scene->time_at < context->time) { scene->time_at++; }
		if (scene->time_at + 10 < context->time) { scene->time_at += 10; }
		if (scene->killed_at < context->killed) { scene->killed_at++; }

		if (g_GameInput.GameInput.button_primleft && SDL_PointInRect(&(g_GameInput.GameInput.primary), &(scene->background._dst)))
		{
			scene->score_at = context->score;
			scene->time_at = context->time;
			scene->killed_at = context->killed;
		}
	}
	else
	{
		SDLX_RenderQueue_Add(NULL, &(scene->restart.sprite));
		SDLX_RenderQueue_Add(NULL, &(scene->level_select.sprite));
		SDLX_RenderQueue_Add(NULL, &(scene->next.sprite));
		// scene->next.sprite.current--;
	}

	SDLX_RenderQueue_Add(NULL, &(scene->level.sprite));
	// SDL_Log("This %d", context->score);

	SDL_snprintf(buff, sizeof(buff), "Score  %7d", scene->score_at);
	scene->score.set = buff;
	update_text(&(scene->score), sizeof(buff));

	SDL_snprintf(buff, sizeof(buff), "Time   %7d", scene->time_at);
	scene->time.set = buff;
	update_text(&(scene->time), sizeof(buff));

	if (context->out_of >= 100)
		SDL_snprintf(buff, sizeof(buff), "Killed %3d/%d", scene->killed_at, context->out_of);
	else
		SDL_snprintf(buff, sizeof(buff), "Killed %4d/%d", scene->killed_at, context->out_of);
	scene->killed.set = buff;
	update_text(&(scene->killed), sizeof(buff));

	SDLX_RenderQueue_Add(NULL, &(scene->score.sprite));
	SDLX_RenderQueue_Add(NULL, &(scene->time.sprite));
	SDLX_RenderQueue_Add(NULL, &(scene->killed.sprite));


	SDLX_RenderQueue_Add(NULL, &(scene->background));

	return (NULL);
}
