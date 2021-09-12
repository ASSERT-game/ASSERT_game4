#include "main.h"
#include "entity.h"

t_wave_m	level_08(void)
{
	t_wave_m level_08 = {
		.wave_id = 7,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 4,

		.size = 5,
	};

	level_08.waves = SDL_malloc(sizeof(*(level_08.waves)) * level_08.size);

	level_08.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 12, SDL_FALSE, NULL};
	level_08.waves[0].wave_array = SDL_malloc(sizeof(*(level_08.waves[0].wave_array)) * level_08.waves[0].size);

	int t = 10;
	level_08.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0 * t, SDL_TRUE, {0, 230}, 0};
	level_08.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 1 * t, SDL_TRUE, {0, 48}, 0};
	level_08.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 2 * t, SDL_TRUE, {0, 98}, 0};
	level_08.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 3 * t, SDL_TRUE, {0, 65}, 0};
	level_08.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 4 * t, SDL_TRUE, {0, 283}, 0};
	level_08.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 5 * t, SDL_TRUE, {0, 159}, 0};
	level_08.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 6 * t, SDL_TRUE, {0, 333}, 0};
	level_08.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 124}, 0};
	level_08.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 8 * t, SDL_TRUE, {0, 240}, 0};
	level_08.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 9 * t, SDL_TRUE, {0, 141}, 0};
	level_08.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 36}, 0};
	level_08.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 11 * t, SDL_TRUE, {0, 63}, 0};

	level_08.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 32, SDL_FALSE, NULL};
	level_08.waves[1].wave_array = SDL_malloc(sizeof(*(level_08.waves[1].wave_array)) * level_08.waves[1].size);

	level_08.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 45 - 15}, 0};
	level_08.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 45}, 0};
	level_08.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 45 + 15}, 0};
	level_08.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 135 - 15}, 0};
	level_08.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 135}, 0};
	level_08.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 135 + 15}, 0};
	level_08.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 225 - 15}, 0};
	level_08.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 225}, 0};
	level_08.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 225 + 15}, 0};
	level_08.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 315 - 15}, 0};
	level_08.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 315}, 0};
	level_08.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 315 + 15}, 0};

	level_08.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 45 - 15}, 0};
	level_08.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 45}, 0};
	level_08.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 45 + 15}, 0};
	level_08.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 135 - 15}, 0};
	level_08.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 135}, 0};
	level_08.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 135 + 15}, 0};
	level_08.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 225 - 15}, 0};
	level_08.waves[1].wave_array[19] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 225}, 0};
	level_08.waves[1].wave_array[20] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 225 + 15}, 0};
	level_08.waves[1].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 315 - 15}, 0};
	level_08.waves[1].wave_array[22] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 315}, 0};
	level_08.waves[1].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 60, SDL_TRUE, {0, 315 + 15}, 0};

	level_08.waves[1].wave_array[24] =  (t_wave_elem){E_SLIME_CYAN, 0, 120, SDL_TRUE, {0, 0}, 0};
	level_08.waves[1].wave_array[25] =  (t_wave_elem){E_SLIME_CYAN, 0, 120, SDL_TRUE, {0, 90}, 0};
	level_08.waves[1].wave_array[26] =  (t_wave_elem){E_SLIME_CYAN, 0, 120, SDL_TRUE, {0, 180}, 0};
	level_08.waves[1].wave_array[27] =  (t_wave_elem){E_SLIME_CYAN, 0, 120, SDL_TRUE, {0, 270}, 0};

	level_08.waves[1].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_08.waves[1].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_08.waves[1].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 180}, 0};
	level_08.waves[1].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 270}, 0};

	level_08.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_08.waves[2].wave_array = SDL_malloc(sizeof(*(level_08.waves[2].wave_array)) * level_08.waves[2].size);

	t = 14;
	level_08.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 0 * t, SDL_TRUE, {0, 48}, 0};
	level_08.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 1 * t + 10, SDL_TRUE, {0, 48}, 0};
	level_08.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 2 * t, SDL_TRUE, {0, 98}, 0};
	level_08.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 3 * t, SDL_TRUE, {0, 65}, 0};
	level_08.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 4 * t, SDL_TRUE, {0, 283}, 0};
	level_08.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 5 * t + 10, SDL_TRUE, {0, 283}, 0};
	level_08.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 6 * t, SDL_TRUE, {0, 333}, 0};
	level_08.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 7 * t, SDL_TRUE, {0, 124}, 0};
	level_08.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 8 * t, SDL_TRUE, {0, 240}, 0};
	level_08.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 9 * t + 10, SDL_TRUE, {0, 240}, 0};
	level_08.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 10 * t, SDL_TRUE, {0, 36}, 0};
	level_08.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 11 * t, SDL_TRUE, {0, 63}, 0};
	level_08.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 12 * t + 10, SDL_TRUE, {0, 63}, 0};
	level_08.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 13 * t, SDL_TRUE, {0, 178}, 0};
	level_08.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 14 * t, SDL_TRUE, {0, 237}, 0};
	level_08.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, (4 << 8), 14 * t + 10, SDL_TRUE, {0, 237}, 0};

	level_08.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 38, SDL_FALSE, NULL};
	level_08.waves[3].wave_array = SDL_malloc(sizeof(*(level_08.waves[3].wave_array)) * level_08.waves[3].size);

	int a = 22;
	level_08.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 0 * a + 127}, 0};
	level_08.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 1 * a + 127}, 0};
	level_08.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 2 * a + 127}, 0};
	level_08.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 3 * a + 127}, 0};
	level_08.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 4 * a + 127}, 0};
	level_08.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 5 * a + 127}, 0};
	level_08.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 6 * a + 127}, 0};
	level_08.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 7 * a + 127}, 0};
	level_08.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 8 * a + 127}, 0};
	level_08.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 9 * a + 127}, 0};
	level_08.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 10 * a + 127}, 0};
	level_08.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 11 * a + 127}, 0};
	level_08.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 12 * a + 127}, 0};
	level_08.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 13 * a + 127}, 0};

	level_08.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 0 * a + 127}, 0};
	level_08.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 1 * a + 127}, 0};
	level_08.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 2 * a + 127}, 0};
	level_08.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 3 * a + 127}, 0};
	level_08.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 4 * a + 127}, 0};
	level_08.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 5 * a + 127}, 0};
	level_08.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 6 * a + 127}, 0};
	level_08.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 7 * a + 127}, 0};
	level_08.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 8 * a + 127}, 0};
	level_08.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 9 * a + 127}, 0};
	level_08.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 10 * a + 127}, 0};
	level_08.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 11 * a + 127}, 0};
	level_08.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 12 * a + 127}, 0};
	level_08.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_CYAN, 0, 50, SDL_TRUE, {0, 13 * a + 127}, 0};

	// 74
	level_08.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 0 + 80, SDL_TRUE, {0, 21 + 53}, 0};
	level_08.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 1 + 80, SDL_TRUE, {0, 56 + 53}, 0};
	level_08.waves[3].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 2 + 80, SDL_TRUE, {0, 44 + 53}, 0};
	level_08.waves[3].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 3 + 80, SDL_TRUE, {0, 19 + 53}, 0};
	level_08.waves[3].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, t * 4 + 80, SDL_TRUE, {0, 50 + 53}, 0};
	level_08.waves[3].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, t * 5 + 80, SDL_TRUE, {0, 8 + 53}, 0};
	level_08.waves[3].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, t * 6 + 80, SDL_TRUE, {0, 43 + 53}, 0};
	level_08.waves[3].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, t * 7 + 80, SDL_TRUE, {0, 19 + 53}, 0};
	level_08.waves[3].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, t * 8 + 80, SDL_TRUE, {0, 46 + 53}, 0};
	level_08.waves[3].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, t * 9 + 80, SDL_TRUE, {0, 54 + 53}, 0};

	level_08.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 2, SDL_FALSE, NULL};
	level_08.waves[4].wave_array = SDL_malloc(sizeof(*(level_08.waves[4].wave_array)) * level_08.waves[4].size);

	level_08.waves[4].wave_array[0] = (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_08.waves[4].wave_array[1] = (t_wave_elem){E_SLIME_PURP, 0, 20, SDL_TRUE, {0, 0}, 0};

	return level_08;
}