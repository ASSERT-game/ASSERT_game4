/***************************************************************************
 * FILENAME:    status_effects.c
 * DESCRIPTION: File to manage enemy status effects
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 20Aug2021
***************************************************************************/

#include "main.h"

void	update_status(t_enemy *self)
{
	if (self->effects[RUNIC_SHIELD].info >= 12)
	{
		self->effects[RUNIC_SHIELD].info = 0;
		self->hp--;
		combo_increment(self->effects[RUNIC_SHIELD].combo_mod, self->enemy_hurtbox.hitbox_ptr);
	}

	if (self->effects[EMP_FIELD].info != 0)
	{
		self->effects[EMP_FIELD].info = 0;
		self->speed = self->effects[EMP_FIELD].record;
		self->sprite.current += 4;
	}

	if (self->effects[GHOST_BURN].info != 0)
	{
		self->effects[GHOST_BURN].info++;
		if (self->effects[GHOST_BURN].info % 4 == 0)
		{
			combo_increment(self->effects[GHOST_BURN].combo_mod, self->enemy_hurtbox.hitbox_ptr);
			self->hp--;
		}

		if (self->effects[GHOST_BURN].info == 37)
			self->effects[GHOST_BURN].info = 0;
	}
}