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

struct s_context;

typedef void *(t_scene_fn)(struct s_context *, void *);

typedef struct	s_level_progress
{
	SDL_bool	unlocked;
	t_scene_fn	*init_fn;
}				t_level_progress;

struct s_weapon;

typedef struct	s_context
{
	SDL_bool	exit;
	SDL_bool	scene;

	void		*meta;

	SDL_Texture	*death_capture_sceen;
	t_scene_fn	*redo_init_fn;

	t_level_progress	levels[5][5];

	SDLX_Sprite	background;

	t_scene_fn	*init_fn;
	t_scene_fn	*update_fn;
	t_scene_fn	*close_fn;

	struct s_weapon	*weapons;
}				t_context;

enum	BLASTER_UI_SPRITES
{
	PLAY_NORM,
	PLAY_HOVER,
	CREDIT_NORM,
	CREDIT_HOVER,
	PAUSE_NORM,

	LOCK_NORM,
	LOCK_HOVER,
	BACK_NORM,
	BACK_HOVER,

	EMPTY_UI,
};

enum	BLASTER_COLLISION_TYPES
{
	E_NONE,
	BULLETS,
	SLIMES,
	PLAYER,
};

typedef struct	s_bullet
{
	SDLX_Sprite		sprite;

	SDL_Point		vel;
	SDL_bool		active;

	void			*meta;
	void			(*update)(void *, void *);

	SDLX_collision	hitbox;
}				t_bullet;

typedef struct	s_attacks
{
	size_t		index;
	size_t		capacity;

	t_bullet	*attacks;

}				t_attacks;

typedef struct	s_weapon
{
	unsigned int	start;
	unsigned int	cooldown;

	unsigned int	curr;

	SDL_bool		enabled;

	void		(*factory)(t_bullet *, SDL_Point, double angle, void *);
}				t_weapon;

typedef struct	s_enemy
{
	SDLX_Sprite		sprite;
	SDLX_collision	enemy_hurtbox;

	int				hp;

	void			*meta;
}				t_enemy;

typedef struct	s_player
{
	SDLX_Sprite		sprite;

	int				hp;

	t_weapon		weapon_equip;

	SDLX_collision	player_hurtbox;

	SDL_bool		*scene_end;

	//These are not permanent.
	t_attacks			attacks;
}				t_player;

#endif