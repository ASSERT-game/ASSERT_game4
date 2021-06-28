/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/06/28 03:28:46 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	blaster_start(t_context *context)
{
	context->exit = SDL_FALSE;
	context->scene = SDL_FALSE;

	context->ticks = 0;

	context->meta = NULL;

	context->capture_texture = NULL;
	context->redo_init_fn = NULL;

	context->init_fn = main_menu_init;

	unequip_weapon(&(context->mainhand));
	unequip_weapon(&(context->special));
	unequip_weapon(&(context->shield));
	unequip_weapon(&(context->heal));

	context->mainhand = laser_cannon();
	// context->shield = laser_green_cannon();
	context->heal = heal_cannon();

	SDL_memset(&(context->levels), 0, sizeof(context->levels));

	context->levels[0][0].unlocked = SDL_TRUE;
	context->levels[0][1].unlocked = SDL_TRUE;
	context->levels[0][2].unlocked = SDL_TRUE;

	context->levels[0][0].init_fn = level_01_init;
	context->levels[0][1].init_fn = level_02_init;
	context->levels[0][2].init_fn = level_03_init;
	// context->levels[0][3].init_fn = level_04_init;
	// context->levels[0][4].init_fn = level_05_init;
	// context->levels[1][0].init_fn = level_06_init;
	// context->levels[1][1].init_fn = level_07_init;
	// context->levels[1][2].init_fn = level_08_init;
	// context->levels[1][3].init_fn = level_09_init;
	// context->levels[1][4].init_fn = level_10_init;
	// context->levels[2][0].init_fn = level_11_init;
	// context->levels[2][1].init_fn = level_12_init;
	// context->levels[2][2].init_fn = level_13_init;
	// context->levels[2][3].init_fn = level_14_init;
	// context->levels[2][4].init_fn = level_15_init;
	// context->levels[3][0].init_fn = level_16_init;
	// context->levels[3][1].init_fn = level_17_init;
	// context->levels[3][2].init_fn = level_18_init;
	// context->levels[3][3].init_fn = level_19_init;
	// context->levels[3][4].init_fn = level_20_init;
	// context->levels[4][0].init_fn = level_21_init;
	// context->levels[4][1].init_fn = level_22_init;
	// context->levels[4][2].init_fn = level_23_init;
	// context->levels[4][3].init_fn = level_24_init;
	// context->levels[4][4].init_fn = level_25_init;

	// context->init_fn = first_level_init;
	// context->init_fn = level_select_init;
}

int	main(void)
{
	t_context	context;

	blaster_start(&context);
	while (context.exit == SDL_FALSE)
	{

		context.init_fn(&context, context.meta);

		while (context.scene == SDL_TRUE && context.exit == SDL_FALSE)
		{
			context.exit = SDLX_poll();

			SDLX_GameInput_Mouse_Fill(&(g_GameInput), SDL_TRUE);

			context.update_fn(&context, context.meta);

			if (context.exit != SDL_TRUE && SDLX_discrete_frames(&(context.ticks)) != EXIT_FAILURE)
			{
				SDLX_RenderQueue_Flush(NULL, NULL, SDL_TRUE);
				SDLX_ScreenReset(SDLX_GetDisplay()->renderer, NULL);
			}
			SDLX_record_input(NULL);
		}

		context.close_fn(&context, context.meta);

	}
	return (EXIT_SUCCESS);
}
