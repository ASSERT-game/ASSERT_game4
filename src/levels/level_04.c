#include "main.h"
#include "entity.h"

t_wave_m	level_04(void)
{
	t_wave_m level_04 = {
		.wave_id = 3,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 3,

		.size = 4,
	};

	level_04.waves = SDL_malloc(sizeof(*(level_04.waves)) * level_04.size);


	level_04.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 42, SDL_FALSE, NULL};
	level_04.waves[0].wave_array = SDL_malloc(sizeof(*(level_04.waves[0].wave_array)) * level_04.waves[0].size);

	int t = 18;
	level_04.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, -22 + 0}, 0};
	level_04.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,  SDL_TRUE, {0, -20 + 180}, 0};
	level_04.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2,  SDL_TRUE, {0, 0 + 0}, 0};
	level_04.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,  SDL_TRUE, {0, -31 + 180}, 0};
	level_04.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,  SDL_TRUE, {0, -11 + 0}, 0};
	level_04.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,  SDL_TRUE, {0, -23 + 180}, 0};
	level_04.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,  SDL_TRUE, {0, 17 + 0}, 0};
	level_04.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7,  SDL_TRUE, {0, 11 + 180}, 0};
	level_04.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,  SDL_TRUE, {0, 21 + 0}, 0};
	level_04.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,  SDL_TRUE, {0, 21 + 180}, 0};
	level_04.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, -19 + 0}, 0};
	level_04.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 1 + 180}, 0};
	level_04.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, -20 + 0}, 0};
	level_04.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, -28 + 180}, 0};
	level_04.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, -29 + 0}, 0};
	level_04.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, -6 + 180}, 0};
	level_04.waves[0].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, -18 + 0}, 0};
	level_04.waves[0].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 26 + 180}, 0};
	level_04.waves[0].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 11 + 0}, 0};
	level_04.waves[0].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 9 + 180}, 0};
	level_04.waves[0].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 5 + 0}, 0};
	level_04.waves[0].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 34 + 180}, 0};
	level_04.waves[0].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22,  SDL_TRUE, {0, 0 + 0}, 0};
	level_04.waves[0].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23,  SDL_TRUE, {0, -31 + 180}, 0};
	level_04.waves[0].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24,  SDL_TRUE, {0, -11 + 0}, 0};
	level_04.waves[0].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25,  SDL_TRUE, {0, -23 + 180}, 0};
	level_04.waves[0].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26,  SDL_TRUE, {0, 17 + 0}, 0};
	level_04.waves[0].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27,  SDL_TRUE, {0, 11 + 180}, 0};
	level_04.waves[0].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28,  SDL_TRUE, {0, 21 + 0}, 0};
	level_04.waves[0].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29,  SDL_TRUE, {0, 21 + 180}, 0};
	level_04.waves[0].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 30, SDL_TRUE, {0, -19 + 0}, 0};
	level_04.waves[0].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 31, SDL_TRUE, {0, 1 + 180}, 0};
	level_04.waves[0].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, t * 32, SDL_TRUE, {0, -20 + 0}, 0};
	level_04.waves[0].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, t * 33, SDL_TRUE, {0, -28 + 180}, 0};
	level_04.waves[0].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, t * 34, SDL_TRUE, {0, -29 + 0}, 0};
	level_04.waves[0].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, t * 35, SDL_TRUE, {0, -6 + 180}, 0};
	level_04.waves[0].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, t * 36, SDL_TRUE, {0, -18 + 0}, 0};
	level_04.waves[0].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, t * 37, SDL_TRUE, {0, 26 + 180}, 0};
	level_04.waves[0].wave_array[38] = (t_wave_elem){E_SLIME_BLUE, 0, t * 38, SDL_TRUE, {0, 11 + 0}, 0};
	level_04.waves[0].wave_array[39] = (t_wave_elem){E_SLIME_BLUE, 0, t * 39, SDL_TRUE, {0, 9 + 180}, 0};
	level_04.waves[0].wave_array[40] = (t_wave_elem){E_SLIME_BLUE, 0, t * 40, SDL_TRUE, {0, 5 + 0}, 0};
	level_04.waves[0].wave_array[41] = (t_wave_elem){E_SLIME_BLUE, 0, t * 41, SDL_TRUE, {0, 34 + 180}, 0};

	level_04.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_04.waves[1].wave_array = SDL_malloc(sizeof(*(level_04.waves[1].wave_array)) * level_04.waves[1].size);

	int a = 16;

	t = 15;
	level_04.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 0 * a}, 0};
	level_04.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 1 * a}, 0};
	level_04.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 2 * a}, 0};
	level_04.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 3 * a}, 0};
	level_04.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 4 * a}, 0};
	level_04.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 5 * a}, 0};
	level_04.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 6 * a}, 0};
	level_04.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 7 * a}, 0};
	level_04.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 8 * a}, 0};
	level_04.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 9 * a}, 0};
	level_04.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 10 * a}, 0};
	level_04.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 11 * a}, 0};
	level_04.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 12 * a}, 0};
	level_04.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 13 * a}, 0};
	level_04.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 14 * a}, 0};
	level_04.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 15 * a}, 0};

	level_04.waves[2] = (t_wave){0, WAVE_TICKS, t * 15 + 30, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_04.waves[2].wave_array = SDL_malloc(sizeof(*(level_04.waves[2].wave_array)) * level_04.waves[2].size);

	a = -16;
	level_04.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 0 * a}, 0};
	level_04.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 1 * a}, 0};
	level_04.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 2 * a}, 0};
	level_04.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 3 * a}, 0};
	level_04.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 4 * a}, 0};
	level_04.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 5 * a}, 0};
	level_04.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 6 * a}, 0};
	level_04.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 7 * a}, 0};
	level_04.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 8 * a}, 0};
	level_04.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 9 * a}, 0};
	level_04.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 10 * a}, 0};
	level_04.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 11 * a}, 0};
	level_04.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 12 * a}, 0};
	level_04.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 13 * a}, 0};
	level_04.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 14 * a}, 0};
	level_04.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 15 * a}, 0};

	level_04.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 1, SDL_FALSE, NULL};
	level_04.waves[3].wave_array = SDL_malloc(sizeof(*(level_04.waves[3].wave_array)) * level_04.waves[3].size);

	level_04.waves[3].wave_array[0] = (t_wave_elem){E_SLIME_CYAN, 0, 10, SDL_TRUE, {0, 0}, 0};

	return level_04;
}