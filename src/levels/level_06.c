#include "main.h"
#include "entity.h"

t_wave_m	level_06(void)
{
	t_wave_m level_06 = {
		.wave_id = 5,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 5,

		.size = 6,
	};

	level_06.waves = SDL_malloc(sizeof(*(level_06.waves)) * level_06.size);

	level_06.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 8, SDL_FALSE, NULL};
	level_06.waves[0].wave_array = SDL_malloc(sizeof(*(level_06.waves[0].wave_array)) * level_06.waves[0].size);

	level_06.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 25, SDL_TRUE, {0, 8}, 0};
	level_06.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_06.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 25, SDL_TRUE, {0, -8}, 0};
	level_06.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40, SDL_TRUE, {0, 0}, 0};

	level_06.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 25 + 130, SDL_TRUE, {0, 180 + 8}, 0};
	level_06.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 0 + 130, SDL_TRUE, {0, 180 + 0}, 0};
	level_06.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 25 + 130, SDL_TRUE, {0, 180 + -8}, 0};
	level_06.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, (4 << 8), 40 + 130, SDL_TRUE, {0, 180 + 0}, 0};

	level_06.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 6, SDL_FALSE, NULL};
	level_06.waves[1].wave_array = SDL_malloc(sizeof(*(level_06.waves[1].wave_array)) * level_06.waves[1].size);

	int a = 360 / 6;
	level_06.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0 * a}, 0};
	level_06.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 1 * a}, 0};
	level_06.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 2 * a}, 0};
	level_06.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 3 * a}, 0};
	level_06.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 4 * a}, 0};
	level_06.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 5 * a}, 0};

	level_06.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 10, SDL_FALSE, NULL};
	level_06.waves[2].wave_array = SDL_malloc(sizeof(*(level_06.waves[2].wave_array)) * level_06.waves[2].size);

	int t = 18;
	level_06.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 0 * a}, 0};
	level_06.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 1 * a}, 0};
	level_06.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 2 * a}, 0};
	level_06.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 3 * a}, 0};
	level_06.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 4 * a}, 0};
	level_06.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 5 * a}, 0};
	level_06.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 6 * a}, 0};
	level_06.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 7 * a}, 0};
	level_06.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 8 * a}, 0};
	level_06.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 9 * a}, 0};

	level_06.waves[3] = (t_wave){0, WAVE_TICKS, t * 10, SDL_FALSE, SDL_FALSE, 6, SDL_FALSE, NULL};
	level_06.waves[3].wave_array = SDL_malloc(sizeof(*(level_06.waves[3].wave_array)) * level_06.waves[3].size);

	level_06.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 0 * a}, 0};
	level_06.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 1 * a}, 0};
	level_06.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 2 * a}, 0};
	level_06.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 3 * a}, 0};
	level_06.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 4 * a}, 0};
	level_06.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 5 * a}, 0};

	level_06.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 10, SDL_FALSE, NULL};
	level_06.waves[4].wave_array = SDL_malloc(sizeof(*(level_06.waves[4].wave_array)) * level_06.waves[4].size);

	level_06.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 0 * a}, 0};
	level_06.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 1 * a}, 0};
	level_06.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 2 * a}, 0};
	level_06.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 3 * a}, 0};
	level_06.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 4 * a}, 0};
	level_06.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 5 * a}, 0};
	level_06.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 6 * a}, 0};
	level_06.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 7 * a}, 0};
	level_06.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 8 * a}, 0};
	level_06.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 9 * a}, 0};

	level_06.waves[5] = (t_wave){0, WAVE_TICKS, t * 10, SDL_FALSE, SDL_FALSE, 6, SDL_FALSE, NULL};
	level_06.waves[5].wave_array = SDL_malloc(sizeof(*(level_06.waves[5].wave_array)) * level_06.waves[5].size);

	level_06.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 0 * a}, 0};
	level_06.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 1 * a}, 0};
	level_06.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 2 * a}, 0};
	level_06.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 3 * a}, 0};
	level_06.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 4 * a}, 0};
	level_06.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 15 + 5 * a}, 0};

	return level_06;
}