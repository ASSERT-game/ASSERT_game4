/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef main_H
# define main_H

# include <SDL_image.h>

# include "SDLX.h"

# define ASSETS "assets/"

typedef struct	s_context
{
	SDL_bool	exit;
	SDL_bool	scene;

	void		*meta;
	void		*meta_catch;

	void		*(*init_fn)(struct s_context *, void *, int);
	void		*(*update_fn)(struct s_context *, void *, int);
	void		*(*close_fn)(struct s_context *, void *, int);

	int			ticks;
	SDLX_RenderQueue	queue;
}				t_context;

void			*main_menu_init(t_context *context, void *meta, int ticks);
void			*main_menu_close(t_context *context, void *meta, int ticks);
void			*main_menu_update(t_context *context, void *meta, int ticks);

void			*level_select_init(t_context *context, void *level, int tick);
void			*level_select_close(t_context *context, void *level, int tick);
void			*level_select_update(t_context *context, void *level, int tick);

void			*first_level_init(t_context *context, void *level, int tick);
void			*first_level_close(t_context *context, void *level, int tick);
void			*first_level_update(t_context *context, void *level, int tick);

enum	BLASTER_UI_SPRITES
{
	PLAY_NORM,
	PLAY_HOVER,
	CREDIT_NORM,
	CREDIT_HOVER,
	PAUSE_NORM,
};

int				fetch_ui_sprite(SDLX_Sprite_Data **dst, int sprite_id);

#endif
