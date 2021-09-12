#include "main.h"
#include "entity.h"

t_wave_m	level_12(void)
{
	t_wave_m level_12 = {
		.wave_id = 11,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 0,
		.win_wave = 3,

		.size = 4,
	};

	level_12.waves = SDL_malloc(sizeof(*(level_12.waves)) * level_12.size);

	level_12.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 12, SDL_FALSE, NULL};
	level_12.waves[0].wave_array = SDL_malloc(sizeof(*(level_12.waves[0].wave_array)) * level_12.waves[0].size);

	int a = 36;
	level_12.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_12.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_12.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_12.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_12.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_12.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_12.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_12.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_12.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_12.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_12.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_12.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 11}, 0};

	level_12.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 56, SDL_FALSE, NULL};
	level_12.waves[1].wave_array = SDL_malloc(sizeof(*(level_12.waves[1].wave_array)) * level_12.waves[1].size);

	int t = 12;
	level_12.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 231}, 0};
	level_12.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 39}, 0};
	level_12.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 53}, 0};
	level_12.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 283}, 0};
	level_12.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 156}, 0};
	level_12.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 226}, 0};
	level_12.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 122}, 0};
	level_12.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 304}, 0};
	level_12.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 200}, 0};
	level_12.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 264}, 0};
	level_12.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, t * 10, SDL_TRUE, {0, 165}, 0};
	level_12.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, t * 11, SDL_TRUE, {0, 177}, 0};
	level_12.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE, 0, t * 12, SDL_TRUE, {0, 159}, 0};
	level_12.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE, 0, t * 13, SDL_TRUE, {0, 212}, 0};
	level_12.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE, 0, t * 14, SDL_TRUE, {0, 287}, 0};
	level_12.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE, 0, t * 15, SDL_TRUE, {0, 345}, 0};
	level_12.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_BLUE, 0, t * 16, SDL_TRUE, {0, 343}, 0};
	level_12.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_BLUE, 0, t * 17, SDL_TRUE, {0, 162}, 0};
	level_12.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_BLUE, 0, t * 18, SDL_TRUE, {0, 355}, 0};
	level_12.waves[1].wave_array[19] = (t_wave_elem){E_SLIME_BLUE, 0, t * 19, SDL_TRUE, {0, 214}, 0};
	level_12.waves[1].wave_array[20] = (t_wave_elem){E_SLIME_BLUE, 0, t * 20, SDL_TRUE, {0, 297}, 0};
	level_12.waves[1].wave_array[21] = (t_wave_elem){E_SLIME_BLUE, 0, t * 21, SDL_TRUE, {0, 60}, 0};
	level_12.waves[1].wave_array[22] = (t_wave_elem){E_SLIME_BLUE, 0, t * 22, SDL_TRUE, {0, 15}, 0};
	level_12.waves[1].wave_array[23] = (t_wave_elem){E_SLIME_BLUE, 0, t * 23, SDL_TRUE, {0, 141}, 0};
	level_12.waves[1].wave_array[24] = (t_wave_elem){E_SLIME_BLUE, 0, t * 24, SDL_TRUE, {0, 209}, 0};
	level_12.waves[1].wave_array[25] = (t_wave_elem){E_SLIME_BLUE, 0, t * 25, SDL_TRUE, {0, 257}, 0};
	level_12.waves[1].wave_array[26] = (t_wave_elem){E_SLIME_BLUE, 0, t * 26, SDL_TRUE, {0, 150}, 0};
	level_12.waves[1].wave_array[27] = (t_wave_elem){E_SLIME_BLUE, 0, t * 27, SDL_TRUE, {0, 321}, 0};
	level_12.waves[1].wave_array[28] = (t_wave_elem){E_SLIME_BLUE, 0, t * 28, SDL_TRUE, {0, 216}, 0};
	level_12.waves[1].wave_array[29] = (t_wave_elem){E_SLIME_BLUE, 0, t * 29, SDL_TRUE, {0, 236}, 0};
	level_12.waves[1].wave_array[30] = (t_wave_elem){E_SLIME_BLUE, 0, t * 30, SDL_TRUE, {0, 206}, 0};
	level_12.waves[1].wave_array[31] = (t_wave_elem){E_SLIME_BLUE, 0, t * 31, SDL_TRUE, {0, 208}, 0};
	level_12.waves[1].wave_array[32] = (t_wave_elem){E_SLIME_BLUE, 0, t * 32, SDL_TRUE, {0, 18}, 0};
	level_12.waves[1].wave_array[33] = (t_wave_elem){E_SLIME_BLUE, 0, t * 33, SDL_TRUE, {0, 348}, 0};
	level_12.waves[1].wave_array[34] = (t_wave_elem){E_SLIME_BLUE, 0, t * 34, SDL_TRUE, {0, 132}, 0};
	level_12.waves[1].wave_array[35] = (t_wave_elem){E_SLIME_BLUE, 0, t * 35, SDL_TRUE, {0, 189}, 0};

	level_12.waves[1].wave_array[36] = (t_wave_elem){E_SLIME_CYAN, 0, 10 + 0, SDL_TRUE,  {0, 90}, 0};
	level_12.waves[1].wave_array[37] = (t_wave_elem){E_SLIME_CYAN, 0, 10 + 15, SDL_TRUE, {0, 90}, 0};
	level_12.waves[1].wave_array[38] = (t_wave_elem){E_SLIME_CYAN, 0, 10 + 30, SDL_TRUE, {0, 90}, 0};
	level_12.waves[1].wave_array[39] = (t_wave_elem){E_SLIME_CYAN, 0, 10 + 45, SDL_TRUE, {0, 90}, 0};

	level_12.waves[1].wave_array[40] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 0, SDL_TRUE,  {0, 323}, 0};
	level_12.waves[1].wave_array[41] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 15, SDL_TRUE, {0, 323}, 0};
	level_12.waves[1].wave_array[42] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 30, SDL_TRUE, {0, 323}, 0};
	level_12.waves[1].wave_array[43] = (t_wave_elem){E_SLIME_CYAN, 0, 50 + 45, SDL_TRUE, {0, 323}, 0};

	level_12.waves[1].wave_array[44] = (t_wave_elem){E_SLIME_CYAN, 0, 70 + 0, SDL_TRUE,  {0, 176}, 0};
	level_12.waves[1].wave_array[45] = (t_wave_elem){E_SLIME_CYAN, 0, 70 + 15, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[46] = (t_wave_elem){E_SLIME_CYAN, 0, 70 + 30, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[47] = (t_wave_elem){E_SLIME_CYAN, 0, 70 + 45, SDL_TRUE, {0, 176}, 0};

	level_12.waves[1].wave_array[48] = (t_wave_elem){E_SLIME_CYAN, 0, 220 + 0, SDL_TRUE,  {0, 176}, 0};
	level_12.waves[1].wave_array[49] = (t_wave_elem){E_SLIME_CYAN, 0, 220 + 15, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[50] = (t_wave_elem){E_SLIME_CYAN, 0, 220 + 30, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[51] = (t_wave_elem){E_SLIME_CYAN, 0, 220 + 45, SDL_TRUE, {0, 176}, 0};

	level_12.waves[1].wave_array[52] = (t_wave_elem){E_SLIME_CYAN, 0, 360 + 0, SDL_TRUE,  {0, 176}, 0};
	level_12.waves[1].wave_array[53] = (t_wave_elem){E_SLIME_CYAN, 0, 360 + 15, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[54] = (t_wave_elem){E_SLIME_CYAN, 0, 360 + 30, SDL_TRUE, {0, 176}, 0};
	level_12.waves[1].wave_array[55] = (t_wave_elem){E_SLIME_CYAN, 0, 360 + 45, SDL_TRUE, {0, 176}, 0};

	level_12.waves[2] = (t_wave){0, WAVE_TICKS, t * 15, SDL_FALSE, SDL_FALSE, 12, SDL_FALSE, NULL};
	level_12.waves[2].wave_array = SDL_malloc(sizeof(*(level_12.waves[2].wave_array)) * level_12.waves[2].size);

	level_12.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 0}, 0};
	level_12.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 1}, 0};
	level_12.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 2}, 0};
	level_12.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 3}, 0};
	level_12.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 4}, 0};
	level_12.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 5}, 0};
	level_12.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 6}, 0};
	level_12.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 7}, 0};
	level_12.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 8}, 0};
	level_12.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 9}, 0};
	level_12.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_12.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, a * 11}, 0};

	level_12.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 1, SDL_FALSE, SDL_FALSE, 20, SDL_FALSE, NULL};
	level_12.waves[3].wave_array = SDL_malloc(sizeof(*(level_12.waves[3].wave_array)) * level_12.waves[3].size);

	level_12.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,		0, 0, SDL_TRUE, {0, 356}, 0};
	level_12.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,		0, 50, SDL_TRUE, {0, 71}, 0};
	level_12.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_YELLOW,	0, 100, SDL_TRUE, {0, 236}, 0};
	level_12.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,		0, 140, SDL_TRUE, {0, 39}, 0};
	level_12.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,		0, 180, SDL_TRUE, {0, 47}, 0};
	level_12.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_YELLOW,	0, 220, SDL_TRUE, {0, 145}, 0};
	level_12.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,		0, 250, SDL_TRUE, {0, 136}, 0};
	level_12.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,		0, 280, SDL_TRUE, {0, 325}, 0};
	level_12.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_YELLOW,	0, 310, SDL_TRUE, {0, 43}, 0};
	level_12.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,		0, 345, SDL_TRUE, {0, 69}, 0};
	level_12.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,		0, 360, SDL_TRUE, {0, 127}, 0};
	level_12.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_YELLOW,	0, 375, SDL_TRUE, {0, 129}, 0};
	level_12.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,		0, 387, SDL_TRUE, {0, 312}, 0};
	level_12.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,		0, 399, SDL_TRUE, {0, 170}, 0};
	level_12.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_YELLOW,	0, 409, SDL_TRUE, {0, 19}, 0};
	level_12.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,		0, 419, SDL_TRUE, {0, 234}, 0};
	level_12.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,		0, 429, SDL_TRUE, {0, 224}, 0};
	level_12.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_YELLOW,	0, 437, SDL_TRUE, {0, 340}, 0};
	level_12.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,		0, 445, SDL_TRUE, {0, 213}, 0};
	level_12.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,		0, 453, SDL_TRUE, {0, 79}, 0};

	return (level_12);
}