#include "main.h"
#include "entity.h"

t_wave_m	level_03(void)
{
	t_wave_m level_03 = {
		.wave_id = 2,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 2,

		.size = 3,
	};

	level_03.waves = SDL_malloc(sizeof(*(level_03.waves)) * level_03.size);

	level_03.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 10, SDL_FALSE, NULL};
	level_03.waves[0].wave_array = SDL_malloc(sizeof(*(level_03.waves[0].wave_array)) * level_03.waves[0].size);

	level_03.waves[0].wave_array[0] = (t_wave_elem){E_SLIME_BLUE, 0, 0,   SDL_TRUE, {0, 90}, 0};
	level_03.waves[0].wave_array[1] = (t_wave_elem){E_SLIME_BLUE, 0, 40,  SDL_TRUE, {0, 90 + 25}, 0};
	level_03.waves[0].wave_array[2] = (t_wave_elem){E_SLIME_BLUE, 0, 40,  SDL_TRUE, {0, 90 - 25}, 0};
	level_03.waves[0].wave_array[3] = (t_wave_elem){E_SLIME_BLUE, 0, 0,   SDL_TRUE, {0, 270}, 0};
	level_03.waves[0].wave_array[4] = (t_wave_elem){E_SLIME_BLUE, 0, 40,  SDL_TRUE, {0, 270 - 25}, 0};
	level_03.waves[0].wave_array[5] = (t_wave_elem){E_SLIME_BLUE, 0, 40,  SDL_TRUE, {0, 270 + 25}, 0};
	level_03.waves[0].wave_array[6] = (t_wave_elem){E_SLIME_BLUE, 0, 70,  SDL_TRUE, {0, 90 }, 0};
	level_03.waves[0].wave_array[7] = (t_wave_elem){E_SLIME_BLUE, 0, 100, SDL_TRUE, {0, 270 }, 0};
	level_03.waves[0].wave_array[8] = (t_wave_elem){E_SLIME_BLUE, 0, 125, SDL_TRUE, {0, 270 + 45}, 0};
	level_03.waves[0].wave_array[9] = (t_wave_elem){E_SLIME_BLUE, 0, 125, SDL_TRUE, {0, 270 - 45}, 0};

	level_03.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 36, SDL_FALSE, NULL};
	level_03.waves[1].wave_array = SDL_malloc(sizeof(*(level_03.waves[1].wave_array)) * level_03.waves[1].size);

	int t;

	t = 18;
	level_03.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 31 * t, SDL_TRUE, {0, 0}, 0};
	level_03.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 18 * t, SDL_TRUE, {0, 10}, 0};
	level_03.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 27 * t, SDL_TRUE, {0, 20}, 0};
	level_03.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 22 * t, SDL_TRUE, {0, 30}, 0};
	level_03.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 36 * t, SDL_TRUE, {0, 40}, 0};
	level_03.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 50}, 0};
	level_03.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 32 * t, SDL_TRUE, {0, 60}, 0};
	level_03.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 16 * t, SDL_TRUE, {0, 70}, 0};
	level_03.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 28 * t, SDL_TRUE, {0, 80}, 0};
	level_03.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 90}, 0};
	level_03.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 13 * t, SDL_TRUE, {0, 100}, 0};
	level_03.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 26 * t, SDL_TRUE, {0, 110}, 0};
	level_03.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 120}, 0};
	level_03.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 24 * t, SDL_TRUE, {0, 130}, 0};
	level_03.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 6 * t, SDL_TRUE, {0, 140}, 0};
	level_03.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 20 * t, SDL_TRUE, {0, 150}, 0};
	level_03.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 25 * t, SDL_TRUE, {0, 160}, 0};
	level_03.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, 35 * t, SDL_TRUE, {0, 170}, 0};
	level_03.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, 33 * t, SDL_TRUE, {0, 180}, 0};
	level_03.waves[1].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 34 * t, SDL_TRUE, {0, 190}, 0};
	level_03.waves[1].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, 29 * t, SDL_TRUE, {0, 200}, 0};
	level_03.waves[1].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, 8 * t, SDL_TRUE, {0, 210}, 0};
	level_03.waves[1].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, 3 * t, SDL_TRUE, {0, 220}, 0};
	level_03.waves[1].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, 5 * t, SDL_TRUE, {0, 230}, 0};
	level_03.waves[1].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 240}, 0};
	level_03.waves[1].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 30 * t, SDL_TRUE, {0, 250}, 0};
	level_03.waves[1].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 260}, 0};
	level_03.waves[1].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, 11 * t, SDL_TRUE, {0, 270}, 0};
	level_03.waves[1].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, 4 * t, SDL_TRUE, {0, 280}, 0};
	level_03.waves[1].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, 2 * t, SDL_TRUE, {0, 290}, 0};
	level_03.waves[1].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, 17 * t, SDL_TRUE, {0, 300}, 0};
	level_03.waves[1].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 21 * t, SDL_TRUE, {0, 310}, 0};
	level_03.waves[1].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 320}, 0};
	level_03.waves[1].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, 23 * t, SDL_TRUE, {0, 330}, 0};
	level_03.waves[1].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, 15 * t, SDL_TRUE, {0, 340}, 0};
	level_03.waves[1].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 350}, 0};

	level_03.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 30, SDL_FALSE, NULL};
	level_03.waves[2].wave_array = SDL_malloc(sizeof(*(level_03.waves[2].wave_array)) * level_03.waves[2].size);

	level_03.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 29 * t, SDL_TRUE, {0, 0}, 0};
	level_03.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 19 * t, SDL_TRUE, {0, 10}, 0};
	level_03.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 30 * t, SDL_TRUE, {0, 20}, 0};
	level_03.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 25 * t, SDL_TRUE, {0, 30}, 0};
	level_03.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 33 * t, SDL_TRUE, {0, 40}, 0};
	level_03.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 8 * t, SDL_TRUE, {0, 50}, 0};
	level_03.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 60}, 0};
	level_03.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 5 * t, SDL_TRUE, {0, 70}, 0};
	level_03.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 24 * t, SDL_TRUE, {0, 80}, 0};
	level_03.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 11 * t, SDL_TRUE, {0, 90}, 0};
	level_03.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 15 * t, SDL_TRUE, {0, 100}, 0};
	level_03.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 110}, 0};
	level_03.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 120}, 0};
	level_03.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 16 * t, SDL_TRUE, {0, 130}, 0};
	level_03.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 6 * t, SDL_TRUE, {0, 140}, 0};
	level_03.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 27 * t, SDL_TRUE, {0, 150}, 0};
	level_03.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 18 * t, SDL_TRUE, {0, 160}, 0};
	level_03.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, 35 * t, SDL_TRUE, {0, 170}, 0};
	level_03.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, 34 * t, SDL_TRUE, {0, 180}, 0};
	level_03.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 21 * t, SDL_TRUE, {0, 190}, 0};
	level_03.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, 3 * t, SDL_TRUE, {0, 200}, 0};
	level_03.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, 22 * t, SDL_TRUE, {0, 210}, 0};
	level_03.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, 13 * t, SDL_TRUE, {0, 220}, 0};
	level_03.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 240}, 0};
	level_03.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 250}, 0};
	level_03.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 36 * t, SDL_TRUE, {0, 260}, 0};
	level_03.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 23 * t, SDL_TRUE, {0, 300}, 0};
	level_03.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, 4 * t, SDL_TRUE, {0, 320}, 0};
	level_03.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, 2 * t, SDL_TRUE, {0, 340}, 0};
	level_03.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 350}, 0};

	return level_03;
}