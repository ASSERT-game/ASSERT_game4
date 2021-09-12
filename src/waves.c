/***************************************************************************
 * FILENAME:    waves.c
 * DESCRIPTION: Handles spawning of entities per level basis.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 16Jul2021
***************************************************************************/

#include "main.h"
#include "spawn_table.h"

SDL_bool	wave_should_begin(t_wave_m *wave, size_t i)
{
	SDL_bool	result;

	result = SDL_FALSE;
	if (wave->waves[i].condition_type == WAVE_TICKS)
	{
		if (wave->waves[i - 1].tick >= wave->waves[i].condition_info)
			result = SDL_TRUE;
	}

	if (wave->waves[i].condition_type == WAVE_PREV_DEFEAT)
	{
		if (wave->waves[i - 1 - wave->waves[i].condition_info].isComplete == SDL_TRUE)
			result = SDL_TRUE;
	}

	wave->waves[i].isActive = result;
	return (result);
}

void	spawn_elem(int type, t_enemy *spawn_addr, SDL_Point loc, int mod)
{
	size_t	i;
	size_t	size;
	void	(*spawn_fn)(t_enemy *, SDL_Point, int);

	i = 0;
	size = (sizeof(spawn_table) / sizeof(*spawn_table));
	spawn_fn = NULL;
	while (i + 1 < size && type != spawn_table[i].type)
		i++;

	spawn_fn = spawn_table[i].fn;

	SDL_assert(spawn_fn != NULL);
	spawn_fn(spawn_addr, loc, mod);
}

int		wave_enemy_count(t_wave_m *stage)
{
	size_t	ix;
	size_t	jx;
	int		enemy_count;

	ix = 0;
	enemy_count = 0;
	while (ix < stage->size)
	{
		jx = 0;
		while (jx < stage->waves[ix].size)
		{
			if (stage->waves[ix].wave_array[jx].shouldCount)
				enemy_count++;
			jx++;
		}
		ix++;
	}
	return (enemy_count);
}


int		do_wave(t_wave *wave, t_enemy_m *enemy_man, t_attacks *projectiles)
{
	size_t	i;
	t_enemy	*spawn_addr;

	i = 0;
	while (i < wave->size)
	{
		if (wave->tick == wave->wave_array[i].spawn_tick)
		{
			spawn_addr = spawn_enemy_addr(enemy_man);
			spawn_elem(wave->wave_array[i].type, spawn_addr, wave->wave_array[i].spawn_location, wave->wave_array[i].modifier);
			if (wave->wave_array[i].shouldCount == SDL_TRUE)
				spawn_addr->score_ptr = &(wave->finished_no);
			spawn_addr->spawn_pool = enemy_man;
			spawn_addr->projectile_spawn = projectiles;
		}
		i++;
	}

	wave->tick++;

	if (wave->finished_no >= wave->size)
	{
		wave->isComplete = SDL_TRUE;
		return (1);
	}
	return (0);

}

SDL_bool	wave_method(t_wave_m *wave, t_enemy_m *enemy_man, t_attacks *projectiles)
{
	size_t	i;
	size_t	killed;

	i = 0;
	killed = 0;
	while (i < wave->size)
	{
		if (wave->waves[i].isComplete == SDL_FALSE && (wave->waves[i].isActive || wave_should_begin(wave, i)))
			wave->completed_no += do_wave(&(wave->waves[i]), enemy_man, projectiles);
		killed += wave->waves[i].finished_no;
		i++;
	}

	wave->killed_no = killed;
	if (wave->completed_no >= wave->win_wave_no && killed >= wave->win_kill_count)
	{
		if (wave->win_wave == -1)
			return (SDL_TRUE);
		else if (wave->waves[wave->win_wave].isComplete == SDL_TRUE)
			return (SDL_TRUE);
	}
	return (SDL_FALSE);
}
