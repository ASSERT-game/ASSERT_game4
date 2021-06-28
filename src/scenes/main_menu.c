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
	SDLX_RenderQueue	*queue;

	SDLX_button	play;
	SDLX_button	credits;
}				t_main_menu_scene;

#define UI_ENLARGE (2)

void	*main_menu_init(t_context *context, SDL_UNUSED void *level)
{
	t_main_menu_scene *scene;

	scene = new_scene(sizeof(*scene), context, ASSETS"p8_main_menu_background.png", main_menu_close, main_menu_update);

	SDLX_Button_Init(&(scene->play), fetch_ui_sprite, PLAY_NORM, (SDL_Rect){50, 10, 23 * UI_ENLARGE, 11 * UI_ENLARGE}, NULL);
	SDLX_Style_Button(&(scene->play), PLAY_NORM, PLAY_HOVER);
	scene->play.meta = context;
	scene->play.meta1 = level_select_init;
	scene->play.trigger_fn = button_trigger_scene_switch;

	SDLX_Button_Init(&(scene->credits), fetch_ui_sprite, CREDIT_NORM, (SDL_Rect){50, 56, 35 * UI_ENLARGE, 11 * UI_ENLARGE}, NULL);
	SDLX_Style_Button(&(scene->credits), CREDIT_NORM, CREDIT_HOVER);

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

	SDLX_Button_Update(&(scene->play));
	SDLX_Button_Update(&(scene->credits));

	return (NULL);
}
