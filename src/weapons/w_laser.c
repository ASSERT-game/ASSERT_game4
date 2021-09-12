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

SDL_bool	laser_fire(SDL_UNUSED t_weapon *weapon)
{
	SDL_bool	result;
	SDL_Rect	play_area;

	result = SDL_FALSE;
	play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, primleft) && weapon->curr >= weapon->cooldown && SDL_PointInRect(&(g_GameInput.GameInput.primary), &(play_area)))
	{
		if (g_GameInput.GameInput.button_primleft == 1)
			result = SDL_TRUE;

		if (g_GameInput.GameInput.button_primleft == 2 && weapon->meta_int == 1)
			result = SDL_TRUE;
	}

	if (g_GameInput.GameInput.button_primleft == 0)
		weapon->meta_int = 1;
	return (result);
}

SDL_bool	bullet_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	// SDLX_collision	*self_box;
	SDLX_collision	*hitbox;
	t_bullet		*self_attack;

	// self_box = self;
	hitbox = with;

	self_attack = self;
	if (hitbox->type & self_attack->hitbox.response_amount)
	{
		if (SDL_HasIntersection(self_attack->hitbox.hitbox_ptr, hitbox->hitbox_ptr))
			self_attack->isActive = SDL_FALSE;
	}
	return (SDL_FALSE);
}

void	laser_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	SDL_Rect	play_area;

	bullet = self;

	if (bullet->isActive == SDL_FALSE)
		return ;

	play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (SDL_HasIntersection(&(bullet->sprite._dst), &(play_area)) == SDL_FALSE)
	{
		bullet->isActive = SDL_FALSE;
		// SDL_free(bullet->sprite.sprite_data);
		return ;
	}

	bullet->sprite._dst.x += bullet->vel.x;
	bullet->sprite._dst.y += bullet->vel.y;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	laser_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	SDLX_new_Sprite(&(dst->sprite));
	fetch_red_sprite(&(dst->sprite.sprite_data), 2);
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){MID_PLAY_WIDTH - 8, MID_PLAY_HEIGHT - 8, 16, 16};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->isActive = SDL_TRUE;

	angle = ptoa(g_GameInput.GameInput.primary.x, g_GameInput.GameInput.primary.y);
	dst->sprite.angle = (angle * 180 / M_PI);

	dst->vel.x = SDL_sin(angle) * 12;
	dst->vel.y = SDL_cos(angle) * -12;

	dst->update = laser_update;

	dst->hitbox.type = C_PROJECTILE | C_RECT;
	dst->hitbox.response_amount = C_E_BODY | C_E_PROJECTILE;
	dst->hitbox.originator = dst;

	dst->hitbox.hitbox_ptr = &(dst->sprite._dst);

	t_player *player;
	player = meta;
	player->sprite.current = 8;

	dst->hitbox.detect = bullet_detect_collision;

	dst->hitbox.engage_meta2 = &(player->weapon_equip->combo);
}

#define LASER_COOLDOWN (12)

t_weapon	laser_cannon(void)
{
	t_weapon	laser_cannon;

	laser_cannon.type = B_MAINHAND;
	SDLX_new_Sprite(&(laser_cannon.ability_icon));
	fetch_red_sprite(&(laser_cannon.ability_icon.sprite_data), 0);

	SDLX_new_Sprite(&(laser_cannon.treasure_sprite));
	fetch_red_sprite(&(laser_cannon.treasure_sprite.sprite_data), 1);

	laser_cannon.start = 0;
	laser_cannon.cooldown = LASER_COOLDOWN;

	laser_cannon.curr = LASER_COOLDOWN;

	laser_cannon.isEnabled = SDL_TRUE;
	laser_cannon.meta_int = 0;

	laser_cannon.factory = laser_factory;
	laser_cannon.trigger = laser_fire;

	combo_init(&(laser_cannon.combo));

	return (laser_cannon);
}
