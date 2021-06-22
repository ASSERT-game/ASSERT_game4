/***************************************************************************
 * FILENAME:    scene_utils.c
 * DESCRIPTION: Utility functions for scenes
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

void	*new_scene(size_t size, t_context *context, char *background_path)
{
	void *result;

	result = SDL_malloc(size);
	context->meta = result;
	context->scene = SDL_TRUE;

	context->background = SDLX_Sprite_Static(background_path);
	SDLX_set_background(&(context->background));
	return (result);
}