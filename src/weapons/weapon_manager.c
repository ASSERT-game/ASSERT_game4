/***************************************************************************
 * FILENAME:    weapon_manager.c
 * DESCRIPTION: Manager for the weapon system.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jun2021
***************************************************************************/

#include "main.h"

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
	dst->attacks[ix].hitbox.detect_meta2 = &(dst->attacks[ix]);
}
