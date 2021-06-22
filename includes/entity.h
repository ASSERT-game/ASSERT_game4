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

# include "main_structs.h"

/*
**Player
*/

void			player_init(t_player *dst);
void			player_update(t_player *self);

/*
**Weapons
*/

t_weapon		laser_cannon(void);


/*
**Enemy
*/

void			slime_update(void *self);
SDL_bool		slime_detect_collision(void *self, void *with, void *meta1, void *meta2, void *meta3);
void			*slime_collide(void *self, void *with, void *meta1, void *meta2, void *meta3);

#endif