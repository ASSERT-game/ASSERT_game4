/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/06/15 22:26:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	blaster_start(t_context *context)
{
	context->exit = SDL_FALSE;
	context->scene = SDL_FALSE;

	context->meta = NULL;
	context->meta_catch = NULL;

	context->init_fn = main_menu_init;
	context->update_fn = main_menu_update;
	context->close_fn = main_menu_close;

	context->init_fn = first_level_init;

	context->ticks = 0;
}

int	main(void)
{
	t_context	context;

	blaster_start(&context);
	while (context.exit == SDL_FALSE)
	{

		context.init_fn(&context, context.meta, context.ticks);

		while (context.scene == SDL_TRUE && context.exit == SDL_FALSE)
		{
			context.exit = SDLX_poll();

			SDLX_GameInput_Mouse_Fill(&(g_GameInput), SDL_TRUE);

			context.update_fn(&context, context.meta, context.ticks);
			if (context.exit != SDL_TRUE && SDLX_discrete_frames(&(context.ticks)) != EXIT_FAILURE)
			{
				SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);
				SDLX_screen_reset(SDLX_GetDisplay()->renderer, NULL);
			}
			SDLX_record_input(NULL);
		}

		context.close_fn(&context, context.meta, context.ticks);

	}
	return (EXIT_SUCCESS);
}
