/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDLX_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 01:10:16 by home              #+#    #+#             */
/*   Updated: 2021/06/04 02:09:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDLX.h"

void	*SDLX_Button_NULL_fn(SDL_UNUSED SDLX_button *button, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length)
{
	return NULL;
}

SDL_bool	SDLX_Button_onHoverFocus(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length)
{
	SDL_bool	result;
	SDL_Point	*mouse;
	SDL_Point	*mouse_delta;

	result = SDL_FALSE;
	mouse = &(g_GameInput.GameInput.primary);
	mouse_delta = &(g_GameInput.GameInput.primary_delta);
	if ((mouse_delta->x != 0 || mouse_delta->y != 0) && SDL_PointInRect(mouse, &(self->trigger_box)))
		result = SDL_TRUE;

	if (self->focused == SDL_TRUE)
		result = SDL_TRUE;

	if ((mouse_delta->x != 0 || mouse_delta->y != 0) && SDL_PointInRect(mouse, &(self->trigger_box)) == SDL_FALSE)
		result = SDL_FALSE;

	return (result);
}

int	SDLX_Button_Init(SDLX_button *dst, int (*sprite_fn)(SDLX_Sprite_Data **, int), int sprite_no, SDL_Rect placement, SDLX_RenderQueue *render_dst)
{
	dst->render_dst = render_dst;

	dst->sprite_fn = sprite_fn;

	SDLX_new_Sprite(&(dst->sprite));
	dst->sprite_fn(&(dst->sprite.sprite_data), sprite_no);
	dst->sprite._dst = placement;

	dst->trigger_box = dst->sprite._dst;

	dst->norm_no = -1;
	dst->focus_no = -1;

	dst->disabled = SDL_FALSE;

	dst->global_active = SDL_FALSE;
	dst->focused = SDL_FALSE;
	dst->triggered = SDL_FALSE;

	dst->meta = NULL;
	dst->meta_length = 0;

	dst->get_focus_fn = SDLX_Button_onHoverFocus;

	dst->focus_fn = SDLX_Button_NULL_fn;
	dst->focus_once_fn = SDLX_Button_NULL_fn;
	dst->trigger_fn = SDLX_Button_NULL_fn;
	dst->update_fn = SDLX_Button_NULL_fn;

	return (EXIT_SUCCESS);
}

void	SDLX_Style_Button(SDLX_button *button, int norm, int hover)
{
	button->focus_no = hover;
	button->norm_no = norm;
}

void	SDLX_Button_Set_fn(SDLX_button *button,
			SDL_bool (*get_focus_fn)(struct SDLX_button *, void *, size_t),
			void *(*focus_fn)(struct SDLX_button *, void *, size_t),
			void *(*focus_once_fn)(struct SDLX_button *, void *, size_t),
			void *(*trigger_fn)(struct SDLX_button *, void *, size_t),
			void *(*update_fn)(struct SDLX_button *, void *, size_t))
{
	button->get_focus_fn = get_focus_fn;
	button->focus_fn = focus_fn;
	button->focus_once_fn = focus_once_fn;
	button->trigger_fn = trigger_fn;
	button->update_fn = update_fn;
}

void	SDLX_Button_Set_UDLR(SDLX_button *button, void *up, void *down, void *left, void *right)
{
	button->up = up;
	button->down = down;
	button->left = left;
	button->right = right;
}

void	SDLX_Button_ReFocus(SDLX_button *button)
{
	button->focus_once_fn(button, button->meta, button->meta_length);
	if (button->focus_no != -1)
	{
		button->sprite_fn(&(button->sprite.sprite_data), button->focus_no);
		button->sprite.current = 0;
	}
	button->focused = SDL_TRUE;
}

void	SDLX_Button_Focus(SDLX_button *button)
{
	if (button->focused == SDL_FALSE) // This activates on-hover, aka once
		SDLX_Button_ReFocus(button);
	else //This continues to activate on hover
		button->focus_fn(button, button->meta, button->meta_length);

	// always active
	button->trigger_fn(button, button->meta, button->meta_length);
}

void	SDLX_Button_Lose_Focus(SDLX_button *button)
{
	if (button->norm_no != -1)
	{
		button->sprite_fn(&(button->sprite.sprite_data), button->norm_no);
		button->sprite.current = 0;
	}
	button->focused = SDL_FALSE;
}

/*
// Updates the button based on the data saved in the button class.
// The button has functions for on trigger, on focus, continued focus#include "../aoc++.h"
// These function should go after all changes, allowing the user to revert
// them if they do not want the automatic changes. This also allows the user to
// create a copy and be able to preform shallow copies.
*/

void	SDLX_Button_Update(SDLX_button *button)
{
	SDL_bool	get_focus;

	if (button->disabled == SDL_TRUE)
		return ;

	get_focus = button->get_focus_fn(button, button->meta, button->meta_length);
	if (get_focus == SDL_TRUE) //This could be 'in focus triggers'
		SDLX_Button_Focus(button);
	else if (button->focused == SDL_TRUE && get_focus == SDL_FALSE) // Was focused but no longer
		SDLX_Button_Lose_Focus(button);

	button->update_fn(button, button->meta, button->meta_length);

	if (button->global_active == SDL_TRUE)
		button->trigger_fn(button, button->meta, button->meta_length);

	SDLX_RenderQueue_add(button->render_dst, &(button->sprite));
	button->sprite.current++;
}