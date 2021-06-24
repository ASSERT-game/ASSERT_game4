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

# include "SDL2/SDL_image.h"

# include "SDLX/SDLX.h"

# include "main_structs.h"
# include "entity.h"

# define ASSETS "assets/"


/*
** Scene Functions
*/

void	*main_menu_init(t_context *context, void *vp_scene);
void	*main_menu_close(t_context *context, void *vp_scene);
void	*main_menu_update(t_context *context, void *vp_scene);

void	*level_select_init(t_context *context, void *vp_scene);
void	*level_select_close(t_context *context, void *vp_scene);
void	*level_select_update(t_context *context, void *vp_scene);

void	*first_level_init(t_context *context, void *vp_scene);
void	*first_level_close(t_context *context, void *vp_scene);
void	*first_level_update(t_context *context, void *vp_scene);

/*
** Sprite Handlers
*/

int		fetch_ui_sprite(SDLX_Sprite_Data **dst, int sprite_id);
int		fetch_level_select_sprite(SDLX_Sprite_Data **dst, int no);

/*
** Attack/Projectile Functions
*/

void	projectile_update(t_attacks *queue);
void	projectile_queue(t_attacks *attacks);
void	projectile_add(t_attacks *dst, t_bullet src);

/*
** Button Functions
*/

void	*button_trigger_scene_switch(SDLX_button *self, void *meta, SDL_UNUSED size_t length);
void	*button_pause(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length);
void	*button_resume(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length);

void	*new_scene(size_t size, t_context *context, char *background_path);

/*
** Misc. Functions
*/

uint32_t	lerp32(double percent, uint32_t start, uint32_t end);

#endif

