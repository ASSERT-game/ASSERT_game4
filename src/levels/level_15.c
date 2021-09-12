#include "main.h"
#include "entity.h"

t_wave_m	level_15(void)
{
	t_wave_m level_15 = {
		.wave_id = 14,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 4,

		.size = 5,
	};

	level_15.waves = SDL_malloc(sizeof(*(level_15.waves)) * level_15.size);

	level_15.waves[0] = (t_wave){0, WAVE_TICKS, 0, SDL_FALSE, SDL_TRUE, 26, SDL_FALSE, NULL};
	level_15.waves[0].wave_array = SDL_malloc(sizeof(*(level_15.waves[0].wave_array)) * level_15.waves[0].size);

	int t;

	t = 12;
	level_15.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0,	SDL_TRUE, {0, 334}, 0};
	level_15.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1,	SDL_TRUE, {0, 283}, 0};
	level_15.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 2,	SDL_TRUE, {0, 283}, 0};
	level_15.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3,	SDL_TRUE, {0, 85}, 0};
	level_15.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4,	SDL_TRUE, {0, 319}, 0};
	level_15.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5,	SDL_TRUE, {0, 327}, 0};
	level_15.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6,	SDL_TRUE, {0, 140}, 0};
	level_15.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_YELLOW, 0, t * 7,	SDL_TRUE, {0, 140}, 0};
	level_15.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8,	SDL_TRUE, {0, 250}, 0};
	level_15.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9,	SDL_TRUE, {0, 46}, 0};
	level_15.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10,	SDL_TRUE, {0, 201}, 0};
	level_15.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11,	SDL_TRUE, {0, 334}, 0};
	level_15.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 12,	SDL_TRUE, {0, 334}, 0};
	level_15.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13,	SDL_TRUE, {0, 308}, 0};
	level_15.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14,	SDL_TRUE, {0, 299}, 0};
	level_15.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15,	SDL_TRUE, {0, 72}, 0};
	level_15.waves[0].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16,	SDL_TRUE, {0, 201}, 0};
	level_15.waves[0].wave_array[17] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 17,	SDL_TRUE, {0, 201}, 0};
	level_15.waves[0].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18,	SDL_TRUE, {0, 80}, 0};
	level_15.waves[0].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19,	SDL_TRUE, {0, 247}, 0};
	level_15.waves[0].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20,	SDL_TRUE, {0, 237}, 0};
	level_15.waves[0].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21,	SDL_TRUE, {0, 150}, 0};
	level_15.waves[0].wave_array[22] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 22,	SDL_TRUE, {0, 150}, 0};
	level_15.waves[0].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23,	SDL_TRUE, {0, 79}, 0};
	level_15.waves[0].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24,	SDL_TRUE, {0, 18}, 0};
	level_15.waves[0].wave_array[25] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 25,	SDL_TRUE, {0, 18}, 0};

	level_15.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 60, SDL_FALSE, NULL};
	level_15.waves[1].wave_array = SDL_malloc(sizeof(*(level_15.waves[1].wave_array)) * level_15.waves[1].size);

	int	a = 360 / 15;
	level_15.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_15.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_15.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_15.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_15.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_15.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_15.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_15.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_15.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_15.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_15.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_15.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 11}, 0};
	level_15.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 12}, 0};
	level_15.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 13}, 0};
	level_15.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 14}, 0};

	level_15.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 0}, 0};
	level_15.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 1}, 0};
	level_15.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 2}, 0};
	level_15.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 3}, 0};
	level_15.waves[1].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 4}, 0};
	level_15.waves[1].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 5}, 0};
	level_15.waves[1].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 6}, 0};
	level_15.waves[1].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 7}, 0};
	level_15.waves[1].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 8}, 0};
	level_15.waves[1].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 9}, 0};
	level_15.waves[1].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 10}, 0};
	level_15.waves[1].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 11}, 0};
	level_15.waves[1].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 12}, 0};
	level_15.waves[1].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 13}, 0};
	level_15.waves[1].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, 260, SDL_TRUE, {0, a * 14}, 0};

	level_15.waves[1].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 0}, 0};
	level_15.waves[1].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 1}, 0};
	level_15.waves[1].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 2}, 0};
	level_15.waves[1].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 3}, 0};
	level_15.waves[1].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 4}, 0};
	level_15.waves[1].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 5}, 0};
	level_15.waves[1].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 6}, 0};
	level_15.waves[1].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 7}, 0};
	level_15.waves[1].wave_array[38] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 8}, 0};
	level_15.waves[1].wave_array[39] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 9}, 0};
	level_15.waves[1].wave_array[40] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 10}, 0};
	level_15.waves[1].wave_array[41] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 11}, 0};
	level_15.waves[1].wave_array[42] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 12}, 0};
	level_15.waves[1].wave_array[43] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 13}, 0};
	level_15.waves[1].wave_array[44] = (t_wave_elem){E_SLIME_BLUE, 0, 530, SDL_TRUE, {0, a * 14}, 0};

	level_15.waves[1].wave_array[45] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 0}, 0};
	level_15.waves[1].wave_array[46] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 1}, 0};
	level_15.waves[1].wave_array[47] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 2}, 0};
	level_15.waves[1].wave_array[48] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 3}, 0};
	level_15.waves[1].wave_array[49] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 4}, 0};
	level_15.waves[1].wave_array[50] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 5}, 0};
	level_15.waves[1].wave_array[51] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 6}, 0};
	level_15.waves[1].wave_array[52] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 7}, 0};
	level_15.waves[1].wave_array[53] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 8}, 0};
	level_15.waves[1].wave_array[54] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 9}, 0};
	level_15.waves[1].wave_array[55] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 10}, 0};
	level_15.waves[1].wave_array[56] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 11}, 0};
	level_15.waves[1].wave_array[57] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 12}, 0};
	level_15.waves[1].wave_array[58] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 13}, 0};
	level_15.waves[1].wave_array[59] = (t_wave_elem){E_SLIME_BLUE, 0, 790, SDL_TRUE, {0, a * 14}, 0};

	level_15.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 1, SDL_FALSE, SDL_FALSE, 63, SDL_FALSE, NULL};
	level_15.waves[2].wave_array = SDL_malloc(sizeof(*(level_15.waves[2].wave_array)) * level_15.waves[2].size);

	t = 12;
	level_15.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 0, SDL_TRUE,  {0, 175}, 0};
	level_15.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 1, SDL_TRUE,  {0, 235}, 0};
	level_15.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 2, SDL_TRUE,  {0, 248}, 0};
	level_15.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 3, SDL_TRUE,  {0, 296}, 0};
	level_15.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 4, SDL_TRUE,  {0, 35}, 0};
	level_15.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 5, SDL_TRUE,  {0, 278}, 0};
	level_15.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 6, SDL_TRUE,  {0, 338}, 0};
	level_15.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 7, SDL_TRUE,  {0, 306}, 0};
	level_15.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 8, SDL_TRUE,  {0, 139}, 0};
	level_15.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 9, SDL_TRUE,  {0, 274}, 0};
	level_15.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 10, SDL_TRUE, {0, 125}, 0};
	level_15.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 11, SDL_TRUE, {0, 36}, 0};
	level_15.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 12, SDL_TRUE, {0, 194}, 0};
	level_15.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 13, SDL_TRUE, {0, 176}, 0};
	level_15.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 14, SDL_TRUE, {0, 175}, 0};
	level_15.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 15, SDL_TRUE, {0, 167}, 0};
	level_15.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 16, SDL_TRUE, {0, 344}, 0};
	level_15.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 17, SDL_TRUE, {0, 164}, 0};
	level_15.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 18, SDL_TRUE, {0, 282}, 0};
	level_15.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 19, SDL_TRUE, {0, 342}, 0};
	level_15.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 20, SDL_TRUE, {0, 145}, 0};
	level_15.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 21, SDL_TRUE, {0, 342}, 0};
	level_15.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 22, SDL_TRUE, {0, 225}, 0};
	level_15.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 23, SDL_TRUE, {0, 214}, 0};
	level_15.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 24, SDL_TRUE, {0, 358}, 0};
	level_15.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 25, SDL_TRUE, {0, 83}, 0};
	level_15.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 26, SDL_TRUE, {0, 211}, 0};
	level_15.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 27, SDL_TRUE, {0, 302}, 0};
	level_15.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 28, SDL_TRUE, {0, 320}, 0};
	level_15.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 29, SDL_TRUE, {0, 62}, 0};
	level_15.waves[2].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 30, SDL_TRUE, {0, 298}, 0};
	level_15.waves[2].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 31, SDL_TRUE, {0, 141}, 0};
	level_15.waves[2].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 32, SDL_TRUE, {0, 274}, 0};
	level_15.waves[2].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 33, SDL_TRUE, {0, 27}, 0};
	level_15.waves[2].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 34, SDL_TRUE, {0, 243}, 0};
	level_15.waves[2].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 35, SDL_TRUE, {0, 288}, 0};
	level_15.waves[2].wave_array[36] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 36, SDL_TRUE, {0, 151}, 0};
	level_15.waves[2].wave_array[37] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 37, SDL_TRUE, {0, 105}, 0};
	level_15.waves[2].wave_array[38] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 38, SDL_TRUE, {0, 272}, 0};
	level_15.waves[2].wave_array[39] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 39, SDL_TRUE, {0, 147}, 0};
	level_15.waves[2].wave_array[40] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 40, SDL_TRUE, {0, 85}, 0};
	level_15.waves[2].wave_array[41] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 41, SDL_TRUE, {0, 27}, 0};
	level_15.waves[2].wave_array[42] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 42, SDL_TRUE, {0, 282}, 0};
	level_15.waves[2].wave_array[43] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 43, SDL_TRUE, {0, 3}, 0};
	level_15.waves[2].wave_array[44] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 44, SDL_TRUE, {0, 334}, 0};
	level_15.waves[2].wave_array[45] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 45, SDL_TRUE, {0, 350}, 0};
	level_15.waves[2].wave_array[46] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 46, SDL_TRUE, {0, 44}, 0};
	level_15.waves[2].wave_array[47] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 47, SDL_TRUE, {0, 220}, 0};
	level_15.waves[2].wave_array[48] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 48, SDL_TRUE, {0, 180}, 0};
	level_15.waves[2].wave_array[49] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 49, SDL_TRUE, {0, 103}, 0};
	level_15.waves[2].wave_array[50] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 50, SDL_TRUE, {0, 34}, 0};
	level_15.waves[2].wave_array[51] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 51, SDL_TRUE, {0, 308}, 0};
	level_15.waves[2].wave_array[52] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 52, SDL_TRUE, {0, 270}, 0};
	level_15.waves[2].wave_array[53] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 53, SDL_TRUE, {0, 11}, 0};
	level_15.waves[2].wave_array[54] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 54, SDL_TRUE, {0, 269}, 0};
	level_15.waves[2].wave_array[55] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 55, SDL_TRUE, {0, 352}, 0};
	level_15.waves[2].wave_array[56] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 56, SDL_TRUE, {0, 313}, 0};
	level_15.waves[2].wave_array[57] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 57, SDL_TRUE, {0, 27}, 0};
	level_15.waves[2].wave_array[58] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 58, SDL_TRUE, {0, 183}, 0};
	level_15.waves[2].wave_array[59] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 59, SDL_TRUE, {0, 173}, 0};
	level_15.waves[2].wave_array[60] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 60, SDL_TRUE, {0, 328}, 0};
	level_15.waves[2].wave_array[61] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 61, SDL_TRUE, {0, 223}, 0};
	level_15.waves[2].wave_array[62] = (t_wave_elem){E_SLIME_BLUE, 0, 20 + t * 62, SDL_TRUE, {0, 84}, 0};

	level_15.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 2, SDL_FALSE, SDL_FALSE, 16, SDL_FALSE, NULL};
	level_15.waves[3].wave_array = SDL_malloc(sizeof(*(level_15.waves[3].wave_array)) * level_15.waves[3].size);

	level_15.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN, 0, 100 +  0, SDL_TRUE, {0, 18}, 0};
	level_15.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN, 0, 100 + 10, SDL_TRUE, {0, 18}, 0};
	level_15.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN, 0, 100 + 20, SDL_TRUE, {0, 18}, 0};
	level_15.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN, 0, 100 + 30, SDL_TRUE, {0, 18}, 0};
	level_15.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN, 0, 200 +  0, SDL_TRUE, {0, 4}, 0};
	level_15.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN, 0, 200 + 10, SDL_TRUE, {0, 4}, 0};
	level_15.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN, 0, 200 + 20, SDL_TRUE, {0, 4}, 0};
	level_15.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN, 0, 200 + 30, SDL_TRUE, {0, 4}, 0};
	level_15.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN, 0, 300 +  0, SDL_TRUE, {0, 329}, 0};
	level_15.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN, 0, 300 + 10, SDL_TRUE, {0, 329}, 0};
	level_15.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_CYAN, 0, 300 + 20, SDL_TRUE, {0, 329}, 0};
	level_15.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_CYAN, 0, 300 + 30, SDL_TRUE, {0, 329}, 0};
	level_15.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_CYAN, 0, 400 +  0, SDL_TRUE, {0, 174}, 0};
	level_15.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_CYAN, 0, 400 + 10, SDL_TRUE, {0, 174}, 0};
	level_15.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_CYAN, 0, 400 + 20, SDL_TRUE, {0, 174}, 0};
	level_15.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_CYAN, 0, 400 + 30, SDL_TRUE, {0, 174}, 0};

	level_15.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 2, SDL_FALSE, SDL_FALSE, 2, SDL_FALSE, NULL};
	level_15.waves[4].wave_array = SDL_malloc(sizeof(*(level_15.waves[4].wave_array)) * level_15.waves[4].size);

	level_15.waves[4].wave_array[0] = (t_wave_elem){E_SLIME_SPINY, 0, 0, SDL_TRUE, {0, 90}, 0};
	level_15.waves[4].wave_array[1] = (t_wave_elem){E_SLIME_SPINY, 0, 0, SDL_TRUE, {0, 270}, 0};


	return level_15;
}