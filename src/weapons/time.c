/***************************************************************************
 * FILENAME:    time.c
 * DESCRIPTION: Handles the time weapon
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 12Jun2021
***************************************************************************/

#include "main.h"

void	time_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;

	bullet = self;

	bullet->active = SDL_FALSE;
	return ;
}

void	time_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"heal.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){16, 16, 0, 0};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->active = SDL_FALSE;

	dst->update = time_update;

	dst->hitbox.originator = dst;

	dst->hitbox.detect = NULL;

	t_player	*player;
	SDL_bool	*slow;

	player = meta;
	slow = player->meta;
	*slow = SDL_TRUE;
}

#define time_COOLDOWN (270)

t_weapon	time_cannon(void)
{
	t_weapon	time_cannon;

	time_cannon.start = 0;
	time_cannon.cooldown = time_COOLDOWN;

	time_cannon.curr = time_COOLDOWN;

	time_cannon.enabled = SDL_TRUE;

	time_cannon.factory = time_factory;

	return (time_cannon);
}