/***************************************************************************
 * FILENAME:    entity.h
 * DESCRIPTION: Header file for the functions of Entities.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jun2021
***************************************************************************/

#ifndef ENTITY_H
# define ENTITY_H

# include "entity_structs.h"

/*
**Player
*/

void			player_init(t_player *dst);
void			player_update(t_player *self);

/*
**Weapons
*/

t_weapon		laser_cannon(void);
t_weapon		faser_cannon(void);
t_weapon		ghostfire_cannon(void);
t_weapon		shield_cannon(void);
t_weapon		emp_cannon(void);
t_weapon		null_cannon(void);

/*
**Enemy
*/

enum			e_enemy_t
{
	E_SLIME_CYAN,
	E_SLIME_BLUE,
	E_SLIME_SPINY,
	E_SLIME_YELLOW,
	E_SLIME_PURP,
	E_SLIME_INV,
	E_NONE_TYPE,
};

void			slime_default_init(t_enemy *slime, char *kind, int type, int max_hp, void (*update_fn)(t_enemy *, void *));
void			slime_respawn(t_enemy *slime);
void			*slime_collide(void *self, void *with, void *meta1, void *meta2);
SDL_bool		slime_detect_collision(void *self, void *with, void *meta1, void *meta2);
SDL_bool		slime_detect_collision_once(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2);

void			slime_blue_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_inv_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_blue_update(t_enemy *slime, void *meta);

void			slime_yellow_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_yellow_update(t_enemy *slime, void *meta);

void			slime_purple_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_purple_update(t_enemy *slime, void *meta);

void			slime_cyan_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_cyan_update(t_enemy *self, void *);

void			slime_spiny_init(t_enemy *dst, SDL_Point loc, int mod);
void			slime_spiny_update(t_enemy *slime, void *meta);

#endif