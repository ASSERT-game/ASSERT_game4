#include "main.h"
#include "entity.h"

t_wave_m	level_02(void)
{
	t_wave_m level_02 = {
		.wave_id = 1,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 2,

		.size = 3,
	};

	level_02.waves = SDL_malloc(sizeof(*(level_02.waves)) * level_02.size);

	level_02.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 16, SDL_FALSE, NULL};
	level_02.waves[0].wave_array = SDL_malloc(sizeof(*(level_02.waves[0].wave_array)) * level_02.waves[0].size);

	level_02.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_02.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 40, SDL_TRUE, {0, 14}, 0};
	level_02.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 56, SDL_TRUE, {0, -13}, 0};
	level_02.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 66, SDL_TRUE, {0, -6}, 0};

	level_02.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 70 + 0, SDL_TRUE, {0, 180 + 0}, 0};
	level_02.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 70 + 40, SDL_TRUE, {0, 180 + -6}, 0};
	level_02.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 70 + 56, SDL_TRUE, {0, 180 + -15}, 0};
	level_02.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 70 + 66, SDL_TRUE, {0, 180 + 13}, 0};

	level_02.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 140 + 0, SDL_TRUE, {0, 0}, 0};
	level_02.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 140 + 40, SDL_TRUE, {0, 8}, 0};
	level_02.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 140 + 56, SDL_TRUE, {0, 2}, 0};
	level_02.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 140 + 66, SDL_TRUE, {0, 0}, 0};

	level_02.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 210 + 0, SDL_TRUE, {0, 180 + 0}, 0};
	level_02.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 210 + 40, SDL_TRUE, {0, 180 + -2}, 0};
	level_02.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 210 + 56, SDL_TRUE, {0, 180 + -5}, 0};
	level_02.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 210 + 66, SDL_TRUE, {0, 180 + 17}, 0};


	level_02.waves[1] = (t_wave){0, WAVE_TICKS, 210 + 66 + 25, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_02.waves[1].wave_array = SDL_malloc(sizeof(*(level_02.waves[1].wave_array)) * level_02.waves[1].size);

	level_02.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0}, 0};

	level_02.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 30, SDL_TRUE, {0, 1}, 0};
	level_02.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 55, SDL_TRUE, {0, -1}, 0};
	level_02.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 70, SDL_TRUE, {0, 19}, 0};
	level_02.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 88, SDL_TRUE, {0, 13}, 0};
	level_02.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 92, SDL_TRUE, {0, -19}, 0};

	level_02.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0 + 110, SDL_TRUE, {0, 0 + 180}, 0};

	level_02.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 30 + 110, SDL_TRUE, {0, 1 + 180}, 0};
	level_02.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 55 + 110, SDL_TRUE, {0, -1 + 180}, 0};
	level_02.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 70 + 110, SDL_TRUE, {0, 19 + 180}, 0};
	level_02.waves[1].wave_array[10] =  (t_wave_elem){E_SLIME_BLUE, 0, 88 + 110, SDL_TRUE, {0, 13 + 180}, 0};
	level_02.waves[1].wave_array[11] =  (t_wave_elem){E_SLIME_BLUE, 0, 92 + 110, SDL_TRUE, {0, -19 + 180}, 0};

	level_02.waves[2] = (t_wave){0, WAVE_TICKS, 92 + 110 + 30, SDL_FALSE, SDL_FALSE, 24, SDL_FALSE, NULL};
	level_02.waves[2].wave_array = SDL_malloc(sizeof(*(level_02.waves[2].wave_array)) * level_02.waves[2].size);

	level_02.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_02.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 40, SDL_TRUE, {0, 1}, 0};
	level_02.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 65, SDL_TRUE, {0, -1}, 0};
	level_02.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 80, SDL_TRUE, {0, 19}, 0};
	level_02.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 98, SDL_TRUE, {0, 13}, 0};
	level_02.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 102, SDL_TRUE, {0, -19}, 0};

	level_02.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0 + 65, SDL_TRUE, {0, 0 + 180}, 0};
	level_02.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 40 + 65, SDL_TRUE, {0, 1 + 180}, 0};
	level_02.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 65 + 65, SDL_TRUE, {0, -1 + 180}, 0};
	level_02.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 80 + 65, SDL_TRUE, {0, 19 + 180}, 0};
	level_02.waves[2].wave_array[10] =  (t_wave_elem){E_SLIME_BLUE, 0, 98 + 65, SDL_TRUE, {0, 13 + 180}, 0};
	level_02.waves[2].wave_array[11] =  (t_wave_elem){E_SLIME_BLUE, 0, 102 + 65, SDL_TRUE, {0, -19 + 180}, 0};

	level_02.waves[2].wave_array[12] =  (t_wave_elem){E_SLIME_BLUE, 0, 0 + 150, SDL_TRUE, {0, 0}, 0};
	level_02.waves[2].wave_array[13] =  (t_wave_elem){E_SLIME_BLUE, 0, 40 + 150, SDL_TRUE, {0, 1}, 0};
	level_02.waves[2].wave_array[14] =  (t_wave_elem){E_SLIME_BLUE, 0, 65 + 150, SDL_TRUE, {0, -1}, 0};
	level_02.waves[2].wave_array[15] =  (t_wave_elem){E_SLIME_BLUE, 0, 80 + 150, SDL_TRUE, {0, 19}, 0};
	level_02.waves[2].wave_array[16] =  (t_wave_elem){E_SLIME_BLUE, 0, 98 + 150, SDL_TRUE, {0, 13}, 0};
	level_02.waves[2].wave_array[17] =  (t_wave_elem){E_SLIME_BLUE, 0, 102 + 150, SDL_TRUE, {0, -19}, 0};

	level_02.waves[2].wave_array[18] =  (t_wave_elem){E_SLIME_BLUE, 0, 0 + 200, SDL_TRUE, {0, 0 + 180}, 0};
	level_02.waves[2].wave_array[19] =  (t_wave_elem){E_SLIME_BLUE, 0, 40 + 200, SDL_TRUE, {0, 1 + 180}, 0};
	level_02.waves[2].wave_array[20] =  (t_wave_elem){E_SLIME_BLUE, 0, 65 + 200, SDL_TRUE, {0, -1 + 180}, 0};
	level_02.waves[2].wave_array[21] =  (t_wave_elem){E_SLIME_BLUE, 0, 80 + 200, SDL_TRUE, {0, 19 + 180}, 0};
	level_02.waves[2].wave_array[22] =  (t_wave_elem){E_SLIME_BLUE, 0, 100 + 200, SDL_TRUE, {0, 13 + 180}, 0};
	level_02.waves[2].wave_array[23] =  (t_wave_elem){E_SLIME_BLUE, 0, 112 + 200, SDL_TRUE, {0, -19 + 180}, 0};

	return level_02;
}