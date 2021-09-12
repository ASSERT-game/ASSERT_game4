/***************************************************************************
 * FILENAME:    death_scene.c
 * DESCRIPTION: Scene that displays upon player death.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 24Jun2021
***************************************************************************/

#include "main.h"

typedef struct	s_death_scene
{
	SDLX_button		restart;
	SDLX_button		level_select;

	SDLX_Sprite		background;

	SDL_Texture		*death_capture;

	t_text level;
	t_text score;
	t_text time;
	t_text killed;

	int		score_at;
	int		time_at;
	int		killed_at;
}				t_death_scene;

void	*death_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_death_scene	*scene;

	scene = new_scene(sizeof(*scene), context, NULL, death_level_close, death_level_update);

	SDLX_Button_Init(&(scene->level_select), fetch_loot_sprite, LMENU_NORM, (SDL_Rect){(PLAY_WIDTH - 48) / 2 - 50, 232, 48, 48}, NULL);
	SDLX_Style_Button(&(scene->level_select), LMENU_NORM, LMENU_HOVER);
	scene->level_select.trigger_fn = button_trigger_scene_switch;
	scene->level_select.meta = context;
	scene->level_select.meta1 = level_select_init;

	SDLX_Button_Init(&(scene->restart), fetch_loot_sprite, LREDO_NORM, (SDL_Rect){(PLAY_WIDTH - 48) / 2 + 50, 232, 48, 48}, NULL);
	SDLX_Style_Button(&(scene->restart), LREDO_NORM, LREDO_HOVER);
	scene->restart.trigger_fn = button_trigger_scene_switch;
	scene->restart.meta = context;
	scene->restart.meta1 = context->redo_init_fn;

	SDLX_new_Sprite(&(scene->background));
	fetch_loot_sprite(&(scene->background.sprite_data), DBACK_UI);
	scene->background._dst = (SDL_Rect){(PLAY_WIDTH - 64 * 3) / 2, 80 - (16 * 3), 64 * 3, 80 * 3};
	scene->background.dst = SDLX_NULL_SELF;

	char	buff[256];

	SDL_snprintf(buff, sizeof(buff), "Level %d", context->level);
	scene->score_at = 0;
	scene->time_at = 0;
	scene->killed_at = 0;
	create_text(&(scene->level),  0xFFFFFF00, (SDL_Rect){115, 128 + 0, 0, 0},   buff, .15, context->font);
	create_text(&(scene->score),  0xFFFFFF00, (SDL_Rect){83,  122 + 30, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);
	create_text(&(scene->time),   0xFFFFFF00, (SDL_Rect){83,  122 + 60, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);
	create_text(&(scene->killed), 0xFFFFFF00, (SDL_Rect){83,  122 + 90, 0, 0}, "$$$$$$$$$$-1235789012345678901234567890", .15, context->font);

	return (NULL);
}

void	*death_level_close(t_context *context, SDL_UNUSED void *vp_scene)
{
	SDLX_RenderQueue_Flush(NULL, NULL, SDL_FALSE);

	SDL_RenderCopy(SDLX_GetDisplay()->renderer, context->capture_texture, NULL, NULL);
	SDL_DestroyTexture(context->capture_texture);
	context->capture_texture = NULL;
	context->redo_init_fn = NULL;

	return (NULL);
}

void	*death_level_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_death_scene	*scene;
	char			buff[30];

	scene = vp_scene;

	SDL_RenderCopy(SDLX_GetDisplay()->renderer, context->capture_texture, NULL, NULL);

	SDLX_Button_Update(&(scene->restart));
	SDLX_Button_Update(&(scene->level_select));

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

	SDLX_RenderQueue_Add(NULL, &(scene->level.sprite));
	SDLX_RenderQueue_Add(NULL, &(scene->score.sprite));
	SDLX_RenderQueue_Add(NULL, &(scene->time.sprite));
	SDLX_RenderQueue_Add(NULL, &(scene->killed.sprite));
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

	SDLX_RenderQueue_Add(NULL, &(scene->background));

	return (NULL);
}