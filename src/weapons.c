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

void	laser_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	SDL_Rect	play_area;

	bullet = self;

	play_area = (SDL_Rect){0, 0, 256, 256};
	if (SDL_HasIntersection(&(bullet->sprite._dst), &(play_area)) == SDL_FALSE)
	{
		bullet->active = SDL_FALSE;
		return ;
	}

	bullet->sprite._dst.x += bullet->vel.x;
	bullet->sprite._dst.y += bullet->vel.y;
	SDLX_RenderQueue_add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

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

	dst->update = laser_update;


	dst->hitbox.type = BULLETS;
	dst->hitbox.originator = dst;
	// dst->hitbox.detect_meta1 = dst->sprite.dst;

	dst->hitbox.detect = NULL;
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
	size_t	count;

	ix = 0;
	count = 0;
	while (ix < attacks->capacity)
	{
		if (attacks->attacks[ix].active)
		{
			//calls the bullet update function
			attacks->attacks[ix].sprite._dst.x += attacks->attacks[ix].vel.x;
			attacks->attacks[ix].sprite._dst.y += attacks->attacks[ix].vel.y;
			SDLX_RenderQueue_add(NULL, &(attacks->attacks[ix].sprite));
			SDLX_CollisionBucket_add(NULL, &(attacks->attacks[ix].hitbox));

			attacks->attacks[ix].update(&(attacks->attacks[ix]), NULL);

			count++;
		}
		ix++;
	}
	// SDL_Log("Projectile Count: %zu", count);
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


	dst->attacks[ix].hitbox.type = BULLETS;
	dst->attacks[ix].hitbox.detect_meta1 = &(dst->attacks[ix].sprite._dst);
}
