/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/09/20 01:17:25 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#ifdef EMCC
	#include <emscripten.h>
#endif

void	blaster_start(t_context *context)
{
	context->shouldQuit = SDL_FALSE;
	context->shouldChange = SDL_TRUE;

	context->meta = NULL;

	context->capture_texture = NULL;
	context->redo_init_fn = NULL;
	context->next_init_fn = level_select_init;

	context->init_fn = main_menu_init;
	context->wave_id = -1;

	TTF_Init();
	context->font = TTF_OpenFont(ASSETS"chary___.ttf", 150);
	context->font_outline = TTF_OpenFont(ASSETS"chary___.ttf", 150);
	TTF_SetFontOutline(context->font_outline, 3);

	unequip_weapon(&(context->mainhand));
	unequip_weapon(&(context->special));
	unequip_weapon(&(context->offhand));
	unequip_weapon(&(context->defense));
	context->mainhand = laser_cannon();

	SDL_memset(&(context->levels), 0, sizeof(context->levels));
	set_levels(&(context->levels));
	g_GameInput.key_mapper.map_arr = blaster_key_map(&(g_GameInput.key_mapper.amount));
	g_GameInput.pad_mapper.map_arr = blaster_pad_map(&(g_GameInput.pad_mapper.amount));

	context->levels[0][1].isUnlocked = SDL_TRUE;
	context->levels[0][2].isUnlocked = SDL_TRUE;
	context->levels[0][3].isUnlocked = SDL_TRUE;
	context->levels[0][4].isUnlocked = SDL_TRUE;

	context->levels[1][0].isUnlocked = SDL_TRUE;
	context->levels[1][1].isUnlocked = SDL_TRUE;
	context->levels[1][2].isUnlocked = SDL_TRUE;
	context->levels[1][3].isUnlocked = SDL_TRUE;
	context->levels[1][4].isUnlocked = SDL_TRUE;

	context->levels[2][0].isUnlocked = SDL_TRUE;
	context->levels[2][1].isUnlocked = SDL_TRUE;
	context->levels[2][2].isUnlocked = SDL_TRUE;
	context->levels[2][3].isUnlocked = SDL_TRUE;
	context->levels[2][4].isUnlocked = SDL_TRUE;

	context->levels[3][0].isUnlocked = SDL_TRUE;
	context->levels[3][1].isUnlocked = SDL_TRUE;
	context->levels[3][2].isUnlocked = SDL_TRUE;
	context->levels[3][3].isUnlocked = SDL_TRUE;
	context->levels[3][0].isUnlocked = SDL_TRUE;

	// context->mainhand = faser_cannon();
	// context->offhand = ghostfire_cannon();
	// context->defense = shield_cannon();
	// context->special = emp_cannon();

	context->post_process = SDL_CreateTexture(SDLX_GetDisplay()->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_WIDTH, WIN_HEIGHT);
	context->hit = SDL_FALSE;
	context->timer = 0;
}

void	main_loop(void *context_addr)
{
	t_context	*context;

	context = context_addr;
	if (context->shouldChange == SDL_TRUE)
	{
		context->init_fn(context, context->meta);
		context->shouldChange = SDL_FALSE;
	}

	context->shouldQuit = SDLX_poll();
	SDLX_record_input(NULL);
	SDLX_KeyMap(&(g_GameInput.key_mapper), g_GameInput.keystate);
	SDLX_GameInput_Mouse_Fill(&(g_GameInput), SDL_TRUE);

#ifndef EMCC
	SDL_GameController	*controller;
	controller = NULL;
	controller = SDLX_XboxController_link(0);
	if (controller != NULL)
	{
		SDLX_ControllerMap(&(g_GameInput.pad_mapper), controller);
		SDLX_FillXbox_Axis(&(g_GameInput), controller);

		int trigger = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
		if (trigger > 100)
			g_GameInput.GameInput.button_primleft = 1;
	}
#endif

	context->update_fn(context, context->meta);

	if (context->shouldQuit != SDL_TRUE && SDLX_discrete_frames(NULL) != EXIT_FAILURE)
	{
		static int angle = 0;
		SDLX_RenderQueue_Flush(NULL, NULL, SDL_TRUE);

		SDL_SetRenderTarget(SDLX_GetDisplay()->renderer, NULL);
		if (context->hit && context->timer < 5)
		{
			SDL_RenderCopyEx(SDLX_GetDisplay()->renderer, context->post_process, NULL, NULL, SDL_sin(angle * 2) * .5, NULL, SDL_FLIP_NONE);
			context->timer++;
			angle++;
		}
		else
		{
			SDL_RenderCopyEx(SDLX_GetDisplay()->renderer, context->post_process, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
			angle = 0;
			context->timer = 0;
			context->hit = SDL_FALSE;
		}

		SDL_RenderPresent(SDLX_GetDisplay()->renderer);
		SDL_SetRenderTarget(SDLX_GetDisplay()->renderer, context->post_process);

		if (SDLX_GetBackground() != NULL)
			SDLX_DrawAnimation(SDLX_GetDisplay()->renderer, SDLX_GetBackground());
	}

	if (context->shouldChange == SDL_TRUE)
	{
		context->timer = 0;
		context->hit = SDL_FALSE;
		SDLX_CollisionBucket_Flush(NULL);
		SDLX_RenderQueue_Flush(NULL, SDLX_GetDisplay()->renderer, SDL_FALSE);

		context->close_fn(context, context->meta);
	}
}

int	main(void)
{
	t_context	context;

	SDLX_GetDisplay();
	blaster_start(&context);

	#ifdef EMCC
		emscripten_set_main_loop_arg(main_loop, (void *)&(context), 0, SDL_TRUE);
	#else
		while (context.shouldQuit == SDL_FALSE)
			main_loop(&(context));
	#endif

	return (EXIT_SUCCESS);
}
