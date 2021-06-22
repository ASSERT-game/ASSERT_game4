/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/06/21 19:01:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	blaster_start(t_context *context)
{
	context->exit = SDL_FALSE;
	context->scene = SDL_FALSE;

	context->meta = NULL;

	context->init_fn = main_menu_init;
	context->update_fn = main_menu_update;
	context->close_fn = main_menu_close;

	// context->init_fn = first_level_init;
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
			if (context.exit != SDL_TRUE && SDLX_discrete_frames(NULL) != EXIT_FAILURE)
			{
				SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);
				SDLX_screen_reset(SDLX_GetDisplay()->renderer, NULL);
			}
			SDLX_record_input(NULL);
		}

		context.close_fn(&context, context.meta);

	}
	return (EXIT_SUCCESS);
}
