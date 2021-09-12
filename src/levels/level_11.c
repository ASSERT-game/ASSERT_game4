#include "main.h"
#include "entity.h"

t_wave_m	level_11(void)
{
	t_wave_m level_11 = {
		.wave_id = 10,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 5,

		.size = 6,
	};

	level_11.waves = SDL_malloc(sizeof(*(level_11.waves)) * level_11.size);

	level_11.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 4, SDL_FALSE, NULL};
	level_11.waves[0].wave_array = SDL_malloc(sizeof(*(level_11.waves[0].wave_array)) * level_11.waves[0].size);

	level_11.waves[0].wave_array[0] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_11.waves[0].wave_array[1] = (t_wave_elem){E_SLIME_CYAN, 0, 15, SDL_TRUE, {0, 90}, 0};
	level_11.waves[0].wave_array[2] = (t_wave_elem){E_SLIME_CYAN, 0, 30, SDL_TRUE, {0, 90}, 0};
	level_11.waves[0].wave_array[3] = (t_wave_elem){E_SLIME_CYAN, 0, 45, SDL_TRUE, {0, 90}, 0};

	level_11.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 15, SDL_FALSE, NULL};
	level_11.waves[1].wave_array = SDL_malloc(sizeof(*(level_11.waves[1].wave_array)) * level_11.waves[1].size);

	int t = 10;
	level_11.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 138}, 0};
	level_11.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,  SDL_TRUE, {0, 126}, 0};
	level_11.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2,  SDL_TRUE, {0, 359}, 0};
	level_11.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,  SDL_TRUE, {0, 157}, 0};
	level_11.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,  SDL_TRUE, {0, 131}, 0};
	level_11.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,  SDL_TRUE, {0, 143}, 0};
	level_11.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,  SDL_TRUE, {0, 36}, 0};
	level_11.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7,  SDL_TRUE, {0, 79}, 0};
	level_11.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,  SDL_TRUE, {0, 203}, 0};
	level_11.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,  SDL_TRUE, {0, 33}, 0};
	level_11.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 110}, 0};
	level_11.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 218}, 0};
	level_11.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 309}, 0};
	level_11.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 31}, 0};
	level_11.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 0}, 0};

	level_11.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 21, SDL_FALSE, NULL};
	level_11.waves[2].wave_array = SDL_malloc(sizeof(*(level_11.waves[2].wave_array)) * level_11.waves[2].size);

	int a = 36;
	level_11.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 0 * a}, 0};
	level_11.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 1 * a}, 0};
	level_11.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 2 * a}, 0};
	level_11.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 3 * a}, 0};
	level_11.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 4 * a}, 0};
	level_11.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 5 * a}, 0};
	level_11.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 6 * a}, 0};
	level_11.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 7 * a}, 0};
	level_11.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 8 * a}, 0};
	level_11.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 9 * a}, 0};

	level_11.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 60 + 0, SDL_TRUE, {0, 90}, 0};
	level_11.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 60 + 15, SDL_TRUE, {0, 90}, 0};
	level_11.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 60 + 30, SDL_TRUE, {0, 90}, 0};
	level_11.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 60 + 45, SDL_TRUE, {0, 90}, 0};

	t = 18;
	level_11.waves[2].wave_array[14] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 0,  SDL_TRUE, {0, 21}, 0};
	level_11.waves[2].wave_array[15] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 1,  SDL_TRUE, {0, 212}, 0};
	level_11.waves[2].wave_array[16] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 2,  SDL_TRUE, {0, 327}, 0};
	level_11.waves[2].wave_array[17] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 3,  SDL_TRUE, {0, 305}, 0};
	level_11.waves[2].wave_array[18] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 4,  SDL_TRUE, {0, 286}, 0};
	level_11.waves[2].wave_array[19] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 5,  SDL_TRUE, {0, 100}, 0};
	level_11.waves[2].wave_array[20] =  (t_wave_elem){E_SLIME_BLUE, 0, 60 + t * 6,  SDL_TRUE, {0, 133}, 0};

	level_11.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 36, SDL_FALSE, NULL};
	level_11.waves[3].wave_array = SDL_malloc(sizeof(*(level_11.waves[3].wave_array)) * level_11.waves[3].size);

	level_11.waves[3].wave_array[0] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 0 * a}, 0};
	level_11.waves[3].wave_array[1] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 1 * a}, 0};
	level_11.waves[3].wave_array[2] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 2 * a}, 0};
	level_11.waves[3].wave_array[3] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 3 * a}, 0};
	level_11.waves[3].wave_array[4] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 4 * a}, 0};
	level_11.waves[3].wave_array[5] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 5 * a}, 0};
	level_11.waves[3].wave_array[6] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 6 * a}, 0};
	level_11.waves[3].wave_array[7] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 7 * a}, 0};
	level_11.waves[3].wave_array[8] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 8 * a}, 0};
	level_11.waves[3].wave_array[9] = (t_wave_elem){E_SLIME_CYAN, 0, t * 0,  SDL_TRUE, {0, 9 * a}, 0};

	level_11.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 0 * a + 10}, 0};
	level_11.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 1 * a + 10}, 0};
	level_11.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 2 * a + 10}, 0};
	level_11.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 3 * a + 10}, 0};
	level_11.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 4 * a + 10}, 0};
	level_11.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 5 * a + 10}, 0};
	level_11.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 6 * a + 10}, 0};
	level_11.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 7 * a + 10}, 0};
	level_11.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 8 * a + 10}, 0};
	level_11.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_CYAN, 0, 15 + t * 0,  SDL_TRUE, {0, 9 * a + 10}, 0};

	level_11.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 0 * a + 20}, 0};
	level_11.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 1 * a + 20}, 0};
	level_11.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 2 * a + 20}, 0};
	level_11.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 3 * a + 20}, 0};
	level_11.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 4 * a + 20}, 0};
	level_11.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 5 * a + 20}, 0};
	level_11.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 6 * a + 20}, 0};
	level_11.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 7 * a + 20}, 0};
	level_11.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 8 * a + 20}, 0};
	level_11.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_CYAN, 0, 30 + t * 0,  SDL_TRUE, {0, 9 * a + 20}, 0};

	level_11.waves[3].wave_array[30] = (t_wave_elem){E_SLIME_PURP, 0, 40 + 20,  SDL_TRUE, {0, 90 + 120}, 0};
	level_11.waves[3].wave_array[31] = (t_wave_elem){E_SLIME_CYAN, 0, 40,  SDL_TRUE, {0, 90 + 120}, 0};
	level_11.waves[3].wave_array[32] = (t_wave_elem){E_SLIME_PURP, 0, 40 + 20,  SDL_TRUE, {0, 90 + 240}, 0};
	level_11.waves[3].wave_array[33] = (t_wave_elem){E_SLIME_CYAN, 0, 40,  SDL_TRUE, {0, 90 + 240}, 0};
	level_11.waves[3].wave_array[34] = (t_wave_elem){E_SLIME_PURP, 0, 40 + 20,  SDL_TRUE, {0, 90 + 0}, 0};
	level_11.waves[3].wave_array[35] = (t_wave_elem){E_SLIME_CYAN, 0, 40,  SDL_TRUE, {0, 90 + 0}, 0};

	level_11.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 1, SDL_FALSE, NULL};
	level_11.waves[4].wave_array = SDL_malloc(sizeof(*(level_11.waves[4].wave_array)) * level_11.waves[4].size);

	level_11.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_YELLOW, 0, 10,  SDL_TRUE, {0, 120 + 0}, 0};

	level_11.waves[5] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 20, SDL_FALSE, NULL};
	level_11.waves[5].wave_array = SDL_malloc(sizeof(*(level_11.waves[5].wave_array)) * level_11.waves[5].size);

	level_11.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,  SDL_TRUE, {0, 188}, 0};
	level_11.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,  SDL_TRUE, {0, 291}, 0};
	level_11.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2,  SDL_TRUE, {0, 54}, 0};
	level_11.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,  SDL_TRUE, {0, 156}, 0};
	level_11.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,  SDL_TRUE, {0, 70}, 0};
	level_11.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,  SDL_TRUE, {0, 251}, 0};
	level_11.waves[5].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,  SDL_TRUE, {0, 89}, 0};
	level_11.waves[5].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 7,  SDL_TRUE, {0, 257}, 0};
	level_11.waves[5].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,  SDL_TRUE, {0, 236}, 0};
	level_11.waves[5].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,  SDL_TRUE, {0, 106}, 0};
	level_11.waves[5].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10,  SDL_TRUE, {0, 60}, 0};
	level_11.waves[5].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11,  SDL_TRUE, {0, 153}, 0};
	level_11.waves[5].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12,  SDL_TRUE, {0, 21}, 0};
	level_11.waves[5].wave_array[13] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 13,  SDL_TRUE, {0, 268}, 0};
	level_11.waves[5].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14,  SDL_TRUE, {0, 321}, 0};
	level_11.waves[5].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15,  SDL_TRUE, {0, 153}, 0};
	level_11.waves[5].wave_array[16] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 16,  SDL_TRUE, {0, 294}, 0};
	level_11.waves[5].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17,  SDL_TRUE, {0, 69}, 0};
	level_11.waves[5].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18,  SDL_TRUE, {0, 235}, 0};
	level_11.waves[5].wave_array[19] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 19,  SDL_TRUE, {0, 141}, 0};

	return (level_11);
}