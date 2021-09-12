/***************************************************************************
 * FILENAME:    button.c
 * DESCRIPTION: Buttons for blaster.
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

void	*button_chest_update(SDLX_button *self, SDL_UNUSED void *vp_context, SDL_UNUSED size_t length)
{
	SDLX_Sprite	*treasure;

	treasure = self->meta;
	if (self->isTriggered && self->sprite.dst->y >= 40)
	{
		self->sprite.dst->y -= 2;
		self->sprite.dst->w -= 1;
		self->sprite.dst->h -= 1;

		self->sprite.dst->x = (PLAY_WIDTH - self->sprite.dst->w) / 2;
	}
	else if (self->isTriggered && treasure != NULL)
	{
		if (treasure->_dst.y >= 40)
		{
			treasure->_dst.y -= 1;
			treasure->_dst.w += 2;
			treasure->_dst.h += 2;

			treasure->_dst.x = (PLAY_WIDTH - treasure->_dst.w) / 2;
		}

		SDLX_RenderQueue_Add(NULL, treasure);
	}
	return (NULL);
}

void	*button_chest(SDLX_button *self, SDL_UNUSED void *vp_context, SDL_UNUSED size_t length)
{
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		self->isLocked = SDL_TRUE;
		self->isTriggered = SDL_TRUE;

		self->sprite_fn(&(self->sprite.sprite_data), 2);
		self->sprite.current = 0;

		self->trigger_fn = SDLX_Button_NULL_fn;
	}
	return (NULL);
}

void	*button_trigger_scene_switch(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length)
{
	t_context *context;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		context = vp_context;
		context->init_fn = self->meta1;
		context->shouldChange = SDL_TRUE;
	}

	return (NULL);
}

void	*button_pause(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t length)
{
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		self->sprite_fn(&(self->sprite.sprite_data), self->norm_no);
		self->isTriggered = SDL_TRUE;
	}
	return (NULL);
}

void	*button_pause_key(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t length)
{
	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, START))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, START)

		self->sprite_fn(&(self->sprite.sprite_data), self->norm_no);
		self->isTriggered = SDL_TRUE;
	}
	return (NULL);
}

void	*button_resume(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length)
{
	SDL_bool	*pause;
	// SDLX_button	*button;
	SDL_Texture	**pbackground;

	// button = self;
	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		pause = pause_addr;
		*pause = SDL_FALSE;

		self->isFocused = SDL_FALSE;
		self->sprite_fn(&(self->sprite.sprite_data), self->norm_no);

		pbackground = self->meta1;
		SDL_DestroyTexture(*pbackground);
		*pbackground = NULL;
	}

	return (NULL);
}

void	*change_ability(SDLX_button *self, void *weapon_addr, SDL_UNUSED size_t length)
{
	t_weapon	**player_spot;
	t_weapon	*from_weapon;

	if (SDLX_GAME_PRESS(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)
		g_GameInput.GameInput.button_primleft = ABILITY_CHANGED;
		self->isTriggered = SDL_TRUE;
	}

	if (self->isTriggered == SDL_TRUE)
	{
		self->isTriggered = SDL_FALSE;

		from_weapon = self->meta1;
		player_spot = weapon_addr;
		(*player_spot)->meta_int = 0; /* Resetting the metadata for weapons upon switching */
		*player_spot = from_weapon;
	}

	return (NULL);
}

void	*ability_button_update(SDLX_button *self, void *weapon_addr, SDL_UNUSED size_t length)
{
	t_weapon	**player_spot;
	int			*keymap;

	player_spot = weapon_addr;

	keymap = self->down;
	if (*keymap == 1 && *player_spot != self->meta1)
	{
		self->isTriggered = SDL_TRUE;
		self->trigger_fn(self, self->meta, 0);
	}

	if (*player_spot == self->meta1)
		self->sprite_fn(&(self->sprite.sprite_data), ABILITY_SEL);
	else
		self->sprite_fn(&(self->sprite.sprite_data), ABILITY);
	return (NULL);
}

void	ability_button_init(SDLX_button *dst, t_weapon **player_equip_addr, t_weapon *bound_weapon)
{
	SDLX_Button_Init(dst, fetch_ui_sprite, ABILITY, (SDL_Rect){0, 400, 48, 48}, NULL);

	dst->isDisabled = SDL_TRUE;
	if (bound_weapon->isEnabled == SDL_TRUE)
		dst->isDisabled = SDL_FALSE;

	dst->meta1 = bound_weapon;
	dst->meta = player_equip_addr;
	dst->trigger_fn = change_ability;
	dst->update_fn = ability_button_update;
	bound_weapon->ability_icon.dst = &(dst->sprite._dst);
}

void	*button_carousel_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length)
{
	size_t	*at;
	int		delta;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		at = self->meta;
		delta = (int)self->meta1;
		*at += delta;
	}

	return (NULL);
}

void	*button_equip_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length)
{
	t_context		*context;
	t_weapon		*new_weapon;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		context = self->meta;
		new_weapon = self->meta1;
		if (new_weapon->type & B_MAINHAND) { context->mainhand = *new_weapon; }
		else if (new_weapon->type & B_DEFENSE) { context->defense = *new_weapon; }
		else if (new_weapon->type & B_OFFHAND) { context->offhand = *new_weapon; }
		else if (new_weapon->type & B_SPECIAL) { context->special = *new_weapon; }
	}

	return (NULL);
}

void	*button_unequip_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length)
{
	t_context	*context;
	t_weapon	*new_weapon;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		SDLX_INPUT_CONSUME(g_GameInput, g_GameInput_prev, primleft)

		context = self->meta;
		new_weapon = self->meta1;
		if (new_weapon->type & B_MAINHAND) { unequip_weapon(&(context->mainhand)); }
		else if (new_weapon->type & B_DEFENSE) { unequip_weapon(&(context->defense)); }
		else if (new_weapon->type & B_OFFHAND) { unequip_weapon(&(context->offhand)); }
		else if (new_weapon->type & B_SPECIAL) { unequip_weapon(&(context->special)); }
	}

	return (NULL);
}