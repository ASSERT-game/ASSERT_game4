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

typedef struct	s_context
{
	SDL_bool	exit;
	SDL_bool	scene;

	void		*meta;

	SDLX_Sprite	background;

	void		*(*init_fn)(struct s_context *, void *);
	void		*(*update_fn)(struct s_context *, void *);
	void		*(*close_fn)(struct s_context *, void *);

}				t_context;

enum	BLASTER_UI_SPRITES
{
	PLAY_NORM,
	PLAY_HOVER,
	CREDIT_NORM,
	CREDIT_HOVER,
	PAUSE_NORM,
};

enum	BLASTER_COLL_TYPES
{
	BULLETS,
	SLIMES,
};

typedef struct	s_bullet
{
	SDLX_Sprite		sprite;

	SDL_Point		vel;
	SDL_bool		active;

	void			*meta;
	void			(*update)(void *, void *);

	SDLX_collison	hitbox;
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
	SDLX_collison	enemy_hurtbox;

	int				hp;

	void			*meta;
}				t_enemy;

typedef struct	s_player
{
	SDLX_Sprite		sprite;

	t_weapon		weapon_equip;
	SDLX_collison	player_hurtbox;


	//These are not permanent.
	t_attacks			attacks;
}				t_player;

#endif