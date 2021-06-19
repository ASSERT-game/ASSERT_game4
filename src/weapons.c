/***************************************************************************
 * FILENAME:    weapons.c
 * DESCRIPTION: Handles the weapon system
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

void	laser_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"laser.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){128, 7 * 16 + 8, 16, 16};
	dst->sprite.center = SDLX_NULL_SELF;
	dst->sprite._center.x = 8;
	dst->sprite._center.y = 32;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->active = SDL_TRUE;

	dst->sprite.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (dst->sprite._dst.x + 4), (dst->sprite._dst.y + 16) - g_GameInput.GameInput.primary.y) * 180 / M_PI);

	angle = SDL_atan2(g_GameInput.GameInput.primary.x - (dst->sprite._dst.x + 4), (dst->sprite._dst.y + 16) - g_GameInput.GameInput.primary.y);

	dst->vel.x = SDL_sin(angle) * 12;
	dst->vel.y = SDL_cos(angle) * -12;
}

#define LASER_COOLDOWN (2)

t_weapon	laser_cannon(void)
{
	t_weapon	laser_cannon;

	laser_cannon.start = 0;
	laser_cannon.cooldown = LASER_COOLDOWN;

	laser_cannon.curr = LASER_COOLDOWN;

	laser_cannon.enabled = SDL_TRUE;

	laser_cannon.factory = laser_factory;

	return (laser_cannon);
}

void	projectile_queue(t_attacks *dst)
{
	dst->index = 0;
	dst->capacity = 300;

	dst->attacks = SDL_calloc(dst->capacity, sizeof(*(dst->attacks)));
}

void	projectile_update(t_attacks *attacks)
{
	size_t	ix;

	ix = 0;
	while (ix < attacks->capacity)
	{
		if (attacks->attacks[ix].active)
		{
			//calls the bullet update function
			attacks->attacks[ix].sprite._dst.x += attacks->attacks[ix].vel.x;
			attacks->attacks[ix].sprite._dst.y += attacks->attacks[ix].vel.y;
			SDLX_RenderQueue_add(NULL, &(attacks->attacks[ix].sprite));
		}
		ix++;
	}
}

void	projectile_add(t_attacks *dst, t_bullet src)
{
	size_t	ix;

	ix = 0;
	while (ix < dst->capacity && dst->attacks[ix].active == SDL_TRUE)
	{
		ix++;
	}

	if (ix == dst->capacity)
	{
		dst->attacks = SDL_realloc(dst->attacks, sizeof(*(dst->attacks)) * dst->capacity * 2);
		dst->capacity = dst->capacity * 2;
	}

	dst->attacks[ix] = src;
	dst->attacks[ix].sprite.dst = &(dst->attacks[ix].sprite._dst);
}