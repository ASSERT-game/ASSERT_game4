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

void	player_init(t_player *dst)
{
	t_player	*player;

	player = dst;

	player->sprite = SDLX_Sprite_Static(ASSETS"bunny.png");
	player->sprite.dst = &(player->sprite._dst);
	player->sprite._dst = (SDL_Rect){7 * 16, 7 * 16, 40, 40};

	player->weapon_equip = laser_cannon();

	projectile_queue(&(player->attacks));
	player->attacks.queue = player->queue;
}

void	player_update(t_player *self)
{
	//Player hp drops below 0

	t_weapon	*weapon;
	t_bullet	attack;

	weapon = &(self->weapon_equip);
	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft) && weapon->curr >= weapon->cooldown)
	{
		weapon->curr = weapon->start;
		weapon->factory(&(attack), (SDL_Point){0, 0}, 0, NULL);
		projectile_add(&(self->attacks), attack);
	}

	weapon->curr++;
	/* If (curr) is equal to (cooldown + 1) undo the (curr++) */
	weapon->curr -= (weapon->curr / (weapon->cooldown + 1));

	SDLX_RenderQueue_add(self->queue, &(self->sprite));
}