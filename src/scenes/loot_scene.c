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
	SDLX_button	inventory;

	SDLX_Sprite	chest;

	SDL_Texture	*level_capture;
}				t_loot_scene;

void	*loot_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_loot_scene	*scene;

	scene = new_scene(sizeof(*scene), context, NULL, loot_level_close, loot_level_update);

	SDLX_Button_Init(&(scene->restart), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 100, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->restart), BACK_NORM, BACK_HOVER);
	scene->restart.trigger_fn = button_trigger_scene_switch;
	scene->restart.meta = context;
	scene->restart.meta1 = context->redo_init_fn;

	SDLX_Button_Init(&(scene->level_select), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 200, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->level_select), BACK_NORM, BACK_HOVER);
	scene->level_select.trigger_fn = button_trigger_scene_switch;
	scene->level_select.meta = context;
	scene->level_select.meta1 = level_select_init;

	SDLX_Button_Init(&(scene->inventory), fetch_level_select_sprite, BACK_NORM, (SDL_Rect){100, 250, 32, 32}, NULL);
	SDLX_Style_Button(&(scene->inventory), BACK_NORM, BACK_HOVER);
	scene->inventory.trigger_fn = button_trigger_scene_switch;
	scene->inventory.meta = context;
	scene->inventory.meta1 = level_select_init;

	scene->chest = SDLX_Sprite_Static(ASSETS"loot.png");
	scene->chest.dst = SDLX_NULL_SELF;
	scene->chest._dst = (SDL_Rect){256 / 2 - 32, 32, 64, 64};

	return (NULL);
}

void	*loot_level_close(SDL_UNUSED t_context *context, SDL_UNUSED void *vp_scene)
{
	t_loot_scene	*scene;

	scene = vp_scene;
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

	scene = vp_scene;

	SDL_RenderCopy(SDLX_GetDisplay()->renderer, context->capture_texture, NULL, NULL);
	SDLX_RenderQueue_Add(NULL, &(scene->chest));

	SDLX_Button_Update(&(scene->restart));
	SDLX_Button_Update(&(scene->level_select));
	SDLX_Button_Update(&(scene->inventory));

	return (NULL);
}
