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

#ifndef MAIN_H
# define MAIN_H

# include "SDL2/SDL_image.h"
# include "SDL2/SDL_ttf.h"

# include "SDLX/SDLX.h"

# include "entity.h"
# include "main_enums.h"
# include "main_structs.h"
# include "scenes.h"
# include "sprites.h"
# include "waves.h"

# define ASSETS "assets/"

//PLAY WINDOW is {304x352}
# define PLAY_WIDTH (WIN_WIDTH / DISPLAY_SCALE)
# define BOTTOM_UI (16 * 7)
# define PLAY_HEIGHT ((WIN_HEIGHT / DISPLAY_SCALE) - BOTTOM_UI)

# define MID_PLAY_WIDTH (PLAY_WIDTH / 2)
# define MID_PLAY_HEIGHT (PLAY_HEIGHT / 2)

/*
** Wave Functions
*/

t_enemy		*spawn_enemy_addr(t_enemy_m *manager);
void		init_enemy_array(t_enemy_m *manager);
void		iter_enemies(t_enemy_m *enemies);

SDL_bool	wave_method(t_wave_m *wave, t_enemy_m *enemy_man, t_attacks *projectiles);
int			wave_enemy_count(t_wave_m *stage);

/*
** Attack/Projectile Functions
*/

void		projectile_update(t_attacks *queue);
void		init_attack_array(t_attacks *attacks);
t_bullet	*spawn_projectile_addr(t_attacks *dst);

void	unequip_weapon(t_weapon *dst);
void	load_weapons(t_context *context, t_weapon **player_weapon_addr, SDLX_button *mainhand, SDLX_button *offhand, SDLX_button *defense, SDLX_button *special);
void	update_cooldowns(t_weapon *mainhand, t_weapon *offhand, t_weapon *defense, t_weapon *special);

void	crosshair_init(SDLX_Sprite *crosshair);
void	update_crosshair(SDLX_Sprite *crosshair);


/*
** Game System/Mechanics Functions
*/

void	update_status(t_enemy *self);

void	final_combos(t_combo *mainhand, t_combo *offhand, t_combo *defense, t_combo *special);
void	update_combos(t_combo *mainhand, t_combo *offhand, t_combo *defense, t_combo *special, size_t *score);
void	combo_increment(t_combo *combo, SDL_Rect *hit);
void	combo_init(t_combo *self);

/*
** Button Functions
*/

void	*button_trigger_scene_switch(SDLX_button *self, void *meta, SDL_UNUSED size_t length);
void	*button_pause(SDLX_button *self, void *vp_context, SDL_UNUSED size_t length);
void	*button_pause_key(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t length);
void	*button_resume(SDLX_button *self, void *pause_addr, SDL_UNUSED size_t length);

void	*button_chest(SDLX_button *self, SDL_UNUSED void *vp_context, SDL_UNUSED size_t length);
void	*button_chest_update(SDLX_button *self, SDL_UNUSED void *vp_context, SDL_UNUSED size_t length);

void	*button_carousel_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length);
void	*button_equip_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length);
void	*button_unequip_weapon(SDLX_button *self, SDL_UNUSED void *addr, SDL_UNUSED size_t length);

void	ability_button_init(SDLX_button *dst, t_weapon **player_equip_addr, t_weapon *to);

void	*new_scene(size_t size, t_context *context, char *background_path, t_scene_fn close, t_scene_fn update);
void	end_scene(t_context *context, SDLX_button *pause);

/*
** UI Functions
*/

void	pause_menu_init(t_pmenu *menu, void *pause_addr, void *pbackground, void *context, void *restart_fn);
void	update_pause_menu(t_pmenu *menu, SDL_Texture *pbackground);
void	level_ui_init(SDLX_button *pause, SDLX_Sprite *bottom);

/*
** Misc. Functions
*/

uint32_t	lerp32(double percent, uint32_t start, uint32_t end);
double		ptoa(int x, int y);

void		circle_spawn(int *x, int *y, int radius, double angle);

SDLX_iMap	*blaster_key_map(size_t *size);
SDLX_iMap	*blaster_pad_map(size_t *size);
void		set_levels(t_level_progress (*levels)[5][5]);

/*
** TTF Text Functions
*/

void	update_text(t_text *text, size_t size);
void	create_text(t_text *dst, int color, SDL_Rect loc, char *message, double scale, TTF_Font *font);
void	change_message(t_text *text, char *to, SDL_bool allocate);

#endif

