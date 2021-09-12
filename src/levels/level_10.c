#include "main.h"
#include "entity.h"

t_wave_m	level_10(void)
{
	t_wave_m level_10 = {
		.wave_id = 9,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 7,

		.size = 8,
	};

	level_10.waves = SDL_malloc(sizeof(*(level_10.waves)) * level_10.size);

	level_10.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 1, SDL_FALSE, NULL};
	level_10.waves[0].wave_array = SDL_malloc(sizeof(*(level_10.waves[0].wave_array)) * level_10.waves[0].size);

	level_10.waves[0].wave_array[0] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90}, 0};

	level_10.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 2, SDL_FALSE, NULL};
	level_10.waves[1].wave_array = SDL_malloc(sizeof(*(level_10.waves[1].wave_array)) * level_10.waves[1].size);

	level_10.waves[1].wave_array[0] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_10.waves[1].wave_array[1] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 180}, 0};

	level_10.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 3, SDL_FALSE, NULL};
	level_10.waves[2].wave_array = SDL_malloc(sizeof(*(level_10.waves[2].wave_array)) * level_10.waves[2].size);

	level_10.waves[2].wave_array[0] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_10.waves[2].wave_array[1] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 210}, 0};
	level_10.waves[2].wave_array[2] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 330}, 0};

	level_10.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 36, SDL_FALSE, NULL};
	level_10.waves[3].wave_array = SDL_malloc(sizeof(*(level_10.waves[3].wave_array)) * level_10.waves[3].size);

	int t;

	t = 30;
	level_10.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_PURP, (4 << 8), 31 * t + 25, SDL_TRUE, {0, 0}, 0};
	level_10.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 31 * t, SDL_TRUE, {0, 0}, 0};
	level_10.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 27 * t, SDL_TRUE, {0, 20}, 0};
	level_10.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 22 * t + 25, SDL_TRUE, {0, 30}, 0};
	level_10.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 22 * t, SDL_TRUE, {0, 30}, 0};
	level_10.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 50}, 0};
	level_10.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 32 * t, SDL_TRUE, {0, 60}, 0};
	level_10.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_PURP, (4 << 8), 16 * t + 25, SDL_TRUE, {0, 70}, 0};
	level_10.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 16 * t, SDL_TRUE, {0, 70}, 0};
	level_10.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 90}, 0};
	level_10.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 13 * t + 25, SDL_TRUE, {0, 100}, 0};
	level_10.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 13 * t, SDL_TRUE, {0, 100}, 0};
	level_10.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 120}, 0};
	level_10.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 24 * t, SDL_TRUE, {0, 130}, 0};
	t = 42;
	level_10.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 6 * t + 25, SDL_TRUE, {0, 140}, 0};
	level_10.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 6 * t, SDL_TRUE, {0, 140}, 0};
	level_10.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 25 * t, SDL_TRUE, {0, 160}, 0};
	level_10.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 35 * t + 25, SDL_TRUE, {0, 170}, 0};
	level_10.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 35 * t, SDL_TRUE, {0, 170}, 0};
	level_10.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 34 * t, SDL_TRUE, {0, 190}, 0};
	level_10.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 29 * t + 25, SDL_TRUE, {0, 200}, 0};
	level_10.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 29 * t, SDL_TRUE, {0, 200}, 0};
	level_10.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 3 * t + 25, SDL_TRUE, {0, 220}, 0};
	level_10.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 3 * t, SDL_TRUE, {0, 220}, 0};
	level_10.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 240}, 0};
	level_10.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 30 * t, SDL_TRUE, {0, 250}, 0};
	level_10.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 260}, 0};
	level_10.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 11 * t + 25, SDL_TRUE, {0, 270}, 0};
	level_10.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_CYAN, 0, 11 * t, SDL_TRUE, {0, 270}, 0};
	level_10.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 19 * t + 25, SDL_TRUE, {0, 290}, 0};
	level_10.waves[3].wave_array[30] = (t_wave_elem){E_SLIME_CYAN, 0, 19 * t, SDL_TRUE, {0, 290}, 0};
	t = 30;
	level_10.waves[3].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 21 * t, SDL_TRUE, {0, 310}, 0};
	level_10.waves[3].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 320}, 0};
	level_10.waves[3].wave_array[33] = (t_wave_elem){E_SLIME_PURP, (4 << 8), 23 * t + 25, SDL_TRUE, {0, 330}, 0};
	level_10.waves[3].wave_array[34] = (t_wave_elem){E_SLIME_CYAN, 0, 23 * t, SDL_TRUE, {0, 330}, 0};
	level_10.waves[3].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 350}, 0};

	level_10.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 13, SDL_FALSE, NULL};
	level_10.waves[4].wave_array = SDL_malloc(sizeof(*(level_10.waves[4].wave_array)) * level_10.waves[4].size);

	t = 12;
	level_10.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 138}, 0};
	level_10.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,  SDL_TRUE, {0, 126}, 0};
	level_10.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2,  SDL_TRUE, {0, 359}, 0};
	level_10.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,  SDL_TRUE, {0, 157}, 0};
	level_10.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,  SDL_TRUE, {0, 131}, 0};
	level_10.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,  SDL_TRUE, {0, 143}, 0};
	level_10.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,  SDL_TRUE, {0, 36}, 0};
	level_10.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7,  SDL_TRUE, {0, 79}, 0};
	level_10.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,  SDL_TRUE, {0, 203}, 0};
	level_10.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,  SDL_TRUE, {0, 33}, 0};
	level_10.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 110}, 0};
	level_10.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 310}, 0};
	level_10.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 330}, 0};

	level_10.waves[5] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 4, SDL_FALSE, NULL};
	level_10.waves[5].wave_array = SDL_malloc(sizeof(*(level_10.waves[5].wave_array)) * level_10.waves[5].size);

	level_10.waves[5].wave_array[0] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_10.waves[5].wave_array[1] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_10.waves[5].wave_array[2] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 180}, 0};
	level_10.waves[5].wave_array[3] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 270}, 0};

	level_10.waves[6] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 23, SDL_FALSE, NULL};
	level_10.waves[6].wave_array = SDL_malloc(sizeof(*(level_10.waves[6].wave_array)) * level_10.waves[6].size);

	t = 14;
	level_10.waves[6].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 306}, 0};
	level_10.waves[6].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,  SDL_TRUE, {0, 30}, 0};
	level_10.waves[6].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2,  SDL_TRUE, {0, 355}, 0};
	level_10.waves[6].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,  SDL_TRUE, {0, 37}, 0};
	level_10.waves[6].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,  SDL_TRUE, {0, 94}, 0};
	level_10.waves[6].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,  SDL_TRUE, {0, 147}, 0};
	level_10.waves[6].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,  SDL_TRUE, {0, 37}, 0};
	level_10.waves[6].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7,  SDL_TRUE, {0, 255}, 0};
	level_10.waves[6].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,  SDL_TRUE, {0, 144}, 0};
	level_10.waves[6].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,  SDL_TRUE, {0, 261}, 0};
	level_10.waves[6].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 193}, 0};
	level_10.waves[6].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 109}, 0};
	level_10.waves[6].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 248}, 0};
	level_10.waves[6].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 52}, 0};
	level_10.waves[6].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 111}, 0};
	level_10.waves[6].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 5}, 0};
	level_10.waves[6].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 307}, 0};
	level_10.waves[6].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 238}, 0};
	level_10.waves[6].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 290}, 0};
	level_10.waves[6].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 252}, 0};
	level_10.waves[6].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 336}, 0};
	level_10.waves[6].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 62}, 0};
	level_10.waves[6].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 240}, 0};

	level_10.waves[7] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 5, SDL_FALSE, NULL};
	level_10.waves[7].wave_array = SDL_malloc(sizeof(*(level_10.waves[7].wave_array)) * level_10.waves[7].size);

	level_10.waves[7].wave_array[0] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90 + 0}, 0};
	level_10.waves[7].wave_array[1] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90 + 72}, 0};
	level_10.waves[7].wave_array[2] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90 + 144}, 0};
	level_10.waves[7].wave_array[3] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90 + 216}, 0};
	level_10.waves[7].wave_array[4] = (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90 + 288}, 0};

	return (level_10);
}