#include "main.h"
#include "entity.h"

t_wave_m	level_13(void)
{
	t_wave_m level_13 = {
		.wave_id = 12,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 3,

		.size = 4,
	};

	level_13.waves = SDL_malloc(sizeof(*(level_13.waves)) * level_13.size);

	level_13.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 12, SDL_FALSE, NULL};
	level_13.waves[0].wave_array = SDL_malloc(sizeof(*(level_13.waves[0].wave_array)) * level_13.waves[0].size);

	int a = 36;
	level_13.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_13.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_13.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_13.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_13.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_13.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_13.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_13.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_13.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_13.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_13.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_13.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 11}, 0};

	level_13.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_13.waves[1].wave_array = SDL_malloc(sizeof(*(level_13.waves[1].wave_array)) * level_13.waves[1].size);

	level_13.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,		0, 0, SDL_TRUE, {0, 90 - 10}, 0};
	level_13.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_YELLOW,	0, 32, SDL_TRUE, {0, 90}, 0};
	level_13.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,		0, 0, SDL_TRUE, {0, 90 + 10}, 0};

	level_13.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,		0, 40 + 0, SDL_TRUE, {0, 317 - 10}, 0};
	level_13.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_YELLOW,	0, 40 + 32, SDL_TRUE, {0, 317}, 0};
	level_13.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,		0, 40 + 0, SDL_TRUE, {0, 317 + 10}, 0};

	level_13.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,		0, 80 + 0, SDL_TRUE, {0, 76 - 10}, 0};
	level_13.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW,	0, 80 + 32, SDL_TRUE, {0, 76}, 0};
	level_13.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,		0, 80 + 0, SDL_TRUE, {0, 76 + 10}, 0};

	level_13.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,		0, 100 + 0, SDL_TRUE, {0, 267 - 10}, 0};
	level_13.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_YELLOW,	0, 100 + 32, SDL_TRUE, {0, 267}, 0};
	level_13.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,		0, 100 + 0, SDL_TRUE, {0, 267 + 10}, 0};

	level_13.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 22, SDL_FALSE, NULL};
	level_13.waves[2].wave_array = SDL_malloc(sizeof(*(level_13.waves[2].wave_array)) * level_13.waves[2].size);

	level_13.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,		0, 0, SDL_TRUE, {0, 90 - 10}, 0};
	level_13.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_YELLOW,	0, 32, SDL_TRUE, {0, 90}, 0};
	level_13.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,		0, 0, SDL_TRUE, {0, 90 + 10}, 0};

	level_13.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,		0, 80 + 0, SDL_TRUE, {0, 317 - 10}, 0};
	level_13.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_YELLOW,	0, 80 + 32, SDL_TRUE, {0, 317}, 0};
	level_13.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,		0, 80 + 0, SDL_TRUE, {0, 317 + 10}, 0};

	level_13.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,		0, 160 + 0, SDL_TRUE, {0, 76 - 10}, 0};
	level_13.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW,	0, 160 + 32, SDL_TRUE, {0, 76}, 0};
	level_13.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,		0, 160 + 0, SDL_TRUE, {0, 76 + 10}, 0};

	level_13.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,		0, 220 + 0, SDL_TRUE, {0, 267 - 10}, 0};
	level_13.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_YELLOW,	0, 220 + 32, SDL_TRUE, {0, 267}, 0};
	level_13.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,		0, 220 + 0, SDL_TRUE, {0, 267 + 10}, 0};

	int t = 20;
	level_13.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 317}, 0};
	level_13.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 357}, 0};
	level_13.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 221}, 0};
	level_13.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 50}, 0};
	level_13.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 76}, 0};
	level_13.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 59}, 0};
	level_13.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 266}, 0};
	level_13.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 167}, 0};
	level_13.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 66}, 0};
	level_13.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 102}, 0};

	level_13.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 50, SDL_FALSE, NULL};
	level_13.waves[3].wave_array = SDL_malloc(sizeof(*(level_13.waves[3].wave_array)) * level_13.waves[3].size);

	t = 10;
	level_13.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 290}, 0};
	level_13.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 29}, 0};
	level_13.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 284}, 0};
	level_13.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 249}, 0};
	level_13.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 214}, 0};
	level_13.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 312}, 0};
	level_13.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 24}, 0};
	level_13.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 34}, 0};
	level_13.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 214}, 0};
	level_13.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 245}, 0};
	level_13.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 84}, 0};
	level_13.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 86}, 0};
	level_13.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 101}, 0};
	level_13.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 359}, 0};
	level_13.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 213}, 0};
	level_13.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 131}, 0};
	level_13.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 236}, 0};
	level_13.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 80}, 0};
	level_13.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 94}, 0};
	level_13.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 104}, 0};
	level_13.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 126}, 0};
	level_13.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 270}, 0};
	level_13.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 140}, 0};
	level_13.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, 257}, 0};
	level_13.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, 309}, 0};
	level_13.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25, SDL_TRUE, {0, 349}, 0};
	level_13.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26, SDL_TRUE, {0, 270}, 0};
	level_13.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27, SDL_TRUE, {0, 349}, 0};
	level_13.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28, SDL_TRUE, {0, 247}, 0};
	level_13.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29, SDL_TRUE, {0, 183}, 0};
	level_13.waves[3].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 30, SDL_TRUE, {0, 116}, 0};
	level_13.waves[3].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 31, SDL_TRUE, {0, 183}, 0};
	level_13.waves[3].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, t * 32, SDL_TRUE, {0, 99}, 0};
	level_13.waves[3].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, t * 33, SDL_TRUE, {0, 352}, 0};
	level_13.waves[3].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, t * 34, SDL_TRUE, {0, 33}, 0};
	level_13.waves[3].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, t * 35, SDL_TRUE, {0, 268}, 0};
	level_13.waves[3].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, t * 36, SDL_TRUE, {0, 272}, 0};
	level_13.waves[3].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, t * 37, SDL_TRUE, {0, 183}, 0};
	level_13.waves[3].wave_array[38] = (t_wave_elem){E_SLIME_BLUE, 0, t * 38, SDL_TRUE, {0, 50}, 0};
	level_13.waves[3].wave_array[39] = (t_wave_elem){E_SLIME_BLUE, 0, t * 39, SDL_TRUE, {0, 161}, 0};
	level_13.waves[3].wave_array[40] = (t_wave_elem){E_SLIME_BLUE, 0, t * 40, SDL_TRUE, {0, 158}, 0};
	level_13.waves[3].wave_array[41] = (t_wave_elem){E_SLIME_BLUE, 0, t * 41, SDL_TRUE, {0, 240}, 0};
	level_13.waves[3].wave_array[42] = (t_wave_elem){E_SLIME_BLUE, 0, t * 42, SDL_TRUE, {0, 243}, 0};
	level_13.waves[3].wave_array[43] = (t_wave_elem){E_SLIME_BLUE, 0, t * 43, SDL_TRUE, {0, 142}, 0};
	level_13.waves[3].wave_array[44] = (t_wave_elem){E_SLIME_BLUE, 0, t * 44, SDL_TRUE, {0, 113}, 0};
	level_13.waves[3].wave_array[45] = (t_wave_elem){E_SLIME_BLUE, 0, t * 45, SDL_TRUE, {0, 236}, 0};
	level_13.waves[3].wave_array[46] = (t_wave_elem){E_SLIME_BLUE, 0, t * 46, SDL_TRUE, {0, 166}, 0};
	level_13.waves[3].wave_array[47] = (t_wave_elem){E_SLIME_BLUE, 0, t * 47, SDL_TRUE, {0, 355}, 0};
	level_13.waves[3].wave_array[48] = (t_wave_elem){E_SLIME_BLUE, 0, t * 48, SDL_TRUE, {0, 169}, 0};
	level_13.waves[3].wave_array[49] = (t_wave_elem){E_SLIME_BLUE, 0, t * 49, SDL_TRUE, {0, 184}, 0};

	return (level_13);
}