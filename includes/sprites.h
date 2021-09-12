/***************************************************************************
 * FILENAME:    sprites.h
 * DESCRIPTION: Functions that fetch sprites.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jul2021
***************************************************************************/

#ifndef SPRITES_H
# define SPRITES_H

# include "SDLX/SDLX.h"

/*
** Sprite Handlers
*/

int		fetch_bunny_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_combo_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_chest_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_slime_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_ui_sprite(SDLX_Sprite_Data **dst, int sprite_id);
int		fetch_level_select_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_pause_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_loot_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_hp_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_cooldown_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_cooldown_ghost_sprite(SDLX_Sprite_Data **dst, int no);

int		fetch_lunge_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_red_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_emp_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_shield_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_ghostfire_sprite(SDLX_Sprite_Data **dst, int no);
int		fetch_faser_sprite(SDLX_Sprite_Data **dst, int no);

#endif