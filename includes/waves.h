/***************************************************************************
 * FILENAME:    waves.h
 * DESCRIPTION: Header for the struct that handles wave spawning.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 16Jul2021
***************************************************************************/

#ifndef WAVES_H
# define WAVES_H

# include "SDLX/SDLX.h"

typedef struct	s_wave_elem
{
	int			type;
	int			modifier;

	size_t		spawn_tick;

	SDL_bool	shouldCount;

	SDL_Point	spawn_location;

	//Unused yet.
	size_t		drop;
}				t_wave_elem;

enum	e_wave_con
{
	WAVE_TICKS,
	WAVE_PREV_DEFEAT,
	WAVE_OR_DEFEAT,
	WAVE_XAMOUNT,
	WAVE_CONT,
};

typedef struct	s_wave
{
	size_t		tick;

	size_t		condition_type;
	size_t		condition_info;

	SDL_bool	isComplete;
	SDL_bool	isActive;

	size_t		size;
	size_t		finished_no;

	t_wave_elem	*wave_array;

}				t_wave;

typedef struct	s_wave_m
{
	int			wave_id;
	size_t		tick;

	size_t		win_kill_count;
	size_t		win_wave_no;
	int			win_wave;

	SDL_bool	isComplete;
	size_t		completed_no;
	size_t		killed_no;

	size_t		size;
	t_wave		*waves;

}				t_wave_m;

#endif
