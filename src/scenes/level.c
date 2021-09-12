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

void	level_init(t_context *context, t_wave_m waves)
{
	t_level	*scene;

	scene = new_scene(sizeof(*scene), context, ASSETS"backdrop/level_one.png", level_close, level_update);

	scene->pbackground = NULL;

	level_ui_init(&(scene->pause), &(scene->bottom_ui));
	pause_menu_init(&(scene->pause_menu), &(scene->pause.isTriggered), &(scene->pbackground), context, context->init_fn);

	player_init(&(scene->player));
	crosshair_init(&(scene->crosshair));
	load_weapons(context, &(scene->player.weapon_equip), &(scene->mainhand), &(scene->offhand), &(scene->defense), &(scene->special));

	init_enemy_array(&(scene->enemies));
	scene->stage = waves;

	scene->score = 0;
	scene->time = 0;
	scene->enemy_count = wave_enemy_count(&(scene->stage));

	create_text(&(scene->enemies_killed_text), 0xFFFFFF00, (SDL_Rect){10, 16, 0, 0}, "1234567890", .15, context->font);
	create_text(&(scene->enemies_killed_text_outline), 0x5f873900, (SDL_Rect){10 - 1, 16, 0, 0}, "1234567890", .15, context->font_outline);

	/* check health containers and increase player health here */

}

void	*level_close(t_context *context, void *vp_scene)
{
	t_level	*scene;
	int		level_id;

	scene = vp_scene;
	context->redo_init_fn = context->init_fn;

	if (scene->player.hp <= 0) { context->init_fn = death_level_init; }
	else if (scene->stage.isComplete == SDL_TRUE)
	{
		context->init_fn = loot_level_init;

		level_id = scene->stage.wave_id;
		context->wave_id = scene->stage.wave_id;

		if (level_id <= 25)
		{
			level_id++;
			context->levels[level_id / 5][level_id % 5].isUnlocked = SDL_TRUE;
			context->next_init_fn = context->levels[level_id / 5][level_id % 5].init_fn;
		}
		else
			context->next_init_fn = NULL;
	}
	final_combos(&(context->mainhand.combo), &(context->offhand.combo), &(context->defense.combo), &(context->special.combo));
	update_combos(&(context->mainhand.combo), &(context->offhand.combo), &(context->defense.combo), &(context->special.combo), &(scene->score));

	context->level = scene->stage.wave_id + 1;
	context->score = scene->score;
	context->time = scene->time;
	context->killed = scene->stage.killed_no;
	context->out_of = scene->enemy_count;

	if (scene->pbackground != NULL) { SDL_DestroyTexture(scene->pbackground); }

	SDL_free(context->background.sprite_data);
	SDL_free(scene->bottom_ui.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*level_update(t_context *context, void *vp_scene)
{
	t_level		*scene;
	SDL_bool	wave_done;
	char	buff[10];


	scene = vp_scene;
	wave_done = SDL_FALSE;

	if (scene->pause.isTriggered == SDL_FALSE)
	{
		SDLX_RenderQueue_Add(NULL, &(scene->enemies_killed_text.sprite));
		SDLX_RenderQueue_Add(NULL, &(scene->enemies_killed_text_outline.sprite));
		SDLX_Button_Update(&(scene->pause));

		update_cooldowns(&(context->mainhand), &(context->offhand), &(context->defense), &(context->special));

		SDLX_Button_Update(&(scene->mainhand));
		SDLX_Button_Update(&(scene->special));
		SDLX_Button_Update(&(scene->offhand));
		SDLX_Button_Update(&(scene->defense));

		update_crosshair(&(scene->crosshair));
		SDLX_CollisionBucket_Flush(NULL);
		player_update(&(scene->player));

		update_combos(&(context->mainhand.combo), &(context->offhand.combo), &(context->defense.combo), &(context->special.combo), &(scene->score));

		SDLX_RenderQueue_Add(NULL, &(scene->bottom_ui));

		wave_done = wave_method(&(scene->stage), &(scene->enemies), &(scene->player.attacks));

		iter_enemies(&(scene->enemies));
		projectile_update(&(scene->player.attacks));

	}
	else
		update_pause_menu(&(scene->pause_menu), scene->pbackground);

	buff[0] = 'x';
	SDL_ultoa(scene->enemy_count - scene->stage.killed_no, buff + 1, 10);
	scene->enemies_killed_text.set = buff;
	scene->enemies_killed_text_outline.set = buff;

	update_text(&(scene->enemies_killed_text), sizeof(buff));
	update_text(&(scene->enemies_killed_text_outline), sizeof(buff));

	if (scene->pause.isTriggered == SDL_TRUE && scene->pbackground == NULL)
	{
		scene->pause.sprite_fn(&(scene->pause.sprite.sprite_data), EMPTY_UI);
		scene->pbackground = SDLX_CaptureScreen(NULL, 0, SDL_TRUE);
		scene->pause.sprite_fn(&(scene->pause.sprite.sprite_data), PAUSE_NORM);
	}

	if (scene->player.hp <= 0) { end_scene(context, &(scene->pause)); }
	if (wave_done) { scene->stage.isComplete = SDL_TRUE; end_scene(context, &(scene->pause)); }

	scene->time++;

	return (NULL);
}
