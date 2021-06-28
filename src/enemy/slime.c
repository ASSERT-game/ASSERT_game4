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

void		slime_init(t_enemy *dst)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"slime.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){10, 10, 32, 32};

	dst->enemy_hurtbox.originator = dst;
	dst->enemy_hurtbox.detect_meta1 = &(dst->sprite._dst);
	dst->enemy_hurtbox.engage_meta1 = dst;
	dst->enemy_hurtbox.type = SLIMES;
	dst->enemy_hurtbox.detect = slime_detect_collision;
	dst->enemy_hurtbox.engage = slime_collide;

	dst->hp = 2;
	dst->meta = (void *)3;
}

SDL_bool	slime_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collision	*hitbox;
	t_enemy			*slime;

	slime = self;
	hitbox = with;

	if (hitbox->type == BULLETS || hitbox->type == PLAYER)
	{
		if (SDL_HasIntersection(&(slime->sprite._dst), hitbox->detect_meta1))
			return (SDL_TRUE);
	}
	return (SDL_FALSE);
}

void		*slime_collide(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	t_enemy			*slime;
	SDLX_collision	*hurtbox;

	slime = self;
	slime->hp -= 1;

	hurtbox = with;
	if (hurtbox->type == PLAYER)
	{
		slime->hp = 0;
	}
	(void)with;
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

	int x = slime->sprite._dst.x - (256 / 2) + 16;
	int y = slime->sprite._dst.y - (240 / 2) + 16;

	if (x * x + y * y > (x + dx) * (x + dx) + y * y)
		slime->sprite._dst.x += dx * (int)(slime->meta);

	if (x * x + y * y > x * x + (y + dy) * (y + dy))
		slime->sprite._dst.y += dy * (int)(slime->meta);

	if (slime->hp <= 0)
	{
		// SDL_Log("Slime down, red chopper slime down!");
		int *score;

		score = slime->enemy_hurtbox.engage_meta2;
		*score += 1;
		if (rand() % 2 == 1)
		{
			slime->sprite.dst->x = rand() % 256;
			slime->sprite.dst->y = 240 * (rand() % 2);
		}
		else
		{
			slime->sprite.dst->y = rand() % 240;
			slime->sprite.dst->x = 256 * (rand() % 2);
		}

		slime->hp = 2;
	}

	SDLX_RenderQueue_Add(NULL, &(slime->sprite));
	SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
	// SDL_Log("AT: %d", slime->hp);
}