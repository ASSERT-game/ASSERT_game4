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
# include "scenes.h"

# define ASSETS "assets/"

/*
** Sprite Handlers
*/

int		fetch_coin_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_ui_sprite(SDLX_Sprite_Data **dst, int sprite_id);
int		fetch_level_select_sprite(SDLX_Sprite_Data **dst, int no);

/*
** Attack/Projectile Functions
*/

void	projectile_update(t_attacks *queue);
void	projectile_queue(t_attacks *attacks);
void	projectile_add(t_attacks *dst, t_bullet src);

void	unequip_weapon(t_weapon *dst);
void	load_weapons(t_context *context, t_weapon **player_weapon_addr, SDLX_button *mainhand, SDLX_button *shield, SDLX_button *heal, SDLX_button *special);
void	update_cooldowns(t_weapon *mainhand, t_weapon *shield, t_weapon *heal, t_weapon *special);

/*
** Button Functions
*/

void	*button_trigger_scene_switch(SDLX_button *self, void *meta, SDL_UNUSED size_t length);
void	*button_pause(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length);
void	*button_resume(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length);

void	ability_button_init(SDLX_button *dst, t_weapon **player_equip_addr, t_weapon *to);

void	*new_scene(size_t size, t_context *context, char *background_path, t_scene_fn close, t_scene_fn update);

/*
** Misc. Functions
*/

uint32_t	lerp32(double percent, uint32_t start, uint32_t end);

#endif

