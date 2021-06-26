/***************************************************************************
 * FILENAME:    loot_scene.c
 * DESCRIPTION: Scene that displays upon winning a level.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 26Jun2021
***************************************************************************/

#include "main.h"

typedef struct	s_loot_scene
{
	SDLX_button	restart;
	SDLX_button	level_select;
	SDLX_button	inventory;

	SDL_Texture	*level_capture;
}				t_loot_scene;

void	*loot_level_init(t_context *context, SDL_UNUSED void *vp_scene)
{
	t_loot_scene	*scene;

	scene = new_scene(sizeof(*scene), context, NULL, loot_level_close, loot_level_update);

	return (NULL);
}

void	*loot_level_close(SDL_UNUSED t_context *context, SDL_UNUSED void *vp_scene)
{
	return (NULL);
}

void	*loot_level_update(SDL_UNUSED t_context *context, SDL_UNUSED void *vp_scene)
{
	return (NULL);
}
