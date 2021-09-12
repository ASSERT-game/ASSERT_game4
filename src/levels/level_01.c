#include "main.h"
#include "entity.h"

t_wave_m	level_01(void)
{
	t_wave_m level_01 = {
		.wave_id = 0,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 1,

		.size = 2,
	};

	level_01.waves = SDL_malloc(sizeof(*(level_01.waves)) * level_01.size);


	level_01.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 8, SDL_FALSE, NULL};
	level_01.waves[0].wave_array = SDL_malloc(sizeof(*(level_01.waves[0].wave_array)) * level_01.waves[0].size);

	level_01.waves[0].wave_array[0] = (t_wave_elem){E_SLIME_BLUE, 3, 0, SDL_TRUE, {0, 0}, 0};

	level_01.waves[0].wave_array[1] = (t_wave_elem){E_SLIME_BLUE, 3, 50, SDL_TRUE, {0, 30}, 0};
	level_01.waves[0].wave_array[2] = (t_wave_elem){E_SLIME_BLUE, 3, 50, SDL_TRUE, {0, -30}, 0};

	// level_01.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 5, SDL_FALSE, NULL};
	// level_01.waves[1].wave_array = SDL_malloc(sizeof(*(level_01.waves[1].wave_array)) * level_01.waves[1].size);

	level_01.waves[0].wave_array[3] = (t_wave_elem){E_SLIME_BLUE, 3, 65 + 14, SDL_TRUE, {0, 29}, 0};
	level_01.waves[0].wave_array[4] = (t_wave_elem){E_SLIME_BLUE, 3, 65 + 50, SDL_TRUE, {0, -42}, 0};
	level_01.waves[0].wave_array[5] = (t_wave_elem){E_SLIME_BLUE, 3, 65 + 56, SDL_TRUE, {0, -4}, 0};
	level_01.waves[0].wave_array[6] = (t_wave_elem){E_SLIME_BLUE, 3, 65 + 114, SDL_TRUE, {0, -25}, 0};
	level_01.waves[0].wave_array[7] = (t_wave_elem){E_SLIME_BLUE, 3, 65 + 109, SDL_TRUE, {0, 25}, 0};

	level_01.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 15, SDL_FALSE, NULL};
	level_01.waves[1].wave_array = SDL_malloc(sizeof(*(level_01.waves[1].wave_array)) * level_01.waves[1].size);

	level_01.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 3, 0, SDL_TRUE, {0, 8}, 0};
	level_01.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 3, 14, SDL_TRUE, {0, 13}, 0};
	level_01.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 3, 28, SDL_TRUE, {0, 37}, 0};
	level_01.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 3, 42, SDL_TRUE, {0, -27}, 0};
	level_01.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 3, 56, SDL_TRUE, {0, 22}, 0};
	level_01.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 3, 70, SDL_TRUE, {0, -44}, 0};
	level_01.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 3, 84, SDL_TRUE, {0, 5}, 0};
	level_01.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 3, 98, SDL_TRUE, {0, -25}, 0};
	level_01.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 3, 112, SDL_TRUE, {0, 8}, 0};
	level_01.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 3, 126, SDL_TRUE, {0, 37}, 0};
	level_01.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 3, 140, SDL_TRUE, {0, 16}, 0};
	level_01.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 3, 154, SDL_TRUE, {0, -8}, 0};
	level_01.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 3, 168, SDL_TRUE, {0, -3}, 0};
	level_01.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 3, 172, SDL_TRUE, {0, 21}, 0};
	level_01.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 3, 184, SDL_TRUE, {0, 40}, 0};

	return level_01;
}