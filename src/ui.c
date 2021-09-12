/***************************************************************************
 * FILENAME:    ui.c
 * DESCRIPTION: Handles the level to level ui
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 02Jul2021
***************************************************************************/

#include "main.h"

void	level_ui_init(SDLX_button *pause, SDLX_Sprite *bottom)
{
	*bottom = SDLX_Sprite_Static(ASSETS"bottom_ui.png");
	bottom->dst = SDLX_NULL_SELF;
	bottom->_dst = (SDL_Rect){0, PLAY_HEIGHT, PLAY_WIDTH, BOTTOM_UI};

	SDLX_Button_Init(pause, fetch_ui_sprite, PAUSE_NORM, (SDL_Rect){PLAY_WIDTH - 35, 6, 32, 32}, NULL);
	pause->trigger_fn = button_pause;
	pause->update_fn = button_pause_key;
}

#define MENU_SCALE (3)
#define MENU_LOFFSET (80)

void	pause_menu_init(t_pmenu *menu, void *pause_addr, void *pbackground, void *context, void *restart_fn)
{
	SDLX_new_Sprite(&(menu->background));
	fetch_pause_sprite(&(menu->background.sprite_data), MBACK);
	menu->background.dst = SDLX_NULL_SELF;
	menu->background._dst = (SDL_Rect){(PLAY_WIDTH - 64 * MENU_SCALE) / 2, 80, 64 * MENU_SCALE, 16 * 5 * MENU_SCALE};

	SDLX_Button_Init(&(menu->resume), fetch_pause_sprite, MPLAY_NORM, (SDL_Rect){(PLAY_WIDTH - 32 * MENU_SCALE) / 2, 170, 32 * MENU_SCALE, 32 * MENU_SCALE}, NULL);
	SDLX_Style_Button(&(menu->resume), MPLAY_NORM, MPLAY_HOVER);
	menu->resume.trigger_fn = button_resume;
	menu->resume.meta = pause_addr;
	menu->resume.meta1 = pbackground;

	SDLX_Button_Init(&(menu->redo), fetch_pause_sprite, MREDO_NORM, (SDL_Rect){MENU_LOFFSET, 285, 16 * MENU_SCALE, 16 * MENU_SCALE}, NULL);
	SDLX_Style_Button(&(menu->redo), MREDO_NORM, MREDO_HOVER);
	menu->redo.trigger_fn = button_trigger_scene_switch;
	menu->redo.meta = context;
	menu->redo.meta1 = restart_fn;

	SDLX_Button_Init(&(menu->menu), fetch_pause_sprite, MMENU_NORM, (SDL_Rect){PLAY_WIDTH - MENU_LOFFSET - 16 * MENU_SCALE, 285, 16 * MENU_SCALE, 16 * MENU_SCALE}, NULL);
	SDLX_Style_Button(&(menu->menu), MMENU_NORM, MMENU_HOVER);
	menu->menu.trigger_fn = button_trigger_scene_switch;
	menu->menu.meta = context;
	menu->menu.meta1 = level_select_init;
}

void	update_pause_menu(t_pmenu *menu, SDL_Texture *pbackground)
{
	SDL_RenderCopy(SDLX_GetDisplay()->renderer, pbackground, NULL, NULL);

	SDLX_Button_Update(&(menu->resume));
	SDLX_Button_Update(&(menu->redo));
	SDLX_Button_Update(&(menu->menu));
	SDLX_RenderQueue_Add(NULL, &(menu->background));
}