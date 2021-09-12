#include "main.h"
#include "entity.h"

t_wave_m	level_16(void)
{
	t_wave_m level_16 = {
		.wave_id = 15,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 7,
		.win_wave = 0,

		.size = 7,
	};

	level_16.waves = SDL_malloc(sizeof(*(level_16.waves)) * level_16.size);

	level_16.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 4, SDL_FALSE, NULL};
	level_16.waves[0].wave_array = SDL_malloc(sizeof(*(level_16.waves[0].wave_array)) * level_16.waves[0].size);

	level_16.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_SPINY, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_16.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_SPINY, 0, 20, SDL_TRUE, {0, 90}, 0};
	level_16.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_SPINY, 0, 0, SDL_TRUE, {0, 180}, 0};
	level_16.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_SPINY, 0, 20, SDL_TRUE, {0, 270}, 0};

	level_16.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 19, SDL_FALSE, NULL};
	level_16.waves[1].wave_array = SDL_malloc(sizeof(*(level_16.waves[1].wave_array)) * level_16.waves[1].size);
	int t;

	t = 23;
	level_16.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 0, SDL_TRUE, {0, 60}, 0};
	level_16.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 1, SDL_TRUE, {0, 270}, 0};
	level_16.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 2, SDL_TRUE, {0, 332}, 0};
	level_16.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 3, SDL_TRUE, {0, 355}, 0};
	level_16.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 4, SDL_TRUE, {0, 132}, 0};
	level_16.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 5, SDL_TRUE, {0, 211}, 0};
	level_16.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 6, SDL_TRUE, {0, 355}, 0};
	level_16.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 7, SDL_TRUE, {0, 225}, 0};
	level_16.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 8, SDL_TRUE, {0, 135}, 0};
	level_16.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 9, SDL_TRUE, {0, 244}, 0};
	level_16.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 10, SDL_TRUE, {0, 262}, 0};
	level_16.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 11, SDL_TRUE, {0, 181}, 0};
	level_16.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 12, SDL_TRUE, {0, 300}, 0};
	level_16.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 13, SDL_TRUE, {0, 58}, 0};
	level_16.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 14, SDL_TRUE, {0, 83}, 0};
	level_16.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 15, SDL_TRUE, {0, 152}, 0};
	level_16.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 16, SDL_TRUE, {0, 218}, 0};
	level_16.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 17, SDL_TRUE, {0, 134}, 0};
	level_16.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 18, SDL_TRUE, {0, 12}, 0};

	level_16.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 20, SDL_FALSE, NULL};
	level_16.waves[2].wave_array = SDL_malloc(sizeof(*(level_16.waves[2].wave_array)) * level_16.waves[2].size);

	level_16.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_SPINY, 0, 0, SDL_TRUE, {0, 0}, 0};
	level_16.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_SPINY, 0, 15, SDL_TRUE, {0, 0}, 0};
	level_16.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_SPINY, 0, 30, SDL_TRUE, {0, 0}, 0};
	level_16.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_YELLOW, 0, 34, SDL_TRUE, {0, 100}, 0};
	level_16.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_YELLOW, 0, 34, SDL_TRUE, {0, 360 - 100}, 0};

	level_16.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_SPINY,  0, 0 + 0, SDL_TRUE, {0, 180 + 0}, 0};
	level_16.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_SPINY,  0, 0 + 15, SDL_TRUE, {0, 180 + 0}, 0};
	level_16.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_SPINY,  0, 0 + 30, SDL_TRUE, {0, 180 + 0}, 0};
	level_16.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_YELLOW, 0, 0 + 34, SDL_TRUE, {0, 180 + 100}, 0};
	level_16.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_YELLOW, 0, 0 + 34, SDL_TRUE, {0, 180 + 360 - 100}, 0};

	level_16.waves[2].wave_array[10] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 0, SDL_TRUE, {0, 0 + 90}, 0};
	level_16.waves[2].wave_array[11] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 15, SDL_TRUE, {0, 0 + 90}, 0};
	level_16.waves[2].wave_array[12] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 30, SDL_TRUE, {0, 0 + 90}, 0};
	level_16.waves[2].wave_array[13] =  (t_wave_elem){E_SLIME_YELLOW, 0, 80 + 34, SDL_TRUE, {0, 100 + 90}, 0};
	level_16.waves[2].wave_array[14] =  (t_wave_elem){E_SLIME_YELLOW, 0, 80 + 34, SDL_TRUE, {0, 360 - 100 + 90}, 0};
	level_16.waves[2].wave_array[15] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 0 + 0, SDL_TRUE, {0, 180 + 0 + 90}, 0};
	level_16.waves[2].wave_array[16] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 0 + 15, SDL_TRUE, {0, 180 + 0 + 90}, 0};
	level_16.waves[2].wave_array[17] =  (t_wave_elem){E_SLIME_SPINY,  0, 80 + 0 + 30, SDL_TRUE, {0, 180 + 0 + 90}, 0};
	level_16.waves[2].wave_array[18] =  (t_wave_elem){E_SLIME_YELLOW, 0, 80 + 0 + 34, SDL_TRUE, {0, 180 + 100 + 90}, 0};
	level_16.waves[2].wave_array[19] =  (t_wave_elem){E_SLIME_YELLOW, 0, 80 + 0 + 34, SDL_TRUE, {0, 180 + 360 - 100 + 90}, 0};

	level_16.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 37, SDL_FALSE, NULL};
	level_16.waves[3].wave_array = SDL_malloc(sizeof(*(level_16.waves[3].wave_array)) * level_16.waves[3].size);

	t = 10;
	level_16.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE,  {0, 243}, 0};
	level_16.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE,  {0, 89}, 0};
	level_16.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE,  {0, 125}, 0};
	level_16.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE,  {0, 124}, 0};
	level_16.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE,  {0, 307}, 0};
	level_16.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE,  {0, 322}, 0};
	level_16.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE,  {0, 59}, 0};
	level_16.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE,  {0, 327}, 0};
	level_16.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE,  {0, 305}, 0};
	level_16.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE,  {0, 179}, 0};
	level_16.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 0}, 0};
	level_16.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 17}, 0};
	level_16.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 352}, 0};
	level_16.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 348}, 0};
	level_16.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, 96}, 0};
	level_16.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 15, SDL_TRUE, {0, 174}, 0};
	level_16.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 16, SDL_TRUE, {0, 357}, 0};
	level_16.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 17, SDL_TRUE, {0, 29}, 0};
	level_16.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 18, SDL_TRUE, {0, 124}, 0};
	level_16.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, t * 19, SDL_TRUE, {0, 243}, 0};
	level_16.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, t * 20, SDL_TRUE, {0, 73}, 0};
	level_16.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, t * 21, SDL_TRUE, {0, 301}, 0};
	level_16.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, t * 22, SDL_TRUE, {0, 161}, 0};
	level_16.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, t * 23, SDL_TRUE, {0, 123}, 0};
	level_16.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, t * 24, SDL_TRUE, {0, 65}, 0};
	level_16.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, t * 25, SDL_TRUE, {0, 348}, 0};
	level_16.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, t * 26, SDL_TRUE, {0, 266}, 0};
	level_16.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,  0, t * 27, SDL_TRUE, {0, 69}, 0};
	level_16.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, t * 28, SDL_TRUE, {0, 88}, 0};
	level_16.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, t * 29, SDL_TRUE, {0, 299}, 0};
	level_16.waves[3].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,  0, t * 30, SDL_TRUE, {0, 227}, 0};
	level_16.waves[3].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,  0, t * 31, SDL_TRUE, {0, 5}, 0};
	level_16.waves[3].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, t * 32, SDL_TRUE, {0, 238}, 0};
	level_16.waves[3].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, t * 33, SDL_TRUE, {0, 209}, 0};
	level_16.waves[3].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,  0, t * 34, SDL_TRUE, {0, 282}, 0};
	level_16.waves[3].wave_array[35] = (t_wave_elem){E_SLIME_BLUE,  0, t * 35, SDL_TRUE, {0, 156}, 0};
	level_16.waves[3].wave_array[36] = (t_wave_elem){E_SLIME_BLUE,  0, t * 36, SDL_TRUE, {0, 90}, 0};

	level_16.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_16.waves[4].wave_array = SDL_malloc(sizeof(*(level_16.waves[4].wave_array)) * level_16.waves[4].size);

	int	a = 360 / 15;
	level_16.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_16.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_16.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_16.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_16.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_16.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_16.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_16.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_16.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_16.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_16.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_16.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 11}, 0};
	level_16.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 12}, 0};
	level_16.waves[4].wave_array[13] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 13}, 0};
	level_16.waves[4].wave_array[14] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 14}, 0};
	level_16.waves[4].wave_array[15] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 15}, 0};

	level_16.waves[5] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_16.waves[5].wave_array = SDL_malloc(sizeof(*(level_16.waves[5].wave_array)) * level_16.waves[5].size);

	level_16.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, 12}, 0};
	level_16.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_SPINY, (4 << 8), 18, SDL_TRUE, {0, 0}, 0};
	level_16.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, -12}, 0};
	level_16.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,  0, 0 + 70, SDL_TRUE, {0, 50 + 12}, 0};
	level_16.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_SPINY, (4 << 8), 18 + 70, SDL_TRUE, {0, 50 + 0}, 0};
	level_16.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,  0, 0 + 70, SDL_TRUE, {0, 50 + -12}, 0};
	level_16.waves[5].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,  0, 0 + 140, SDL_TRUE, {0, 321 + 12}, 0};
	level_16.waves[5].wave_array[7] =  (t_wave_elem){E_SLIME_SPINY, (4 << 8), 18 + 140, SDL_TRUE, {0, 321 + 0}, 0};
	level_16.waves[5].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,  0, 0 + 140, SDL_TRUE, {0, 321 + -12}, 0};
	level_16.waves[5].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,  0, 0 + 210, SDL_TRUE, {0, 120 + 12}, 0};
	level_16.waves[5].wave_array[10] = (t_wave_elem){E_SLIME_SPINY, (4 << 8), 18 + 210, SDL_TRUE, {0, 120 + 0}, 0};
	level_16.waves[5].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,  0, 0 + 210, SDL_TRUE, {0, 120 + -12}, 0};

	level_16.waves[6] = (t_wave){0, WAVE_TICKS, 150, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_16.waves[6].wave_array = SDL_malloc(sizeof(*(level_16.waves[6].wave_array)) * level_16.waves[6].size);

	level_16.waves[6].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_16.waves[6].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_16.waves[6].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_16.waves[6].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_16.waves[6].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_16.waves[6].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_16.waves[6].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_16.waves[6].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_16.waves[6].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_16.waves[6].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_16.waves[6].wave_array[10] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_16.waves[6].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 11}, 0};
	level_16.waves[6].wave_array[12] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 12}, 0};
	level_16.waves[6].wave_array[13] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 13}, 0};
	level_16.waves[6].wave_array[14] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 14}, 0};
	level_16.waves[6].wave_array[15] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 15}, 0};

	return (level_16);
}