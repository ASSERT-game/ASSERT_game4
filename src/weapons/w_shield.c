/***************************************************************************
 * FILENAME:    shield.c
 * DESCRIPTION: Shield attack
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 08Jul2021
***************************************************************************/

#include "main.h"

SDL_bool	shield_fire(SDL_UNUSED t_weapon *weapon)
{
	SDL_bool	result;

	result = SDL_FALSE;

	if ((SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft) || g_GameInput.GameInput.button_primleft == ABILITY_CHANGED) && weapon->curr >= weapon->cooldown)
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft);
		result = SDL_TRUE;
	}

	return (result);
}

void	mini_shield_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;

	bullet = self;
	if (bullet->isActive == SDL_FALSE)
		return ;

	if (bullet->sprite.current >= (size_t)bullet->vel.x)
	{
		bullet->isActive = SDL_FALSE;
		return ;
	}

	bullet->sprite.current++;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	mini_shield_factory(t_bullet *dst)
{
	SDLX_new_Sprite(&(dst->sprite));
	fetch_shield_sprite(&(dst->sprite.sprite_data), 2);

	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(PLAY_WIDTH - (30 * 3)) / 2, (PLAY_HEIGHT -  (30 * 3)) / 2, (30 * 3), (30 * 3)};

	dst->vel.x = 35;
	dst->isActive = SDL_TRUE;

	dst->update = mini_shield_update;

	dst->hitbox.type = C_MELEE | C_CIRCLE;
	dst->hitbox.response_amount = C_E_BODY | C_E_PROJECTILE;
	dst->hitbox.originator = dst;
	dst->hitbox.hitbox_ptr = &(dst->sprite._dst);

	dst->hitbox.detect = NULL;
}

void	shield_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	t_bullet	*mini_shield_addr;

	bullet = self;
	if (bullet->isActive == SDL_FALSE)
		return ;

	if (bullet->sprite.current >= (size_t)bullet->vel.x)
	{
		bullet->isActive = SDL_FALSE;
		mini_shield_addr = spawn_projectile_addr(bullet->meta);
		mini_shield_factory(mini_shield_addr);
		mini_shield_addr->hitbox.engage_meta2 = bullet->hitbox.engage_meta2;
		return ;
	}

	bullet->sprite.current++;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	shield_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, void *meta)
{
	t_player	*player;

	player = meta;
	dst->meta = &(player->attacks);

	SDLX_new_Sprite(&(dst->sprite));
	fetch_shield_sprite(&(dst->sprite.sprite_data), 2);

	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(PLAY_WIDTH - (54 * 3)) / 2, (PLAY_HEIGHT -  (54 * 3)) / 2, (54 * 3), (54 * 3)};

	dst->vel.x = 100;
	dst->isActive = SDL_TRUE;

	dst->update = shield_update;

	dst->hitbox.type = C_FIELD | C_CIRCLE;
	dst->hitbox.response_amount = C_E_BODY | C_E_PROJECTILE;
	dst->hitbox.originator = dst;
	dst->hitbox.hitbox_ptr = &(dst->sprite._dst);
	dst->hitbox.engage_meta1 = (void *)RUNIC_SHIELD;

	dst->hitbox.detect = NULL;

	dst->hitbox.engage_meta2 = &(player->weapon_equip->combo);
	player->weapon_equip->combo.sprite.current = 0;
}

#define SHIELD_COOLDOWN (250)

t_weapon	shield_cannon(void)
{
	t_weapon	shield_cannon;

	shield_cannon.type = B_DEFENSE;

	SDLX_new_Sprite(&(shield_cannon.ability_icon));
	fetch_shield_sprite(&(shield_cannon.ability_icon.sprite_data), 0);

	SDLX_new_Sprite(&(shield_cannon.treasure_sprite));
	fetch_shield_sprite(&(shield_cannon.treasure_sprite.sprite_data), 1);

	shield_cannon.start = 0;
	shield_cannon.cooldown = SHIELD_COOLDOWN;

	shield_cannon.curr = SHIELD_COOLDOWN;

	shield_cannon.isEnabled = SDL_TRUE;
	shield_cannon.meta_int = 0;

	shield_cannon.factory = shield_factory;
	shield_cannon.trigger = shield_fire;

	combo_init(&(shield_cannon.combo));
	shield_cannon.combo.lifetime = 250;

	return (shield_cannon);
}