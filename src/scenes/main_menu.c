/***************************************************************************
 * FILENAME:    main_menu.c
 * DESCRIPTION: Mandles the main menu
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 03Jun2021
***************************************************************************/

#include "main.h"

typedef	struct	s_main_menu_scene
{
	SDLX_Sprite			background;
	SDLX_Sprite			tittle;
	SDLX_RenderQueue	*queue;

	SDLX_button	play;
}				t_main_menu_scene;

#define UI_ENLARGE (4)

void	*main_menu_init(t_context *context, SDL_UNUSED void *level)
{
	t_main_menu_scene *scene;

	scene = new_scene(sizeof(*scene), context, ASSETS"grove.png", main_menu_close, main_menu_update);

	scene->tittle = SDLX_Sprite_Static(ASSETS"tittle_c.png");
	scene->tittle._dst = (SDL_Rect){MID_PLAY_WIDTH - 132 - 5, 40, 264, 180};
	scene->tittle.dst = SDLX_NULL_SELF;

	SDLX_Button_Init(&(scene->play), fetch_ui_sprite, PLAY_NORM, (SDL_Rect){(PLAY_WIDTH - 23 * UI_ENLARGE) / 2, 275, 23 * UI_ENLARGE, 11 * UI_ENLARGE}, NULL);
	SDLX_Style_Button(&(scene->play), PLAY_NORM, PLAY_HOVER);
	scene->play.meta = context;
	scene->play.meta1 = level_select_init;
	scene->play.trigger_fn = button_trigger_scene_switch;

	return (NULL);
}

void	*main_menu_close(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_main_menu_scene *scene;

	scene = vp_scene;

	SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);
	SDL_free(context->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*main_menu_update(SDL_UNUSED t_context *context, void *vp_scene)
{
	t_main_menu_scene *scene;

	scene = vp_scene;

	SDLX_RenderQueue_Add(NULL, &(scene->tittle));
	SDLX_Button_Update(&(scene->play));

	return (NULL);
}
