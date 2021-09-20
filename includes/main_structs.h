/***************************************************************************
 * FILENAME:    main_structs.h
 * DESCRIPTION: Struts used in Blaster.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jun2021
***************************************************************************/

#ifndef MAIN_STRUCTS_H
# define MAIN_STRUCTS_H

# include "SDLX/SDLX.h"
# include "waves.h"
# include "entity.h"

struct s_context;

typedef void *(t_scene_fn)(struct s_context *, void *);

typedef struct	s_level_progress
{
	SDL_bool	isUnlocked;
	SDL_bool	wasReceived;
	t_scene_fn	*init_fn;

	t_weapon	treasure_w;
}				t_level_progress;

typedef struct	s_context
{
	SDL_bool	shouldQuit;
	SDL_bool	shouldChange;

	void		*meta;

	SDLX_Sprite	background;
	SDL_Texture	*capture_texture;
	t_scene_fn	*redo_init_fn;
	t_scene_fn	*next_init_fn;
	size_t		wave_id;

	t_scene_fn	*init_fn;
	t_scene_fn	*update_fn;
	t_scene_fn	*close_fn;

	t_weapon	mainhand;
	t_weapon	offhand;
	t_weapon	defense;
	t_weapon	special;

	TTF_Font	*font;
	TTF_Font	*font_outline;

	t_level_progress	levels[5][5];

	int			level;
	int			score;
	int			time;
	int			killed;
	int			out_of;

	SDL_Texture	*post_process;
	SDL_bool	hit;
	SDL_bool	timer;
}				t_context;

typedef struct	s_pmenu
{
	SDLX_Sprite	background;

	SDLX_button	resume;
	SDLX_button	redo;
	SDLX_button	menu;
}				t_pmenu;

typedef struct	s_text
{
	SDL_Color	color;
	double		scale;
	size_t		message_length;
	char		*message;
	char		*set;
	SDLX_Sprite	sprite;

	TTF_Font	*set_font;
}				t_text;

typedef struct	s_level
{
	SDLX_button			pause;
	t_pmenu				pause_menu;

	SDLX_Sprite			bottom_ui;
	SDLX_button			mainhand, offhand, defense, special;

	t_player			player;
	SDLX_Sprite			crosshair;

	t_wave_m			stage;
	t_enemy_m			enemies;

	SDL_Texture			*pbackground;

	size_t				score;
	size_t				time;
	t_text				enemies_killed_text;
	t_text				enemies_killed_text_outline;
	int					enemy_count;
}				t_level;

#endif