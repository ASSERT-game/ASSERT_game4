/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef main_H
# define main_H

# include <SDL_image.h>

# include "SDLX.h"

# define ASSETS "assets/"

typedef struct	s_context
{
	SDL_bool	exit;
	SDL_bool	scene;

	void		*meta;
	void		*meta_catch;

	void		*(*init_fn)(struct s_context *, void *, int);
	void		*(*update_fn)(struct s_context *, void *, int);
	void		*(*close_fn)(struct s_context *, void *, int);

	int			ticks;
}				t_context;

void			*main_menu_init(t_context *context, void *meta, int ticks);
void			*main_menu_close(t_context *context, void *meta, int ticks);
void			*main_menu_update(t_context *context, void *meta, int ticks);

void			*level_select_init(t_context *context, void *level, int tick);
void			*level_select_close(t_context *context, void *level, int tick);
void			*level_select_update(t_context *context, void *level, int tick);

void			*first_level_init(t_context *context, void *level, int tick);
void			*first_level_close(t_context *context, void *level, int tick);
void			*first_level_update(t_context *context, void *level, int tick);

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
}				t_enemy;

typedef struct	s_player
{
	SDLX_Sprite		sprite;

	t_weapon		weapon_equip;
	SDLX_collison	player_hurtbox;


	//These are not permanent.
	t_attacks			attacks;
}				t_player;

int				fetch_ui_sprite(SDLX_Sprite_Data **dst, int sprite_id);

void			player_init(t_player *dst);
void			player_update(t_player *self);

t_weapon		laser_cannon(void);

void	projectile_update(t_attacks *queue);
void	projectile_queue(t_attacks *attacks);
void	projectile_add(t_attacks *dst, t_bullet src);

void	slime_update(void *self);
SDL_bool	slime_detect_collision(void *self, void *with, void *meta1, void *meta2, void *meta3);
void		*slime_collide(void *self, void *with, void *meta1, void *meta2, void *meta3);

#endif

