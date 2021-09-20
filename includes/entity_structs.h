/***************************************************************************
 * FILENAME:    entity_structs.h
 * DESCRIPTION: Header file for structs of entities, bullets, projectiles,
 * players, enemies.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jul2021
***************************************************************************/

#ifndef ENITY_STRUCTS_H
# define ENITY_STRUCTS_H

# include "SDLX/SDLX.h"
# include "main_enums.h"

struct s_bullet;
struct s_enemy_m;
typedef struct s_enemy_m t_enemy_m;

typedef struct	s_combo
{
	SDLX_Sprite	sprite;
	size_t		lifetime;
	int			no;
	SDL_bool	active;
}				t_combo;

typedef struct	s_weapon
{
	int				type;
	SDL_bool		(*trigger)(struct s_weapon *);
	void			(*factory)(struct s_bullet *, SDL_Point, double , void *);

	SDLX_Sprite		treasure_sprite;
	SDLX_Sprite		cooldown_sprite;
	SDLX_Sprite		ability_icon;

	SDL_bool		display_combo;
	t_combo			combo;

	unsigned int	start;
	unsigned int	cooldown;

	unsigned int	curr;

	void			*meta_wpn;
	int				meta_int;
	SDL_bool		isEnabled;
}				t_weapon;

typedef struct	s_bullet
{
	SDLX_Sprite		sprite;
	SDLX_collision	hitbox;
	SDL_FPoint		delta;
	void			(*update)(void *, void *);

	SDL_Point		vel;

	void			*meta;
	SDL_bool		isActive;
}				t_bullet;

typedef struct	s_attacks
{
	size_t		capacity;

	t_bullet	*attacks;
}				t_attacks;

typedef	struct	s_effects
{
	int		info;
	double	record;
	t_combo	*combo_mod;
}				t_effects;

typedef struct	s_enemy
{
	SDLX_Sprite		sprite;
	SDL_FPoint		delta;
	double			speed;
	SDLX_collision	enemy_hurtbox;
	void			(*update)(struct s_enemy *, void *);

	int				hp;
	int				max_hp;
	size_t			*score_ptr;

	void			*meta1;
	void			*meta2;
	t_effects		effects[EFFECT_SIZE];
	SDL_bool		isActive;
	t_attacks		*projectile_spawn;
	t_enemy_m		*spawn_pool;
}				t_enemy;

typedef struct	s_enemy_m
{
	size_t		capacity;

	t_enemy		*entity_array;
}				t_enemy_m;

typedef struct	s_player
{
	SDLX_Sprite		sprite;
	SDL_Rect		hurtbox;
	SDLX_collision	player_hurtbox;

	int				hp;
	int				max_hp;

	SDLX_Sprite		hp_s;
	SDLX_Sprite		hpl_s;
	SDLX_Sprite		heart;

	t_weapon		*weapon_equip;
	t_attacks		attacks;
	int				score;

	SDL_bool		*hit;
}				t_player;

#endif