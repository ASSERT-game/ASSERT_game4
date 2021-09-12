#include "main.h"
#include "entity.h"

t_wave_m	level_09(void)
{
	t_wave_m level_09 = {
		.wave_id = 8,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 5,

		.size = 6,
	};

	level_09.waves = SDL_malloc(sizeof(*(level_09.waves)) * level_09.size);

	level_09.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 2, SDL_FALSE, NULL};
	level_09.waves[0].wave_array = SDL_malloc(sizeof(*(level_09.waves[0].wave_array)) * level_09.waves[0].size);

	level_09.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_09.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 270}, 0};

	level_09.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_09.waves[1].wave_array = SDL_malloc(sizeof(*(level_09.waves[1].wave_array)) * level_09.waves[1].size);

	int	t = 20;
	level_09.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 141}, 0};
	level_09.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 334}, 0};
	level_09.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 356}, 0};
	level_09.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_PURP, 0, t * 3, SDL_TRUE, {0, 236}, 0};
	level_09.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 241}, 0};
	level_09.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 110}, 0};
	level_09.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 41}, 0};
	level_09.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 199}, 0};
	level_09.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 8}, 0};
	level_09.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 158}, 0};
	level_09.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 132}, 0};
	level_09.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_PURP, 0, t * 11, SDL_TRUE, {0, 121}, 0};
	level_09.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 3}, 0};
	level_09.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 23}, 0};
	level_09.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 349}, 0};
	level_09.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 69}, 0};

	level_09.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_09.waves[2].wave_array = SDL_malloc(sizeof(*(level_09.waves[2].wave_array)) * level_09.waves[2].size);

	level_09.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 70}, 0};
	level_09.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 329}, 0};
	level_09.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, t * 2 - 10, SDL_TRUE, {0, 234}, 0};
	level_09.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_PURP, (4 << 8), t * 3, SDL_TRUE, {0, 234}, 0};
	level_09.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 201}, 0};
	level_09.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 23}, 0};
	level_09.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 159}, 0};
	level_09.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_PURP, 0, t * 7, SDL_TRUE, {0, 306}, 0};
	level_09.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 30}, 0};
	level_09.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 355}, 0};
	level_09.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, t * 10 - 10, SDL_TRUE, {0, 94}, 0};
	level_09.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_PURP, (4 << 8), t * 11, SDL_TRUE, {0, 94}, 0};
	level_09.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 147}, 0};
	level_09.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 37}, 0};
	level_09.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 255}, 0};
	level_09.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_PURP, 0, t * 15, SDL_TRUE, {0, 144}, 0};

	level_09.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 3, SDL_FALSE, NULL};
	level_09.waves[3].wave_array = SDL_malloc(sizeof(*(level_09.waves[3].wave_array)) * level_09.waves[3].size);

	level_09.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 120 + 90}, 0};
	level_09.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 240 + 90}, 0};
	level_09.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 360 + 90}, 0};

	level_09.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 33, SDL_FALSE, NULL};
	level_09.waves[4].wave_array = SDL_malloc(sizeof(*(level_09.waves[4].wave_array)) * level_09.waves[4].size);

	int a = 18;
	level_09.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 0}, 0};
	level_09.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 1}, 0};
	level_09.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 2}, 0};
	level_09.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 3}, 0};
	level_09.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 7}, 0};
	level_09.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 8}, 0};
	level_09.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 9}, 0};
	level_09.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 10}, 0};
	level_09.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 14}, 0};
	level_09.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 15}, 0};
	level_09.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 40, SDL_TRUE, {0, a * 16}, 0};
	level_09.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 0}, 0};
	level_09.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 1}, 0};
	level_09.waves[4].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 2}, 0};
	level_09.waves[4].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 3}, 0};
	level_09.waves[4].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 7}, 0};
	level_09.waves[4].wave_array[16] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 8}, 0};
	level_09.waves[4].wave_array[17] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 9}, 0};
	level_09.waves[4].wave_array[18] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 10}, 0};
	level_09.waves[4].wave_array[19] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 14}, 0};
	level_09.waves[4].wave_array[20] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 15}, 0};
	level_09.waves[4].wave_array[21] = (t_wave_elem){E_SLIME_CYAN, 0, 70, SDL_TRUE, {0, a * 16}, 0};
	level_09.waves[4].wave_array[22] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 0}, 0};
	level_09.waves[4].wave_array[23] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 1}, 0};
	level_09.waves[4].wave_array[24] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 2}, 0};
	level_09.waves[4].wave_array[25] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 3}, 0};
	level_09.waves[4].wave_array[26] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 7}, 0};
	level_09.waves[4].wave_array[27] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 8}, 0};
	level_09.waves[4].wave_array[28] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 9}, 0};
	level_09.waves[4].wave_array[29] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 10}, 0};
	level_09.waves[4].wave_array[30] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 14}, 0};
	level_09.waves[4].wave_array[31] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 15}, 0};
	level_09.waves[4].wave_array[32] = (t_wave_elem){E_SLIME_CYAN, 0, 100, SDL_TRUE, {0, a * 16}, 0};

	level_09.waves[5] = (t_wave){0, WAVE_TICKS, 120, SDL_FALSE, SDL_FALSE, 3, SDL_FALSE, NULL};
	level_09.waves[5].wave_array = SDL_malloc(sizeof(*(level_09.waves[5].wave_array)) * level_09.waves[5].size);

	level_09.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 120 + 90}, 0};
	level_09.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 240 + 90}, 0};
	level_09.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_PURP, 0, 0, SDL_TRUE, {0, 360 + 90}, 0};

	return (level_09);
}