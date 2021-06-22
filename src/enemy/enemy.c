/***************************************************************************
 * FILENAME:
 * DESCRIPTION: File for
 *     */
/*
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jun2021
***************************************************************************/

#include "main.h"

SDL_bool	ename_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collison	*hitbox;
	t_enemy			*ename;

	ename = self;
	hitbox = with;

	return (SDL_FALSE);
}

void		*ename_collide(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collison	*hitbox;
	t_enemy		*ename;

	ename = self;
	hitbox = with;

	return (NULL);
}

void		ename_update(void *self)
{
	t_enemy		*ename;

	ename = self;

	SDLX_RenderQueue_Add(NULL, &(ename->sprite));
	SDLX_CollisionBucket_add(NULL, &(ename->enemy_hurtbox));
}