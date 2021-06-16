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

void	*button_play_trigger(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t length)
{
	t_context *context;

	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		context = self->meta;

		context->init_fn = level_select_init;
		context->scene = SDL_FALSE;
	}

	return (NULL);
}

#define UI_ENLARGE (2)

void	*main_menu_init(t_context *context, SDL_UNUSED void *level, SDL_UNUSED int tick)
{
	t_main_menu_scene *scene;

	scene = SDL_malloc(sizeof(*scene));
	context->meta = scene;
	context->scene = SDL_TRUE;
	scene->background = SDLX_Sprite_Static(ASSETS"p8_main_menu_background.png");
	SDLX_set_background(&(scene->background));

	SDLX_Button_Init(&(scene->play), fetch_ui_sprite, PLAY_NORM, (SDL_Rect){50, 10, 23 * UI_ENLARGE, 11 * UI_ENLARGE}, NULL);
	SDLX_Button_Init(&(scene->credits), fetch_ui_sprite, CREDIT_NORM, (SDL_Rect){50, 56, 35 * UI_ENLARGE, 11 * UI_ENLARGE}, NULL);

	SDLX_Style_Button(&(scene->play), PLAY_NORM, PLAY_HOVER);
	SDLX_Style_Button(&(scene->credits), CREDIT_NORM, CREDIT_HOVER);

	SDLX_Button_Set_fn(&(scene->play), SDLX_Button_onHoverFocus, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn, button_play_trigger, SDLX_Button_NULL_fn);
	SDLX_Button_Set_fn(&(scene->credits), SDLX_Button_onHoverFocus, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn, SDLX_Button_NULL_fn);

	scene->play.meta = context;
	return (NULL);
}

void	*main_menu_close(SDL_UNUSED t_context *context, void *level, SDL_UNUSED int tick)
{
	t_main_menu_scene *scene;

	scene = level;

	SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);

	SDL_free(scene->background.sprite_data);
	SDL_free(scene);

	return (NULL);
}

void	*main_menu_update(SDL_UNUSED t_context *context, void *level, SDL_UNUSED int tick)
{
	t_main_menu_scene *scene;

	scene = level;

	SDLX_Button_Update(&(scene->play));
	SDLX_Button_Update(&(scene->credits));

	return (NULL);
}
