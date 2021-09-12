/***************************************************************************
 * FILENAME:    combo.c
 * DESCRIPTION: Manages combo functionality in the game.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 02Sep2021
***************************************************************************/

#include "main.h"

void	update_combo_active(t_combo *self, size_t *score)
{
	SDL_bool	active;

	active = SDL_FALSE;
	if (self->no >= 2)
	{
		active = SDL_TRUE;
		fetch_combo_sprite(&(self->sprite.sprite_data), self->no);
	}

	if (self->lifetime < self->sprite.current && self->active == SDL_TRUE)
	{
		active = SDL_FALSE;
		self->no = 0;
		self->sprite.current = 0;
		*score += 100;
	}
	self->active = active;
}

void	final_combos(t_combo *mainhand, t_combo *offhand, t_combo *defense, t_combo *special)
{
	mainhand->sprite.current = mainhand->lifetime + 1;
	offhand->sprite.current = offhand->lifetime + 1;
	defense->sprite.current = defense->lifetime + 1;
	special->sprite.current = special->lifetime + 1;
}


void	update_combos(t_combo *mainhand, t_combo *offhand, t_combo *defense, t_combo *special, size_t *score)
{
	mainhand->sprite.current++;
	offhand->sprite.current++;
	defense->sprite.current++;
	special->sprite.current++;

	update_combo_active(mainhand, score);
	update_combo_active(offhand, score);
	update_combo_active(defense, score);
	update_combo_active(special, score);

	if (mainhand->active == SDL_TRUE) { SDLX_RenderQueue_Add(NULL, &(mainhand->sprite)); }
	if (offhand->active == SDL_TRUE) { SDLX_RenderQueue_Add(NULL, &(offhand->sprite)); }
	if (defense->active == SDL_TRUE) { SDLX_RenderQueue_Add(NULL, &(defense->sprite)); }
	if (special->active == SDL_TRUE) { SDLX_RenderQueue_Add(NULL, &(special->sprite)); }
}

void	combo_increment(t_combo *combo, SDL_Rect *hit)
{
	combo->no++;
	combo->sprite.current = 0;

	combo->sprite._dst.x = hit->x;
	combo->sprite._dst.y = hit->y;

	if (combo->sprite._dst.x > MID_PLAY_WIDTH)
		combo->sprite._dst.x += 20;
	else
		combo->sprite._dst.x -= 20;

	combo->sprite._dst.x = SDL_min(combo->sprite._dst.x, PLAY_WIDTH - 32);
	combo->sprite._dst.y = SDL_min(combo->sprite._dst.y, PLAY_HEIGHT - 32);

	combo->sprite._dst.x = SDL_max(combo->sprite._dst.x, 0 + 5);
	combo->sprite._dst.y = SDL_max(combo->sprite._dst.y, 0 + 5);
}

void	combo_init(t_combo *self)
{
	SDLX_new_Sprite(&(self->sprite));
	fetch_combo_sprite(&(self->sprite.sprite_data), 2);
	self->active = SDL_FALSE;
	self->no = 0;
	self->lifetime = 200;
	self->sprite._dst = (SDL_Rect){0, 0, 32, 32};
	self->sprite.dst = SDLX_NULL_SELF;
}