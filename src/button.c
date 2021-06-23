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

void	*button_trigger_scene_switch(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length)
{
	t_context *context;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		context = vp_context;

		context->init_fn = self->meta1;
		context->scene = SDL_FALSE;
	}

	return (NULL);
}

void	*button_pause(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length)
{
	// t_context *context;
	SDL_bool	*pause_hint;

	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		pause_hint = pause_addr;
		*pause_hint = SDL_TRUE;
		g_GameInput_prev.GameInput.button_primleft = 0;
	}
	(void)self;

	return (NULL);
}

void	*button_resume(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length)
{
	SDL_bool	*pause;
	SDLX_button	*button;
	SDL_Texture	**pbackground;

	button = self;
	if (SDLX_GAME_RELEASE(g_GameInput, g_GameInput_prev, primleft))
	{
		pause = pause_addr;
		*pause = SDL_FALSE;
		g_GameInput_prev.GameInput.button_primleft = 0;

		pbackground = self->meta1;
		SDL_DestroyTexture(*pbackground);
		*pbackground = NULL;
	}

	return (NULL);
}