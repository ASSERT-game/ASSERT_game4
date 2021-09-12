#include "main.h"
#include "entity.h"

t_wave_m	level_14(void)
{
	t_wave_m level_14 = {
		.wave_id = 13,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 4,

		.size = 5,
	};

	level_14.waves = SDL_malloc(sizeof(*(level_14.waves)) * level_14.size);

	level_14.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 54, SDL_FALSE, NULL};
	level_14.waves[0].wave_array = SDL_malloc(sizeof(*(level_14.waves[0].wave_array)) * level_14.waves[0].size);

	int t = 11;
	level_14.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 160}, 0};
	level_14.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 255}, 0};
	level_14.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 164}, 0};
	level_14.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 41}, 0};
	level_14.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 33}, 0};
	level_14.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 215}, 0};
	level_14.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 159}, 0};
	level_14.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 211}, 0};
	level_14.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 74}, 0};
	level_14.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 236}, 0};
	level_14.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 184}, 0};
	level_14.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 158}, 0};
	level_14.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 60}, 0};
	level_14.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 292}, 0};
	level_14.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 137}, 0};
	level_14.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 64}, 0};
	level_14.waves[0].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 9}, 0};
	level_14.waves[0].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 202}, 0};
	level_14.waves[0].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 291}, 0};
	level_14.waves[0].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 107}, 0};
	level_14.waves[0].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 49}, 0};
	level_14.waves[0].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 99}, 0};
	level_14.waves[0].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 259}, 0};
	level_14.waves[0].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, 299}, 0};
	level_14.waves[0].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, 165}, 0};
	level_14.waves[0].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25, SDL_TRUE, {0, 278}, 0};
	level_14.waves[0].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26, SDL_TRUE, {0, 225}, 0};
	level_14.waves[0].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27, SDL_TRUE, {0, 335}, 0};
	level_14.waves[0].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28, SDL_TRUE, {0, 148}, 0};
	level_14.waves[0].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29, SDL_TRUE, {0, 241}, 0};
	level_14.waves[0].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 30, SDL_TRUE, {0, 79}, 0};
	level_14.waves[0].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 31, SDL_TRUE, {0, 86}, 0};
	level_14.waves[0].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, t * 32, SDL_TRUE, {0, 20}, 0};
	level_14.waves[0].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, t * 33, SDL_TRUE, {0, 5}, 0};
	level_14.waves[0].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, t * 34, SDL_TRUE, {0, 135}, 0};
	level_14.waves[0].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, t * 35, SDL_TRUE, {0, 289}, 0};
	level_14.waves[0].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, t * 36, SDL_TRUE, {0, 206}, 0};
	level_14.waves[0].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, t * 37, SDL_TRUE, {0, 4}, 0};
	level_14.waves[0].wave_array[38] = (t_wave_elem){E_SLIME_BLUE, 0, t * 38, SDL_TRUE, {0, 40}, 0};
	level_14.waves[0].wave_array[39] = (t_wave_elem){E_SLIME_BLUE, 0, t * 39, SDL_TRUE, {0, 46}, 0};
	level_14.waves[0].wave_array[40] = (t_wave_elem){E_SLIME_BLUE, 0, t * 40, SDL_TRUE, {0, 309}, 0};
	level_14.waves[0].wave_array[41] = (t_wave_elem){E_SLIME_BLUE, 0, t * 41, SDL_TRUE, {0, 306}, 0};
	level_14.waves[0].wave_array[42] = (t_wave_elem){E_SLIME_BLUE, 0, t * 42, SDL_TRUE, {0, 353}, 0};
	level_14.waves[0].wave_array[43] = (t_wave_elem){E_SLIME_BLUE, 0, t * 43, SDL_TRUE, {0, 54}, 0};
	level_14.waves[0].wave_array[44] = (t_wave_elem){E_SLIME_BLUE, 0, t * 44, SDL_TRUE, {0, 94}, 0};
	level_14.waves[0].wave_array[45] = (t_wave_elem){E_SLIME_BLUE, 0, t * 45, SDL_TRUE, {0, 192}, 0};
	level_14.waves[0].wave_array[46] = (t_wave_elem){E_SLIME_BLUE, 0, t * 46, SDL_TRUE, {0, 25}, 0};
	level_14.waves[0].wave_array[47] = (t_wave_elem){E_SLIME_BLUE, 0, t * 47, SDL_TRUE, {0, 220}, 0};
	level_14.waves[0].wave_array[48] = (t_wave_elem){E_SLIME_BLUE, 0, t * 48, SDL_TRUE, {0, 347}, 0};
	level_14.waves[0].wave_array[49] = (t_wave_elem){E_SLIME_BLUE, 0, t * 49, SDL_TRUE, {0, 14}, 0};
	level_14.waves[0].wave_array[50] = (t_wave_elem){E_SLIME_BLUE, 0, t * 50, SDL_TRUE, {0, 322}, 0};
	level_14.waves[0].wave_array[51] = (t_wave_elem){E_SLIME_BLUE, 0, t * 51, SDL_TRUE, {0, 192}, 0};
	level_14.waves[0].wave_array[52] = (t_wave_elem){E_SLIME_BLUE, 0, t * 52, SDL_TRUE, {0, 332}, 0};
	level_14.waves[0].wave_array[53] = (t_wave_elem){E_SLIME_BLUE, 0, t * 53, SDL_TRUE, {0, 21}, 0};

	level_14.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 15, SDL_FALSE, NULL};
	level_14.waves[1].wave_array = SDL_malloc(sizeof(*(level_14.waves[1].wave_array)) * level_14.waves[1].size);

	int a = 360 / 15;
	level_14.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_14.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_14.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_14.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_14.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_14.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_14.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_14.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_14.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_14.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_14.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_14.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 11}, 0};
	level_14.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 12}, 0};
	level_14.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 13}, 0};
	level_14.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, a * 14}, 0};

	level_14.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 20, SDL_FALSE, NULL};
	level_14.waves[2].wave_array = SDL_malloc(sizeof(*(level_14.waves[2].wave_array)) * level_14.waves[2].size);

	level_14.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, 356}, 0};
	level_14.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,		0, 50 - 10, SDL_TRUE, {0, 71}, 0};
	level_14.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_YELLOW,	0, 100 - 10, SDL_TRUE, {0, 236}, 0};
	level_14.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,		0, 140 - 10, SDL_TRUE, {0, 39}, 0};
	level_14.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,		0, 180 - 10, SDL_TRUE, {0, 47}, 0};
	level_14.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_YELLOW,	0, 220 - 10, SDL_TRUE, {0, 145}, 0};
	level_14.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,		0, 250 - 12, SDL_TRUE, {0, 136}, 0};
	level_14.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,		0, 280 - 12, SDL_TRUE, {0, 325}, 0};
	level_14.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_YELLOW,	0, 310 - 12, SDL_TRUE, {0, 43}, 0};
	level_14.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,		0, 345 - 13, SDL_TRUE, {0, 69}, 0};
	level_14.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,		0, 360 - 13, SDL_TRUE, {0, 127}, 0};
	level_14.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_YELLOW,	0, 375 - 13, SDL_TRUE, {0, 129}, 0};
	level_14.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,		0, 387 - 13, SDL_TRUE, {0, 312}, 0};
	level_14.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,		0, 399 - 14, SDL_TRUE, {0, 170}, 0};
	level_14.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_YELLOW,	0, 409 - 14, SDL_TRUE, {0, 19}, 0};
	level_14.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,		0, 419 - 14, SDL_TRUE, {0, 234}, 0};
	level_14.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,		0, 429 - 14, SDL_TRUE, {0, 224}, 0};
	level_14.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_YELLOW,	0, 437 - 15, SDL_TRUE, {0, 340}, 0};
	level_14.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,		0, 445 - 15, SDL_TRUE, {0, 213}, 0};
	level_14.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,		0, 453 - 15, SDL_TRUE, {0, 79}, 0};

	level_14.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 30, SDL_FALSE, NULL};
	level_14.waves[3].wave_array = SDL_malloc(sizeof(*(level_14.waves[3].wave_array)) * level_14.waves[3].size);

	t = 9;
	a = 18;
	level_14.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, a * 0}, 0};
	level_14.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, a * 1}, 0};
	level_14.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, a * 2}, 0};
	level_14.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, a * 3}, 0};
	level_14.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, a * 4}, 0};
	level_14.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, a * 5}, 0};
	level_14.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, a * 6}, 0};
	level_14.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, a * 7}, 0};
	level_14.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, a * 8}, 0};
	level_14.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, a * 9}, 0};
	level_14.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, a * 10}, 0};
	level_14.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, a * 11}, 0};
	level_14.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, a * 12}, 0};
	level_14.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, a * 13}, 0};
	level_14.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, a * 14}, 0};
	level_14.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, a * 15}, 0};
	level_14.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, a * 16}, 0};
	level_14.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, a * 17}, 0};
	level_14.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, a * 18}, 0};
	level_14.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, a * 19}, 0};
	level_14.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, a * 20}, 0};
	level_14.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, a * 21}, 0};
	level_14.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, a * 22}, 0};
	level_14.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, a * 23}, 0};
	level_14.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, a * 24}, 0};
	level_14.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25, SDL_TRUE, {0, a * 25}, 0};
	level_14.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26, SDL_TRUE, {0, a * 26}, 0};
	level_14.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27, SDL_TRUE, {0, a * 27}, 0};
	level_14.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28, SDL_TRUE, {0, a * 28}, 0};
	level_14.waves[3].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29, SDL_TRUE, {0, a * 29}, 0};

	level_14.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 13, SDL_FALSE, NULL};
	level_14.waves[4].wave_array = SDL_malloc(sizeof(*(level_14.waves[4].wave_array)) * level_14.waves[4].size);

	t = 22;
	level_14.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_YELLOW, 0, 0 * t, SDL_TRUE,  {0, 193}, 0};
	level_14.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_YELLOW, 0, 1 * t, SDL_TRUE,  {0, 354}, 0};
	level_14.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_YELLOW, 0, 2 * t, SDL_TRUE,  {0, 270}, 0};
	level_14.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_YELLOW, 0, 3 * t, SDL_TRUE,  {0, 241}, 0};
	level_14.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_YELLOW, 0, 4 * t, SDL_TRUE,  {0, 77}, 0};
	level_14.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_YELLOW, 0, 5 * t, SDL_TRUE,  {0, 42}, 0};
	level_14.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_YELLOW, 0, 6 * t, SDL_TRUE,  {0, 221}, 0};
	level_14.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW, 0, 7 * t, SDL_TRUE,  {0, 321}, 0};
	level_14.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_YELLOW, 0, 8 * t, SDL_TRUE,  {0, 194}, 0};
	level_14.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_YELLOW, 0, 9 * t, SDL_TRUE,  {0, 270}, 0};
	level_14.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_YELLOW, 0, 10 * t, SDL_TRUE, {0, 360}, 0};
	level_14.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_YELLOW, 0, 11 * t, SDL_TRUE, {0, 209}, 0};
	level_14.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_YELLOW, 0, 12 * t, SDL_TRUE, {0, 311}, 0};

	return (level_14);
}