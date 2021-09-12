/***************************************************************************
 * FILENAME:    emp.c
 * DESCRIPTION: emp attack
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

SDL_bool	emp_fire(SDL_UNUSED t_weapon *weapon)
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

void	emp_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	t_player	*player;

	bullet = self;
	player = bullet->meta;
	if (bullet->isActive == SDL_FALSE)
		return ;

	if (bullet->sprite.current >= (size_t)bullet->vel.x)
	{
		bullet->isActive = SDL_FALSE;
		return ;
	}

	if (!(player->weapon_equip->type & B_DEFENSE))
		player->weapon_equip->curr++;

	bullet->sprite.current++;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	emp_factory(t_bullet *dst, SDL_UNUSED SDL_Point spawn_point, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	SDLX_new_Sprite(&(dst->sprite));
	fetch_emp_sprite(&(dst->sprite.sprite_data), 2);

	dst->sprite.dst = SDLX_NULL_SELF;
	dst->sprite._dst = (SDL_Rect){(PLAY_WIDTH - (40 * 3)) / 2, (PLAY_HEIGHT -  (40 * 3)) / 2, (40 * 3), (40 * 3)};

	dst->vel.x = 50;
	dst->isActive = SDL_TRUE;

	dst->update = emp_update;
	dst->meta = meta;

	dst->hitbox.type = C_FIELD | C_CIRCLE;
	dst->hitbox.response_amount = C_E_BODY | C_E_PROJECTILE;
	dst->hitbox.originator = dst;
	dst->hitbox.engage_meta1 = (void *)EMP_FIELD;

	dst->hitbox.hitbox = dst->sprite._dst;
	dst->hitbox.hitbox_ptr = &(dst->hitbox.hitbox);

	dst->hitbox.detect = NULL;

	t_player *player;
	player = meta;
	dst->hitbox.engage_meta2 = &(player->weapon_equip->combo);
}

#define EMP_COOLDOWN (100)

t_weapon	emp_cannon(void)
{
	t_weapon	emp_cannon;

	emp_cannon.type = B_SPECIAL;

	SDLX_new_Sprite(&(emp_cannon.ability_icon));
	fetch_emp_sprite(&(emp_cannon.ability_icon.sprite_data), 0);

	SDLX_new_Sprite(&(emp_cannon.treasure_sprite));
	fetch_emp_sprite(&(emp_cannon.treasure_sprite.sprite_data), 1);

	emp_cannon.start = 0;
	emp_cannon.cooldown = EMP_COOLDOWN;

	emp_cannon.curr = EMP_COOLDOWN;

	emp_cannon.isEnabled = SDL_TRUE;
	emp_cannon.meta_int = 0;

	emp_cannon.factory = emp_factory;
	emp_cannon.trigger = emp_fire;

	combo_init(&(emp_cannon.combo));

	return (emp_cannon);
}