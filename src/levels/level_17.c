#include "main.h"
#include "entity.h"

t_wave_m	level_17(void)
{
	t_wave_m level_17 = {
		.wave_id = 16,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 6,
		.win_wave = 0,

		.size = 6,
	};

	level_17.waves = SDL_malloc(sizeof(*(level_17.waves)) * level_17.size);

	level_17.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 37, SDL_FALSE, NULL};
	level_17.waves[0].wave_array = SDL_malloc(sizeof(*(level_17.waves[0].wave_array)) * level_17.waves[0].size);

	int	t = 8;
	level_17.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE,  {0, 243}, 0};
	level_17.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE,  {0, 89}, 0};
	level_17.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE,  {0, 125}, 0};
	level_17.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE,  {0, 124}, 0};
	level_17.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE,  {0, 307}, 0};
	level_17.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE,  {0, 322}, 0};
	level_17.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE,  {0, 59}, 0};
	level_17.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE,  {0, 327}, 0};
	level_17.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE,  {0, 305}, 0};
	level_17.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE,  {0, 179}, 0};
	level_17.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 0}, 0};
	level_17.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 17}, 0};
	level_17.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 352}, 0};
	level_17.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 348}, 0};
	level_17.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, 96}, 0};
	level_17.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 15, SDL_TRUE, {0, 174}, 0};
	level_17.waves[0].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 16, SDL_TRUE, {0, 357}, 0};
	level_17.waves[0].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 17, SDL_TRUE, {0, 29}, 0};
	level_17.waves[0].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 18, SDL_TRUE, {0, 124}, 0};
	level_17.waves[0].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, t * 19, SDL_TRUE, {0, 243}, 0};
	level_17.waves[0].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, t * 20, SDL_TRUE, {0, 73}, 0};
	level_17.waves[0].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, t * 21, SDL_TRUE, {0, 301}, 0};
	level_17.waves[0].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, t * 22, SDL_TRUE, {0, 161}, 0};
	level_17.waves[0].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, t * 23, SDL_TRUE, {0, 123}, 0};
	level_17.waves[0].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, t * 24, SDL_TRUE, {0, 65}, 0};
	level_17.waves[0].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, t * 25, SDL_TRUE, {0, 348}, 0};
	level_17.waves[0].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, t * 26, SDL_TRUE, {0, 266}, 0};
	level_17.waves[0].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,  0, t * 27, SDL_TRUE, {0, 69}, 0};
	level_17.waves[0].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, t * 28, SDL_TRUE, {0, 88}, 0};
	level_17.waves[0].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, t * 29, SDL_TRUE, {0, 299}, 0};
	level_17.waves[0].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,  0, t * 30, SDL_TRUE, {0, 227}, 0};
	level_17.waves[0].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,  0, t * 31, SDL_TRUE, {0, 5}, 0};
	level_17.waves[0].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, t * 32, SDL_TRUE, {0, 238}, 0};
	level_17.waves[0].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, t * 33, SDL_TRUE, {0, 209}, 0};
	level_17.waves[0].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,  0, t * 34, SDL_TRUE, {0, 282}, 0};
	level_17.waves[0].wave_array[35] = (t_wave_elem){E_SLIME_BLUE,  0, t * 35, SDL_TRUE, {0, 156}, 0};
	level_17.waves[0].wave_array[36] = (t_wave_elem){E_SLIME_BLUE,  0, t * 36, SDL_TRUE, {0, 90}, 0};

	level_17.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 9, SDL_FALSE, NULL};
	level_17.waves[1].wave_array = SDL_malloc(sizeof(*(level_17.waves[1].wave_array)) * level_17.waves[1].size);

	int	a = 360 / 9;
	level_17.waves[1].wave_array[0] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_17.waves[1].wave_array[1] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_17.waves[1].wave_array[2] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_17.waves[1].wave_array[3] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_17.waves[1].wave_array[4] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_17.waves[1].wave_array[5] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_17.waves[1].wave_array[6] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_17.waves[1].wave_array[7] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_17.waves[1].wave_array[8] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, a * 8}, 0};

	level_17.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 30, SDL_FALSE, NULL};
	level_17.waves[2].wave_array = SDL_malloc(sizeof(*(level_17.waves[2].wave_array)) * level_17.waves[2].size);

	t = 10;
	level_17.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 283}, 0};
	level_17.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 215}, 0};
	level_17.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 332}, 0};
	level_17.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 219}, 0};
	level_17.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 35}, 0};
	level_17.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 21}, 0};
	level_17.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 76}, 0};
	level_17.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 280}, 0};
	level_17.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 270}, 0};
	level_17.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 93}, 0};
	level_17.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 288}, 0};
	level_17.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 338}, 0};
	level_17.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 23}, 0};
	level_17.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 261}, 0};
	level_17.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, 335}, 0};
	level_17.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 15, SDL_TRUE, {0, 27}, 0};
	level_17.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 16, SDL_TRUE, {0, 41}, 0};
	level_17.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 17, SDL_TRUE, {0, 298}, 0};

	level_17.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_CYAN,  0, 42 + 0, SDL_TRUE, {0, 274}, 0};
	level_17.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_CYAN,  0, 42 + 20, SDL_TRUE, {0, 274}, 0};
	level_17.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_CYAN,  0, 42 + 40, SDL_TRUE, {0, 274}, 0};
	level_17.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_CYAN,  0, 42 + 60, SDL_TRUE, {0, 274}, 0};
	level_17.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_CYAN,  0, 84 + 0, SDL_TRUE, {0, 320}, 0};
	level_17.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_CYAN,  0, 84 + 20, SDL_TRUE, {0, 320}, 0};
	level_17.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_CYAN,  0, 84 + 40, SDL_TRUE, {0, 320}, 0};
	level_17.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_CYAN,  0, 84 + 60, SDL_TRUE, {0, 320}, 0};
	level_17.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_CYAN,  0, 126 + 0, SDL_TRUE, {0, 142}, 0};
	level_17.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_CYAN,  0, 126 + 20, SDL_TRUE, {0, 142}, 0};
	level_17.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_CYAN,  0, 126 + 40, SDL_TRUE, {0, 142}, 0};
	level_17.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_CYAN,  0, 126 + 60, SDL_TRUE, {0, 142}, 0};

	level_17.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 15, SDL_FALSE, NULL};
	level_17.waves[3].wave_array = SDL_malloc(sizeof(*(level_17.waves[3].wave_array)) * level_17.waves[3].size);

	t = 22;
	level_17.waves[3].wave_array[0] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 0, SDL_TRUE, {0, 20}, 0};
	level_17.waves[3].wave_array[1] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 1, SDL_TRUE, {0, 214}, 0};
	level_17.waves[3].wave_array[2] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 2, SDL_TRUE, {0, 233}, 0};
	level_17.waves[3].wave_array[3] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 3, SDL_TRUE, {0, 82}, 0};
	level_17.waves[3].wave_array[4] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 4, SDL_TRUE, {0, 218}, 0};
	level_17.waves[3].wave_array[5] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 5, SDL_TRUE, {0, 237}, 0};
	level_17.waves[3].wave_array[6] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 6, SDL_TRUE, {0, 289}, 0};
	level_17.waves[3].wave_array[7] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 7, SDL_TRUE, {0, 225}, 0};
	level_17.waves[3].wave_array[8] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 8, SDL_TRUE, {0, 21}, 0};
	level_17.waves[3].wave_array[9] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 9, SDL_TRUE, {0, 256}, 0};
	level_17.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 10, SDL_TRUE, {0, 60}, 0};
	level_17.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 11, SDL_TRUE, {0, 1}, 0};
	level_17.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 12, SDL_TRUE, {0, 110}, 0};
	level_17.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 13, SDL_TRUE, {0, 135}, 0};
	level_17.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_YELLOW,  0, t * 14, SDL_TRUE, {0, 217}, 0};

	level_17.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 35, SDL_FALSE, NULL};
	level_17.waves[4].wave_array = SDL_malloc(sizeof(*(level_17.waves[4].wave_array)) * level_17.waves[4].size);

	a = 360 / 5;
	level_17.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 0 * a}, 0};
	level_17.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 1 * a}, 0};
	level_17.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 2 * a}, 0};
	level_17.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 3 * a}, 0};
	level_17.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 4 * a}, 0};
	level_17.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, 60, SDL_TRUE, {0, 0 * a + 30}, 0};
	level_17.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, 60, SDL_TRUE, {0, 1 * a + 30}, 0};
	level_17.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, 60, SDL_TRUE, {0, 2 * a + 30}, 0};
	level_17.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, 60, SDL_TRUE, {0, 3 * a + 30}, 0};
	level_17.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, 60, SDL_TRUE, {0, 4 * a + 30}, 0};
	level_17.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, 130, SDL_TRUE, {0, 0 * a + 60}, 0};
	level_17.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, 130, SDL_TRUE, {0, 1 * a + 60}, 0};
	level_17.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, 130, SDL_TRUE, {0, 2 * a + 60}, 0};
	level_17.waves[4].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, 130, SDL_TRUE, {0, 3 * a + 60}, 0};
	level_17.waves[4].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, 130, SDL_TRUE, {0, 4 * a + 60}, 0};
	level_17.waves[4].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, 190, SDL_TRUE, {0, 0 * a + 90}, 0};
	level_17.waves[4].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, 190, SDL_TRUE, {0, 1 * a + 90}, 0};
	level_17.waves[4].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, 190, SDL_TRUE, {0, 2 * a + 90}, 0};
	level_17.waves[4].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, 190, SDL_TRUE, {0, 3 * a + 90}, 0};
	level_17.waves[4].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, 190, SDL_TRUE, {0, 4 * a + 90}, 0};
	level_17.waves[4].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, 260, SDL_TRUE, {0, 0 * a + 120}, 0};
	level_17.waves[4].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, 260, SDL_TRUE, {0, 1 * a + 120}, 0};
	level_17.waves[4].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, 260, SDL_TRUE, {0, 2 * a + 120}, 0};
	level_17.waves[4].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, 260, SDL_TRUE, {0, 3 * a + 120}, 0};
	level_17.waves[4].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, 260, SDL_TRUE, {0, 4 * a + 120}, 0};
	level_17.waves[4].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, 320, SDL_TRUE, {0, 0 * a + 150}, 0};
	level_17.waves[4].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, 320, SDL_TRUE, {0, 1 * a + 150}, 0};
	level_17.waves[4].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,  0, 320, SDL_TRUE, {0, 2 * a + 150}, 0};
	level_17.waves[4].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, 320, SDL_TRUE, {0, 3 * a + 150}, 0};
	level_17.waves[4].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, 320, SDL_TRUE, {0, 4 * a + 150}, 0};
	level_17.waves[4].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,  0, 390, SDL_TRUE, {0, 0 * a + 180}, 0};
	level_17.waves[4].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,  0, 390, SDL_TRUE, {0, 1 * a + 180}, 0};
	level_17.waves[4].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, 390, SDL_TRUE, {0, 2 * a + 180}, 0};
	level_17.waves[4].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, 390, SDL_TRUE, {0, 3 * a + 180}, 0};
	level_17.waves[4].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,  0, 390, SDL_TRUE, {0, 4 * a + 180}, 0};

	level_17.waves[5] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 22, SDL_FALSE, NULL};
	level_17.waves[5].wave_array = SDL_malloc(sizeof(*(level_17.waves[5].wave_array)) * level_17.waves[5].size);

	a = 10;
	t = 20;
	level_17.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, a * 0}, 0};
	level_17.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, a * 0 + 180}, 0};
	level_17.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, a * 2}, 0};
	level_17.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, a * 2 + 180}, 0};
	level_17.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, a * 4}, 0};
	level_17.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, a * 4 + 180}, 0};
	level_17.waves[5].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, a * 6}, 0};
	level_17.waves[5].wave_array[7] =  (t_wave_elem){E_SLIME_INV,  0, t * 6, SDL_TRUE, {0, a * 6 + 180}, 0};
	level_17.waves[5].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, a * 8}, 0};
	level_17.waves[5].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, a * 8 + 180}, 0};
	level_17.waves[5].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, a * 10}, 0};
	level_17.waves[5].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, a * 10 + 180}, 0};
	level_17.waves[5].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, a * 12}, 0};
	level_17.waves[5].wave_array[13] = (t_wave_elem){E_SLIME_INV,  0, t * 12, SDL_TRUE, {0, a * 12 + 180}, 0};
	level_17.waves[5].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, a * 14}, 0};
	level_17.waves[5].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, a * 14 + 180}, 0};
	level_17.waves[5].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 16, SDL_TRUE, {0, a * 16}, 0};
	level_17.waves[5].wave_array[17] = (t_wave_elem){E_SLIME_INV,  0, t * 16, SDL_TRUE, {0, a * 16 + 180}, 0};
	level_17.waves[5].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 18, SDL_TRUE, {0, a * 18}, 0};
	level_17.waves[5].wave_array[19] = (t_wave_elem){E_SLIME_INV,  0, t * 18, SDL_TRUE, {0, a * 18 + 180}, 0};
	level_17.waves[5].wave_array[20] = (t_wave_elem){E_SLIME_INV,  0, t * 20, SDL_TRUE, {0, a * 20}, 0};
	level_17.waves[5].wave_array[21] = (t_wave_elem){E_SLIME_INV,  0, t * 20, SDL_TRUE, {0, a * 20 + 180}, 0};

	return (level_17);
}