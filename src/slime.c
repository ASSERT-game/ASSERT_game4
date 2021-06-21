/***************************************************************************
 * FILENAME:    enemy.c
 * DESCRIPTION: Handles the slime
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Jun2021
***************************************************************************/

#include "main.h"

SDL_bool	slime_detect_collision(void *self, void *with, void *meta1, void *meta2, void *meta3)
{
	SDLX_collison	*self_box;
	SDLX_collison	*hitbox;

	self_box = self;
	hitbox = with;

	if (hitbox->type != BULLETS)
		return (SDL_FALSE);

	if (SDL_HasIntersection(self_box->detect_meta1, hitbox->detect_meta1) == SDL_TRUE)
		return (SDL_TRUE);

	(void)self;
	(void)with;
	(void)meta1;
	(void)meta2;
	(void)meta3;
	return (SDL_FALSE);
}

void		*slime_collide(void *self, void *with, void *meta1, void *meta2, void *meta3)
{
	t_enemy	*slime;

	slime = meta1;
	slime->hp -= 1;
	SDL_Log("The slime is hit, I repeat the slime has been hit.");

	if (slime->hp <= 0)
		SDL_Log("Slime down, red chopper slime down!");

	(void)self;
	(void)with;
	(void)meta2;
	(void)meta3;
	return (NULL);
}

void	slime_update(void *self)
{
	t_enemy		*slime;
	int			dx;
	int			dy;
	int move = rand() % 9;

	slime = self;

	dx = 0;
	dy = 0;
	if (move % 3 == 1)
		dx++;
	else if (move % 3 == 2)
		dx--;

	if (move / 3 == 1)
		dy++;
	else if (move / 3 == 2)
		dy--;

	int x = slime->sprite._dst.x - 128;
	int y = slime->sprite._dst.y - 160;
	if (x * x + y * y > (x + dx) * (x + dx) + y * y)
		slime->sprite._dst.x += dx;

	if (x * x + y * y > x * x + (y + dy) * (y + dy))
		slime->sprite._dst.y += dy;

	SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
	SDL_Log("AT: %d", slime->hp);
}