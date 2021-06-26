/***************************************************************************
 * FILENAME:    scenes.h
 * DESCRIPTION: Header file with all the scenes in the game.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 26Jun2021
***************************************************************************/

#ifndef SCENES_H
# define SCENES_H

#include "main_structs.h"

void	*main_menu_init(t_context *context, void *vp_scene);
void	*main_menu_close(t_context *context, void *vp_scene);
void	*main_menu_update(t_context *context, void *vp_scene);

void	*level_select_init(t_context *context, void *vp_scene);
void	*level_select_close(t_context *context, void *vp_scene);
void	*level_select_update(t_context *context, void *vp_scene);

void	*first_level_init(t_context *context, void *vp_scene);
void	*first_level_close(t_context *context, void *vp_scene);
void	*first_level_update(t_context *context, void *vp_scene);

void	*death_level_init(t_context *context, void *vp_scene);
void	*death_level_close(t_context *context, void *vp_scene);
void	*death_level_update(t_context *context, void *vp_scene);

void	*loot_level_init(t_context *context, SDL_UNUSED void *vp_scene);
void	*loot_level_close(t_context *context, SDL_UNUSED void *vp_scene);
void	*loot_level_update(t_context *context, SDL_UNUSED void *vp_scene);

#endif