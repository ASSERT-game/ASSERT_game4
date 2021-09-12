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

#define GHOSTFIRE_COOLDOWN (80)

SDL_bool	ghostfire_fire(t_weapon *weapon)
{
	SDL_bool	result;
	SDL_Rect	play_area;

	result = SDL_FALSE;
	play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, primleft) &&
		/* weapon->curr * 3 >= weapon->cooldown is the same as:
		weapon->curr >= (weapon->cooldown / 3) */
		weapon->curr * 3 >= weapon->cooldown &&
		 SDL_PointInRect(&(g_GameInput.GameInput.primary), &(play_area)))
	{
		if (g_GameInput.GameInput.button_primleft == 1)
			result = SDL_TRUE;

		if (g_GameInput.GameInput.button_primleft == 2 && weapon->meta_int == 1)
			result = SDL_TRUE;
	}

	if (g_GameInput.GameInput.button_primleft == 0)
		weapon->meta_int = 1;

	if (result == SDL_TRUE)
		weapon->meta_wpn = (void *)(long)(weapon->curr - GHOSTFIRE_COOLDOWN);
	return (result);
}

// static SDL_bool	bullet_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
// {
// 	// SDLX_collision	*self_box;
// 	// SDLX_collision	*hitbox;
// 	// t_bullet		*self_attack;

// 	// self_box = self;
// 	// hitbox = with;

// 	// self_attack = self;
// 	return (SDL_FALSE);
// }

void	ghostfire_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	// SDL_Rect	play_area;

	bullet = self;

	if (bullet->isActive == SDL_FALSE)
		return ;

	// play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (bullet->sprite.current == 21)
	{
		bullet->isActive = SDL_FALSE;
		return ;
	}

	bullet->sprite.current++;
	bullet->sprite._dst.x += bullet->vel.x;
	bullet->sprite._dst.y += bullet->vel.y;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	ghostfire_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	t_player *player;

	player = meta;
	player->weapon_equip->curr = (int)(player->weapon_equip->meta_wpn);

	SDLX_new_Sprite(&(dst->sprite));
	fetch_ghostfire_sprite(&(dst->sprite.sprite_data), 2);
	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){MID_PLAY_WIDTH - 17, MID_PLAY_HEIGHT - 14, 34, 28};
	dst->sprite.center = NULL;
	dst->sprite.angle = 0;

	dst->vel.x = 1;
	dst->vel.y = 1;

	dst->isActive = SDL_TRUE;

	angle = ptoa(g_GameInput.GameInput.primary.x, g_GameInput.GameInput.primary.y);
	dst->sprite.angle = (angle * 180 / M_PI);

	dst->vel.x = SDL_sin(angle) * 5;
	dst->vel.y = SDL_cos(angle) * -5;

	dst->update = ghostfire_update;

	dst->hitbox.type = C_FIELD | C_RECT;
	dst->hitbox.response_amount = C_E_BODY | C_E_PROJECTILE;
	dst->hitbox.originator = dst;
	dst->hitbox.engage_meta1 = (void *)GHOST_BURN;

	dst->hitbox.hitbox_ptr = &(dst->sprite._dst);

	dst->hitbox.detect = NULL;

	dst->hitbox.engage_meta2 = &(player->weapon_equip->combo);
}

t_weapon	ghostfire_cannon(void)
{
	t_weapon	ghostfire_cannon;

	ghostfire_cannon.type = B_OFFHAND;
	SDLX_new_Sprite(&(ghostfire_cannon.ability_icon));
	fetch_ghostfire_sprite(&(ghostfire_cannon.ability_icon.sprite_data), 0);

	SDLX_new_Sprite(&(ghostfire_cannon.treasure_sprite));
	fetch_ghostfire_sprite(&(ghostfire_cannon.treasure_sprite.sprite_data), 1);

	ghostfire_cannon.start = 0;
	ghostfire_cannon.cooldown = GHOSTFIRE_COOLDOWN * 3;

	ghostfire_cannon.curr = GHOSTFIRE_COOLDOWN;

	ghostfire_cannon.isEnabled = SDL_TRUE;
	ghostfire_cannon.meta_wpn = (void *)3;
	ghostfire_cannon.meta_int = 0;

	ghostfire_cannon.factory = ghostfire_factory;
	ghostfire_cannon.trigger = ghostfire_fire;

	combo_init(&(ghostfire_cannon.combo));

	return (ghostfire_cannon);
}
