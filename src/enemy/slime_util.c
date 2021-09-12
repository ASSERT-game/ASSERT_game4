/***************************************************************************
 * FILENAME:    slime_util.c
 * DESCRIPTION: Common Functions for Slimes
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 07Jul2021
***************************************************************************/

#include "main.h"

void	slime_default_init(t_enemy *slime, char *kind, int type, int max_hp, void (*update_fn)(t_enemy *, void *))
{
	char buff[30] = { 0 };

	SDL_snprintf(buff, 100, ASSETS"enemy/%s.png", kind);
	slime->isActive = SDL_TRUE;
	slime->sprite = SDLX_Sprite_Static(buff);

	slime->sprite.dst = SDLX_NULL_SELF;
	slime->sprite._dst = (SDL_Rect){10, 10, 32, 32};

	SDL_memset(&(slime->effects), 0, sizeof(slime->effects));
	slime->enemy_hurtbox.originator = slime;

	slime->enemy_hurtbox.hitbox_ptr = &(slime->sprite._dst);
	slime->enemy_hurtbox.type = type;
	slime->enemy_hurtbox.response_amount = C_PROJECTILE | C_PLAYER | C_MELEE;
	slime->enemy_hurtbox.detect = slime_detect_collision;
	slime->enemy_hurtbox.engage = slime_collide;

	slime->max_hp = max_hp;
	slime->hp = slime->max_hp;

	slime->update = update_fn;
}

SDL_bool	slime_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collision	*hitbox;
	t_enemy			*slime;
	SDL_bool		result;
	SDL_bool		(*collide_fn)(SDLX_collision *, SDLX_collision *);

	result = SDL_FALSE;
	slime = self;
	hitbox = with;

	collide_fn = SDLX_Collide_RectToRect;
	if (hitbox->type & C_ARECT)
		collide_fn = SDLX_Collide_RectToARect;
	else if (hitbox->type & C_CIRCLE)
		collide_fn = SDLX_Collide_RectToCircle;

	if (hitbox->type & slime->enemy_hurtbox.response_amount)
	{
		if (collide_fn(&(slime->enemy_hurtbox), hitbox) == SDL_TRUE)
		{
			if ((hitbox->type & (C_PLAYER | C_E_PROJECTILE)) == 0)
				combo_increment(hitbox->engage_meta2, slime->enemy_hurtbox.hitbox_ptr);
			result = SDL_TRUE;
		}
	}

	if (hitbox->type & C_FIELD && collide_fn(&(slime->enemy_hurtbox), hitbox) == SDL_TRUE)
	{
		slime->effects[(size_t)hitbox->engage_meta1].info++;
		slime->effects[(size_t)hitbox->engage_meta1].combo_mod = hitbox->engage_meta2;

		if (slime->effects[EMP_FIELD].info == 1 && (int)hitbox->engage_meta1 == EMP_FIELD)
		{
			slime->effects[EMP_FIELD].record = slime->speed;
			slime->speed = 0;
		}
	}


	return (result);
}

SDL_bool	slime_detect_collision_once(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collision	*hitbox;
	t_enemy			*slime;
	t_bullet		*bullet;
	SDL_bool		(*collide_fn)(SDLX_collision *, SDLX_collision *);

	slime = self;
	hitbox = with;


	if (hitbox->type & C_PROJECTILE)
	{
		bullet = hitbox->originator;
		if (bullet->isActive == SDL_FALSE)
			return (SDL_FALSE);
	}

	collide_fn = SDLX_Collide_RectToRect;
	if (hitbox->type & C_ARECT)
		collide_fn = SDLX_Collide_RectToARect;
	else if (hitbox->type & C_CIRCLE)
		collide_fn = SDLX_Collide_RectToCircle;


	if (hitbox->type & slime->enemy_hurtbox.response_amount)
	{
		if (collide_fn(&(slime->enemy_hurtbox), hitbox) == SDL_TRUE)
		{
			if (hitbox->type & C_PROJECTILE)
				bullet->isActive = SDL_FALSE;
			if ((hitbox->type & (C_PLAYER | C_E_PROJECTILE)) == 0)
				combo_increment(hitbox->engage_meta2, slime->enemy_hurtbox.hitbox_ptr);
			return (SDL_TRUE);
		}
	}

	if (hitbox->type & C_FIELD && collide_fn(&(slime->enemy_hurtbox), hitbox) == SDL_TRUE)
	{
		slime->effects[(size_t)hitbox->engage_meta1].info++;
		slime->effects[(size_t)hitbox->engage_meta1].combo_mod = hitbox->engage_meta2;

		if (slime->effects[EMP_FIELD].info == 1 && (int)hitbox->engage_meta1 == EMP_FIELD)
		{
			slime->effects[EMP_FIELD].record = slime->speed;
			slime->speed = 0;
		}
	}

	return (SDL_FALSE);
}