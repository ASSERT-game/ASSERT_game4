#include "main.h"
#include "entity.h"

t_wave_m	level_05(void)
{
	t_wave_m level_05 = {
		.wave_id = 4,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 2,

		.size = 3,
	};

	level_05.waves = SDL_malloc(sizeof(*(level_05.waves)) * level_05.size);

	level_05.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 12, SDL_FALSE, NULL};
	level_05.waves[0].wave_array = SDL_malloc(sizeof(*(level_05.waves[0].wave_array)) * level_05.waves[0].size);

	level_05.waves[0].wave_array[0] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_05.waves[0].wave_array[1] = (t_wave_elem){E_SLIME_BLUE, 0, 45, SDL_TRUE, {0, 30}, 0};
	level_05.waves[0].wave_array[2] = (t_wave_elem){E_SLIME_BLUE, 0, 45, SDL_TRUE, {0, -30}, 0};
	level_05.waves[0].wave_array[3] = (t_wave_elem){E_SLIME_CYAN, (4 << 8), 55, SDL_TRUE, {0, 0}, 0};

	level_05.waves[0].wave_array[4] = (t_wave_elem){E_SLIME_BLUE, 0, 85 + 0, SDL_TRUE,  {0, 180 + 0}, 0};
	level_05.waves[0].wave_array[5] = (t_wave_elem){E_SLIME_BLUE, 0, 85 + 35, SDL_TRUE, {0, 180 + 30}, 0};
	level_05.waves[0].wave_array[6] = (t_wave_elem){E_SLIME_BLUE, 0, 85 + 35, SDL_TRUE, {0, 180 + -30}, 0};
	level_05.waves[0].wave_array[7] = (t_wave_elem){E_SLIME_CYAN, (4 << 8), 85 + 45, SDL_TRUE, {0, 180 + 0}, 0};

	level_05.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 155 + 0, SDL_TRUE,  {0, 0}, 0};
	level_05.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 155 + 25, SDL_TRUE, {0, 30}, 0};
	level_05.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 155 + 25, SDL_TRUE, {0, -30}, 0};
	level_05.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, (4 << 8), 155 + 35, SDL_TRUE, {0, 0}, 0};

	level_05.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_05.waves[1].wave_array = SDL_malloc(sizeof(*(level_05.waves[1].wave_array)) * level_05.waves[1].size);

	level_05.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 25, SDL_TRUE, {0, 8}, 0};
	level_05.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_05.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 25, SDL_TRUE, {0, -8}, 0};
	level_05.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40, SDL_TRUE, {0, 0}, 0};

	level_05.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 25 + 110, SDL_TRUE, {0, 180 + 8}, 0};
	level_05.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 0 + 110, SDL_TRUE, {0, 180 + 0}, 0};
	level_05.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 25 + 110, SDL_TRUE, {0, 180 + -8}, 0};
	level_05.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40 + 110, SDL_TRUE, {0, 180 + 0}, 0};

	level_05.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 25 + 250, SDL_TRUE, {0, 12}, 0};
	level_05.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN, 0, 0 + 250, SDL_TRUE, {0, 0}, 0};
	level_05.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 25 + 250, SDL_TRUE, {0, -12}, 0};
	level_05.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40 + 250, SDL_TRUE, {0, 0}, 0};

	level_05.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 36, SDL_FALSE, NULL};
	level_05.waves[2].wave_array = SDL_malloc(sizeof(*(level_05.waves[2].wave_array)) * level_05.waves[2].size);

	int t;

	t = 20;
	level_05.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 31 * t + 25, SDL_TRUE, {0, 0}, 0};
	level_05.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 31 * t, SDL_TRUE, {0, 0}, 0};
	level_05.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 27 * t, SDL_TRUE, {0, 20}, 0};
	level_05.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 22 * t + 25, SDL_TRUE, {0, 30}, 0};
	level_05.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 22 * t, SDL_TRUE, {0, 30}, 0};
	level_05.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 50}, 0};
	level_05.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 32 * t, SDL_TRUE, {0, 60}, 0};
	level_05.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 16 * t + 25, SDL_TRUE, {0, 70}, 0};
	level_05.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 16 * t, SDL_TRUE, {0, 70}, 0};
	level_05.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 12 * t, SDL_TRUE, {0, 90}, 0};
	level_05.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 13 * t + 25, SDL_TRUE, {0, 100}, 0};
	level_05.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 13 * t, SDL_TRUE, {0, 100}, 0};
	level_05.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 120}, 0};
	level_05.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 24 * t, SDL_TRUE, {0, 130}, 0};
	level_05.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 6 * t + 25, SDL_TRUE, {0, 140}, 0};
	level_05.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 6 * t, SDL_TRUE, {0, 140}, 0};
	level_05.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 25 * t, SDL_TRUE, {0, 160}, 0};
	level_05.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 35 * t + 25, SDL_TRUE, {0, 170}, 0};
	level_05.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 35 * t, SDL_TRUE, {0, 170}, 0};
	level_05.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 34 * t, SDL_TRUE, {0, 190}, 0};
	level_05.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 29 * t + 25, SDL_TRUE, {0, 200}, 0};
	level_05.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 29 * t, SDL_TRUE, {0, 200}, 0};
	level_05.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 3 * t + 25, SDL_TRUE, {0, 220}, 0};
	level_05.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 3 * t, SDL_TRUE, {0, 220}, 0};
	level_05.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 240}, 0};
	level_05.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 30 * t, SDL_TRUE, {0, 250}, 0};
	level_05.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 14 * t, SDL_TRUE, {0, 260}, 0};
	level_05.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 11 * t + 25, SDL_TRUE, {0, 270}, 0};
	level_05.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_CYAN, 0, 11 * t, SDL_TRUE, {0, 270}, 0};
	level_05.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 19 * t + 25, SDL_TRUE, {0, 290}, 0};
	level_05.waves[2].wave_array[30] = (t_wave_elem){E_SLIME_CYAN, 0, 19 * t, SDL_TRUE, {0, 290}, 0};
	level_05.waves[2].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 21 * t, SDL_TRUE, {0, 310}, 0};
	level_05.waves[2].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 320}, 0};
	level_05.waves[2].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 23 * t + 25, SDL_TRUE, {0, 330}, 0};
	level_05.waves[2].wave_array[34] = (t_wave_elem){E_SLIME_CYAN, 0, 23 * t, SDL_TRUE, {0, 330}, 0};
	level_05.waves[2].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 350}, 0};

	return level_05;
}