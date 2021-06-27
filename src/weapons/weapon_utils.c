/***************************************************************************
 * FILENAME:    weapn_utils.c
 * DESCRIPTION: Utility functions for weapon struct.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 26Jun2021
***************************************************************************/

#include "main.h"

void	empty_weapon_factory(SDL_UNUSED t_bullet *loc, SDL_UNUSED SDL_Point spawn, SDL_UNUSED double angle, SDL_UNUSED void *meta)
{
	return ;
}

void	unequip_weapon(t_weapon *dst)
{
	dst->start = 0;
	dst->cooldown = 0;

	dst->curr = 0;

	dst->enabled = 0;
	dst->factory = empty_weapon_factory;
}

#define ABILITY_LEFT_PADDING (16)

void	load_weapons(t_context *context, t_weapon **player_weapon_addr, SDLX_button *mainhand, SDLX_button *shield, SDLX_button *heal, SDLX_button *special)
{
	size_t		i;
	size_t		ability_bar_width;
	size_t		ability_space;
	size_t		count;
	SDLX_button	*line[4];

	ability_button_init(mainhand, player_weapon_addr, &(context->mainhand));
	ability_button_init(shield, player_weapon_addr, &(context->shield));
	ability_button_init(heal, player_weapon_addr, &(context->heal));
	ability_button_init(special, player_weapon_addr, &(context->special));

	count = 0;
	if (context->mainhand.enabled == SDL_TRUE) { line[count] = mainhand; count++; }
	if (context->shield.enabled == SDL_TRUE) { line[count] = shield; count++; }
	if (context->heal.enabled == SDL_TRUE) { line[count] = heal; count++; }
	if (context->special.enabled == SDL_TRUE) { line[count] = special; count++; }

	i = 0;
	SDL_Log("%zu", count);
	SDL_assert(count != 0);
	ability_bar_width = 256 - ABILITY_LEFT_PADDING - ABILITY_LEFT_PADDING;
	ability_space = (ability_bar_width - (mainhand->sprite._dst.w * count)) / (count);
	while (i < count)
	{
		line[i]->sprite._dst.x = ABILITY_LEFT_PADDING + (i * (ability_space + 48)) + (ability_space / 2);
		i++;
	}
}