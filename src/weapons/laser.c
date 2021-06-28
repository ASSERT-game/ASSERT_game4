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

SDL_bool	bullet_detect_collision(void *self, void *with, void *meta1, void *meta2)
{
	SDLX_collision	*self_box;
	SDLX_collision	*hitbox;
	t_bullet		*self_attack;

	self_box = self;
	hitbox = with;

	self_attack = meta2;
	if (hitbox->type == SLIMES && SDL_HasIntersection(meta1, hitbox->detect_meta1))
		self_attack->active = SDL_FALSE;

	(void)meta1;

	return (SDL_FALSE);
}

void	laser_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	SDL_Rect	play_area;

	bullet = self;

	if (bullet->active == SDL_FALSE)
		return ;

	play_area = (SDL_Rect){0, 0, 256, 256};
	if (SDL_HasIntersection(&(bullet->sprite._dst), &(play_area)) == SDL_FALSE)
	{
		bullet->active = SDL_FALSE;
		SDL_free(bullet->sprite.sprite_data);
		return ;
	}

	bullet->sprite._dst.x += bullet->vel.x;
	bullet->sprite._dst.y += bullet->vel.y;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	laser_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"laser.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(256 / 2) - 8, 120 - 8, 16, 16};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->active = SDL_TRUE;

	dst->sprite.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y) * 180 / M_PI);

	angle = SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y);

	dst->vel.x = SDL_sin(angle) * 12;
	dst->vel.y = SDL_cos(angle) * -12;

	dst->update = laser_update;


	dst->hitbox.type = BULLETS;
	dst->hitbox.originator = dst;

	dst->hitbox.detect = bullet_detect_collision;
}

void	laser_green_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"laser_green.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(256 / 2) - 8, 120 - 8, 16, 16};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->active = SDL_TRUE;

	dst->sprite.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y) * 180 / M_PI);

	angle = SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y);

	dst->vel.x = SDL_sin(angle) * 12;
	dst->vel.y = SDL_cos(angle) * -12;

	dst->update = laser_update;


	dst->hitbox.type = BULLETS;
	dst->hitbox.originator = dst;

	dst->hitbox.detect = bullet_detect_collision;
}

#define LASER_COOLDOWN (9)

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

t_weapon	laser_green_cannon(void)
{
	t_weapon	laser_cannon;

	laser_cannon.start = 0;
	laser_cannon.cooldown = LASER_COOLDOWN - 2;

	laser_cannon.curr = LASER_COOLDOWN;

	laser_cannon.enabled = SDL_TRUE;

	laser_cannon.factory = laser_green_factory;

	return (laser_cannon);
}

void	laser_yellow_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	dst->sprite = SDLX_Sprite_Static(ASSETS"laser_yellow.png");
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(256 / 2) - 8, 120 - 8, 16, 16};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->active = SDL_TRUE;

	dst->sprite.angle = (SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y) * 180 / M_PI);

	angle = SDL_atan2(g_GameInput.GameInput.primary.x - (256 / 2), 120 - g_GameInput.GameInput.primary.y);

	dst->vel.x = SDL_sin(angle) * 16;
	dst->vel.y = SDL_cos(angle) * -16;

	dst->update = laser_update;


	dst->hitbox.type = BULLETS;
	dst->hitbox.originator = dst;

	dst->hitbox.detect = bullet_detect_collision;
}

t_weapon	laser_yellow_cannon(void)
{
	t_weapon	laser_cannon;

	laser_cannon.start = 0;
	laser_cannon.cooldown = LASER_COOLDOWN - 5;

	laser_cannon.curr = LASER_COOLDOWN;

	laser_cannon.enabled = SDL_TRUE;

	laser_cannon.factory = laser_yellow_factory;

	return (laser_cannon);
}
