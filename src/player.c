/***************************************************************************
 * FILENAME:    player.c
 * DESCRIPTION: Player struct file.
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

void	player_init(t_player *player)
{
	player->sprite = SDLX_Sprite_Static(ASSETS"bunny.png");
	player->sprite.dst = &(player->sprite._dst);
	player->sprite._dst = (SDL_Rect){7 * 16, 7 * 16 - 8, 32, 32};

	player->hp = 50;

	player->player_hurtbox.originator = player;
	player->player_hurtbox.detect = player_hit;
	player->player_hurtbox.engage = player_collide;
	player->player_hurtbox.type = PLAYER;
	player->player_hurtbox.detect_meta1 = &(player->sprite._dst);

	projectile_queue(&(player->attacks));
}

SDL_bool	player_hit(SDL_UNUSED void *self, void *with, SDL_UNUSED void *meta, SDL_UNUSED void *meta1)
{
	SDLX_collision	*hitbox;
	t_player		*player;

	player = self;
	hitbox = with;
	if (hitbox->type == SLIMES)
	{
		if (SDL_HasIntersection(&(player->sprite._dst), hitbox->detect_meta1) == SDL_TRUE)
			return (SDL_TRUE);
	}
	return (SDL_FALSE);
}

void		*player_collide(void *self, SDL_UNUSED void *with, SDL_UNUSED void *meta, SDL_UNUSED void *meta1)
{
	t_player	*player;

	player = self;

	player->hp -= 10;
	return (NULL);
}

void	player_update(t_player *self)
{
	t_weapon	*weapon;
	t_bullet	attack;

	weapon = self->weapon_equip;

	if (g_GameInput.GameInput.button_primleft && weapon->curr >= weapon->cooldown)
	{
		weapon->curr = weapon->start;
		weapon->factory(&(attack), (SDL_Point){0, 0}, 0, self);
		projectile_add(&(self->attacks), attack);
	}

	SDLX_RenderQueue_Add(NULL, &(self->sprite));
	SDLX_CollisionBucket_add(NULL, &(self->player_hurtbox));
}