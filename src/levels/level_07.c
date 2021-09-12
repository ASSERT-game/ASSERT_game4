#include "main.h"
#include "entity.h"

t_wave_m	level_07(void)
{
	t_wave_m level_07 = {
		.wave_id = 6,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 5,

		.size = 6,
	};

	level_07.waves = SDL_malloc(sizeof(*(level_07.waves)) * level_07.size);

	level_07.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 16, SDL_FALSE, NULL};
	level_07.waves[0].wave_array = SDL_malloc(sizeof(*(level_07.waves[0].wave_array)) * level_07.waves[0].size);

	int a = 30;
	level_07.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0 * a}, 0};
	level_07.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 1 * a}, 0};
	level_07.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 2 * a}, 0};
	level_07.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 3 * a}, 0};
	level_07.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 4 * a}, 0};
	level_07.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 5 * a}, 0};
	level_07.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 6 * a}, 0};
	level_07.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 7 * a}, 0};
	level_07.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 8 * a}, 0};
	level_07.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 9 * a}, 0};
	level_07.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 10 * a}, 0};
	level_07.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 11 * a}, 0};

	level_07.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 25, SDL_TRUE, {0, 90 + 8}, 0};
	level_07.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 0, SDL_TRUE, {0, 90}, 0};
	level_07.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 25, SDL_TRUE, {0, 90 - 8}, 0};
	level_07.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40 + 50, SDL_TRUE, {0, 90}, 0};

	level_07.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_07.waves[1].wave_array = SDL_malloc(sizeof(*(level_07.waves[1].wave_array)) * level_07.waves[1].size);

	level_07.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_07.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_07.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 180}, 0};
	level_07.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 270}, 0};

	int t = 10;
	level_07.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 4 * t, SDL_TRUE, {0, 230}, 0};
	level_07.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 5 * t, SDL_TRUE, {0, 48}, 0};
	level_07.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 6 * t, SDL_TRUE, {0, 98}, 0};
	level_07.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 65}, 0};
	level_07.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 8 * t, SDL_TRUE, {0, 283}, 0};
	level_07.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 159}, 0};
	level_07.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 333}, 0};
	level_07.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 11 * t, SDL_TRUE, {0, 124}, 0};
	level_07.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 240}, 0};
	level_07.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 13 * t, SDL_TRUE, {0, 141}, 0};
	level_07.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 36}, 0};
	level_07.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 15 * t, SDL_TRUE, {0, 63}, 0};

	level_07.waves[2] = (t_wave){0, WAVE_TICKS, t * 4, SDL_FALSE, SDL_FALSE, 36, SDL_FALSE, NULL};
	level_07.waves[2].wave_array = SDL_malloc(sizeof(*(level_07.waves[2].wave_array)) * level_07.waves[2].size);

	t = 20;
	level_07.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 31 * t + 25, SDL_TRUE, {0, 0}, 0};
	level_07.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 31 * t, SDL_TRUE, {0, 0}, 0};
	level_07.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 27 * t, SDL_TRUE, {0, 20}, 0};
	level_07.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 22 * t + 25, SDL_TRUE, {0, 30}, 0};
	level_07.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 22 * t, SDL_TRUE, {0, 30}, 0};
	level_07.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 50}, 0};
	level_07.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 32 * t, SDL_TRUE, {0, 60}, 0};
	level_07.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 16 * t + 25, SDL_TRUE, {0, 70}, 0};
	level_07.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 16 * t, SDL_TRUE, {0, 70}, 0};
	level_07.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 90}, 0};
	level_07.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 13 * t + 25, SDL_TRUE, {0, 100}, 0};
	level_07.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 13 * t, SDL_TRUE, {0, 100}, 0};
	level_07.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 120}, 0};
	level_07.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 24 * t, SDL_TRUE, {0, 130}, 0};
	level_07.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 6 * t + 25, SDL_TRUE, {0, 140}, 0};
	level_07.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 6 * t, SDL_TRUE, {0, 140}, 0};
	level_07.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 25 * t, SDL_TRUE, {0, 160}, 0};
	level_07.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 35 * t + 25, SDL_TRUE, {0, 170}, 0};
	level_07.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 35 * t, SDL_TRUE, {0, 170}, 0};
	level_07.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 34 * t, SDL_TRUE, {0, 190}, 0};
	level_07.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 29 * t + 25, SDL_TRUE, {0, 200}, 0};
	level_07.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 29 * t, SDL_TRUE, {0, 200}, 0};
	level_07.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 3 * t + 25, SDL_TRUE, {0, 220}, 0};
	level_07.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 3 * t, SDL_TRUE, {0, 220}, 0};
	level_07.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 240}, 0};
	level_07.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 30 * t, SDL_TRUE, {0, 250}, 0};
	level_07.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 260}, 0};
	level_07.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 11 * t + 25, SDL_TRUE, {0, 270}, 0};
	level_07.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_CYAN, 0, 11 * t, SDL_TRUE, {0, 270}, 0};
	level_07.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 19 * t + 25, SDL_TRUE, {0, 290}, 0};
	level_07.waves[2].wave_array[30] = (t_wave_elem){E_SLIME_CYAN, 0, 19 * t, SDL_TRUE, {0, 290}, 0};
	level_07.waves[2].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 21 * t, SDL_TRUE, {0, 310}, 0};
	level_07.waves[2].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 320}, 0};
	level_07.waves[2].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 23 * t + 25, SDL_TRUE, {0, 330}, 0};
	level_07.waves[2].wave_array[34] = (t_wave_elem){E_SLIME_CYAN, 0, 23 * t, SDL_TRUE, {0, 330}, 0};
	level_07.waves[2].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 350}, 0};

	level_07.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_07.waves[3].wave_array = SDL_malloc(sizeof(*(level_07.waves[3].wave_array)) * level_07.waves[3].size);

	a = 30;
	level_07.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 0 * a}, 0};
	level_07.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 1 * a}, 0};
	level_07.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 2 * a}, 0};
	level_07.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 3 * a}, 0};
	level_07.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 4 * a}, 0};
	level_07.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 5 * a}, 0};
	level_07.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 6 * a}, 0};
	level_07.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 7 * a}, 0};
	level_07.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 8 * a}, 0};
	level_07.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 9 * a}, 0};
	level_07.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 10 * a}, 0};
	level_07.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 20, SDL_TRUE, {0, 11 * a}, 0};

	level_07.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 25, SDL_FALSE, NULL};
	level_07.waves[4].wave_array = SDL_malloc(sizeof(*(level_07.waves[4].wave_array)) * level_07.waves[4].size);

	a = 16;
	t = 12;
	level_07.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 0 * a}, 0};
	level_07.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 1 * a}, 0};
	level_07.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 2 * a}, 0};
	level_07.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 3 * a}, 0};
	level_07.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 4 * a}, 0};
	level_07.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 5 * a}, 0};
	level_07.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 6 * a}, 0};
	level_07.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 7 * a}, 0};
	level_07.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 8 * a}, 0};
	level_07.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 9 * a}, 0};
	level_07.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 10 * a}, 0};
	level_07.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 11 * a}, 0};
	level_07.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 12 * a}, 0};
	level_07.waves[4].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 13 * a}, 0};
	level_07.waves[4].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 14 * a}, 0};
	level_07.waves[4].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 15 * a}, 0};
	level_07.waves[4].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 16 * a}, 0};
	level_07.waves[4].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 17 * a}, 0};
	level_07.waves[4].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 18 * a}, 0};
	level_07.waves[4].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 19 * a}, 0};
	level_07.waves[4].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 20 * a}, 0};
	level_07.waves[4].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 21 * a}, 0};
	level_07.waves[4].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 22 * a}, 0};
	level_07.waves[4].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, 23 * a}, 0};
	level_07.waves[4].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, 24 * a}, 0};

	level_07.waves[5] = (t_wave){0, WAVE_TICKS, t * 15 + 25, SDL_FALSE, SDL_FALSE, 32, SDL_FALSE, NULL};
	level_07.waves[5].wave_array = SDL_malloc(sizeof(*(level_07.waves[5].wave_array)) * level_07.waves[5].size);

	a = 16;
	level_07.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 0 * a + 102}, 0};
	level_07.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 1 * a + 102}, 0};
	level_07.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 2 * a + 102}, 0};
	level_07.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 3 * a + 102}, 0};
	level_07.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 4 * a + 102}, 0};
	level_07.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 5 * a + 102}, 0};
	level_07.waves[5].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 6 * a + 102}, 0};
	level_07.waves[5].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 7 * a + 102}, 0};
	level_07.waves[5].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 8 * a + 102}, 0};
	level_07.waves[5].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 9 * a + 102}, 0};
	level_07.waves[5].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10 - 10, SDL_TRUE, {0, 10 * a + 102}, 0};
	level_07.waves[5].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 11 * a + 102}, 0};
	level_07.waves[5].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 12 * a + 102}, 0};
	level_07.waves[5].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 13 * a + 102}, 0};
	level_07.waves[5].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 14 * a + 102}, 0};
	level_07.waves[5].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 15 * a + 102}, 0};
	level_07.waves[5].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 16 * a + 102}, 0};
	level_07.waves[5].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 17 * a + 102}, 0};
	level_07.waves[5].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 18 * a + 102}, 0};
	level_07.waves[5].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 19 * a + 102}, 0};
	level_07.waves[5].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 20 * a + 102}, 0};
	level_07.waves[5].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 21 * a + 102}, 0};
	level_07.waves[5].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 22 * a + 102}, 0};
	level_07.waves[5].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, 23 * a + 102}, 0};
	level_07.waves[5].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, 24 * a + 102}, 0};
	level_07.waves[5].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25, SDL_TRUE, {0, 25 * a + 102}, 0};
	level_07.waves[5].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26, SDL_TRUE, {0, 26 * a + 102}, 0};
	level_07.waves[5].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27, SDL_TRUE, {0, 27 * a + 102}, 0};
	level_07.waves[5].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28, SDL_TRUE, {0, 28 * a + 102}, 0};
	level_07.waves[5].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29, SDL_TRUE, {0, 29 * a + 102}, 0};
	level_07.waves[5].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 30, SDL_TRUE, {0, 30 * a + 102}, 0};
	level_07.waves[5].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 31, SDL_TRUE, {0, 31 * a + 102}, 0};

	return level_07;
}