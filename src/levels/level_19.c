#include "main.h"
#include "entity.h"

t_wave_m	level_19(void)
{
	t_wave_m level_19 = {
		.wave_id = 18,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 6,
		.win_wave = 0,

		.size = 6,
	};

	level_19.waves = SDL_malloc(sizeof(*(level_19.waves)) * level_19.size);

	level_19.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 70, SDL_FALSE, NULL};
	level_19.waves[0].wave_array = SDL_malloc(sizeof(*(level_19.waves[0].wave_array)) * level_19.waves[0].size);

	int	a = 360 / 5;
	int	t = 45;
	level_19.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 0 + 0 * a}, 0};
	level_19.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 0 + 1 * a}, 0};
	level_19.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 0 + 2 * a}, 0};
	level_19.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 0 + 3 * a}, 0};
	level_19.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 0 + 4 * a}, 0};
	level_19.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 10 + 0 * a}, 0};
	level_19.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 10 + 1 * a}, 0};
	level_19.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 10 + 2 * a}, 0};
	level_19.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 10 + 3 * a}, 0};
	level_19.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 10 + 4 * a}, 0};
	level_19.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 20 + 0 * a}, 0};
	level_19.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 20 + 1 * a}, 0};
	level_19.waves[0].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 20 + 2 * a}, 0};
	level_19.waves[0].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 20 + 3 * a}, 0};
	level_19.waves[0].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 20 + 4 * a}, 0};
	level_19.waves[0].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 30 + 0 * a}, 0};
	level_19.waves[0].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 30 + 1 * a}, 0};
	level_19.waves[0].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 30 + 2 * a}, 0};
	level_19.waves[0].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 30 + 3 * a}, 0};
	level_19.waves[0].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 30 + 4 * a}, 0};
	level_19.waves[0].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 40 + 0 * a}, 0};
	level_19.waves[0].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 40 + 1 * a}, 0};
	level_19.waves[0].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 40 + 2 * a}, 0};
	level_19.waves[0].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 40 + 3 * a}, 0};
	level_19.waves[0].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 40 + 4 * a}, 0};
	level_19.waves[0].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 50 + 0 * a}, 0};
	level_19.waves[0].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 50 + 1 * a}, 0};
	level_19.waves[0].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 50 + 2 * a}, 0};
	level_19.waves[0].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 50 + 3 * a}, 0};
	level_19.waves[0].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 50 + 4 * a}, 0};
	level_19.waves[0].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 60 + 0 * a}, 0};
	level_19.waves[0].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 60 + 1 * a}, 0};
	level_19.waves[0].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 60 + 2 * a}, 0};
	level_19.waves[0].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 60 + 3 * a}, 0};
	level_19.waves[0].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 60 + 4 * a}, 0};
	level_19.waves[0].wave_array[35] = (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 70 + 0 * a}, 0};
	level_19.waves[0].wave_array[36] = (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 70 + 1 * a}, 0};
	level_19.waves[0].wave_array[37] = (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 70 + 2 * a}, 0};
	level_19.waves[0].wave_array[38] = (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 70 + 3 * a}, 0};
	level_19.waves[0].wave_array[39] = (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 70 + 4 * a}, 0};
	level_19.waves[0].wave_array[40] = (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 80 + 0 * a}, 0};
	level_19.waves[0].wave_array[41] = (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 80 + 1 * a}, 0};
	level_19.waves[0].wave_array[42] = (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 80 + 2 * a}, 0};
	level_19.waves[0].wave_array[43] = (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 80 + 3 * a}, 0};
	level_19.waves[0].wave_array[44] = (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 80 + 4 * a}, 0};
	level_19.waves[0].wave_array[45] = (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 90 + 0 * a}, 0};
	level_19.waves[0].wave_array[46] = (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 90 + 1 * a}, 0};
	level_19.waves[0].wave_array[47] = (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 90 + 2 * a}, 0};
	level_19.waves[0].wave_array[48] = (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 90 + 3 * a}, 0};
	level_19.waves[0].wave_array[49] = (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 90 + 4 * a}, 0};
	level_19.waves[0].wave_array[50] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 100 + 0 * a}, 0};
	level_19.waves[0].wave_array[51] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 100 + 1 * a}, 0};
	level_19.waves[0].wave_array[52] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 100 + 2 * a}, 0};
	level_19.waves[0].wave_array[53] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 100 + 3 * a}, 0};
	level_19.waves[0].wave_array[54] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 100 + 4 * a}, 0};
	level_19.waves[0].wave_array[55] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 110 + 0 * a}, 0};
	level_19.waves[0].wave_array[56] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 110 + 1 * a}, 0};
	level_19.waves[0].wave_array[57] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 110 + 2 * a}, 0};
	level_19.waves[0].wave_array[58] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 110 + 3 * a}, 0};
	level_19.waves[0].wave_array[59] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 110 + 4 * a}, 0};
	level_19.waves[0].wave_array[60] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 120 + 0 * a}, 0};
	level_19.waves[0].wave_array[61] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 120 + 1 * a}, 0};
	level_19.waves[0].wave_array[62] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 120 + 2 * a}, 0};
	level_19.waves[0].wave_array[63] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 120 + 3 * a}, 0};
	level_19.waves[0].wave_array[64] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 120 + 4 * a}, 0};
	level_19.waves[0].wave_array[65] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 130 + 0 * a}, 0};
	level_19.waves[0].wave_array[66] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 130 + 1 * a}, 0};
	level_19.waves[0].wave_array[67] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 130 + 2 * a}, 0};
	level_19.waves[0].wave_array[68] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 130 + 3 * a}, 0};
	level_19.waves[0].wave_array[69] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 130 + 4 * a}, 0};

	level_19.waves[1] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 10, SDL_FALSE, NULL};
	level_19.waves[1].wave_array = SDL_malloc(sizeof(*(level_19.waves[1].wave_array)) * level_19.waves[1].size);

	t = 18;
	level_19.waves[1].wave_array[0] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 0, SDL_TRUE, {0, 275}, 0};
	level_19.waves[1].wave_array[1] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 1, SDL_TRUE, {0, 20}, 0};
	level_19.waves[1].wave_array[2] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 2, SDL_TRUE, {0, 176}, 0};
	level_19.waves[1].wave_array[3] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 3, SDL_TRUE, {0, 283}, 0};
	level_19.waves[1].wave_array[4] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 4, SDL_TRUE, {0, 183}, 0};
	level_19.waves[1].wave_array[5] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 5, SDL_TRUE, {0, 121}, 0};
	level_19.waves[1].wave_array[6] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 6, SDL_TRUE, {0, 220}, 0};
	level_19.waves[1].wave_array[7] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 7, SDL_TRUE, {0, 27}, 0};
	level_19.waves[1].wave_array[8] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 8, SDL_TRUE, {0, 301}, 0};
	level_19.waves[1].wave_array[9] = (t_wave_elem){E_SLIME_YELLOW, 0, t * 9, SDL_TRUE, {0, 11}, 0};

	level_19.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 34, SDL_FALSE, NULL};
	level_19.waves[2].wave_array = SDL_malloc(sizeof(*(level_19.waves[2].wave_array)) * level_19.waves[2].size);

	level_19.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 22}, 0};
	level_19.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 285}, 0};
	level_19.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 50}, 0};
	level_19.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_INV,  0, t * 3, SDL_TRUE, {0, 111}, 0};
	level_19.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 225}, 0};
	level_19.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 5, SDL_TRUE, {0, 313}, 0};
	level_19.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 290}, 0};
	level_19.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_INV,  0, t * 7, SDL_TRUE, {0, 192}, 0};
	level_19.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 318}, 0};
	level_19.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_INV,  0, t * 9, SDL_TRUE, {0, 99}, 0};
	level_19.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, t * 10, SDL_TRUE, {0, 166}, 0};
	level_19.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_INV,  0, t * 11, SDL_TRUE, {0, 122}, 0};
	level_19.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 147}, 0};
	level_19.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 268}, 0};
	level_19.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, 337}, 0};
	level_19.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, t * 15, SDL_TRUE, {0, 66}, 0};
	level_19.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_INV,  0, t * 16, SDL_TRUE, {0, 149}, 0};
	level_19.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 17, SDL_TRUE, {0, 224}, 0};
	level_19.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 18, SDL_TRUE, {0, 350}, 0};
	level_19.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, t * 19, SDL_TRUE, {0, 12}, 0};
	level_19.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, t * 20, SDL_TRUE, {0, 112}, 0};
	level_19.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, t * 21, SDL_TRUE, {0, 82}, 0};
	level_19.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, t * 22, SDL_TRUE, {0, 65}, 0};
	level_19.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, t * 23, SDL_TRUE, {0, 167}, 0};
	level_19.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, t * 24, SDL_TRUE, {0, 260}, 0};
	level_19.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, t * 25, SDL_TRUE, {0, 40}, 0};
	level_19.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, t * 26, SDL_TRUE, {0, 149}, 0};
	level_19.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_INV,  0, t * 27, SDL_TRUE, {0, 151}, 0};
	level_19.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, t * 28, SDL_TRUE, {0, 318}, 0};
	level_19.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, t * 29, SDL_TRUE, {0, 297}, 0};
	level_19.waves[2].wave_array[30] = (t_wave_elem){E_SLIME_INV,  0, t * 30, SDL_TRUE, {0, 273}, 0};
	level_19.waves[2].wave_array[31] = (t_wave_elem){E_SLIME_INV,  0, t * 31, SDL_TRUE, {0, 255}, 0};
	level_19.waves[2].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, t * 32, SDL_TRUE, {0, 60}, 0};
	level_19.waves[2].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, t * 33, SDL_TRUE, {0, 325}, 0};

	level_19.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 10, SDL_FALSE, NULL};
	level_19.waves[3].wave_array = SDL_malloc(sizeof(*(level_19.waves[3].wave_array)) * level_19.waves[3].size);

	level_19.waves[3].wave_array[0] = (t_wave_elem){E_SLIME_BLUE, 0, t * 0, SDL_TRUE, {0, 174}, 0};
	level_19.waves[3].wave_array[1] = (t_wave_elem){E_SLIME_BLUE, 0, t * 1, SDL_TRUE, {0, 182}, 0};
	level_19.waves[3].wave_array[2] = (t_wave_elem){E_SLIME_BLUE, 0, t * 2, SDL_TRUE, {0, 212}, 0};
	level_19.waves[3].wave_array[3] = (t_wave_elem){E_SLIME_BLUE, 0, t * 3, SDL_TRUE, {0, 274}, 0};
	level_19.waves[3].wave_array[4] = (t_wave_elem){E_SLIME_BLUE, 0, t * 4, SDL_TRUE, {0, 149}, 0};
	level_19.waves[3].wave_array[5] = (t_wave_elem){E_SLIME_BLUE, 0, t * 5, SDL_TRUE, {0, 55}, 0};
	level_19.waves[3].wave_array[6] = (t_wave_elem){E_SLIME_BLUE, 0, t * 6, SDL_TRUE, {0, 247}, 0};
	level_19.waves[3].wave_array[7] = (t_wave_elem){E_SLIME_BLUE, 0, t * 7, SDL_TRUE, {0, 67}, 0};
	level_19.waves[3].wave_array[8] = (t_wave_elem){E_SLIME_BLUE, 0, t * 8, SDL_TRUE, {0, 114}, 0};
	level_19.waves[3].wave_array[9] = (t_wave_elem){E_SLIME_BLUE, 0, t * 9, SDL_TRUE, {0, 150}, 0};

	level_19.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 6, SDL_FALSE, NULL};
	level_19.waves[4].wave_array = SDL_malloc(sizeof(*(level_19.waves[4].wave_array)) * level_19.waves[4].size);

	a = 360 / 5;
	level_19.waves[4].wave_array[0] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 0 * a}, 0};
	level_19.waves[4].wave_array[1] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 1 * a}, 0};
	level_19.waves[4].wave_array[2] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 2 * a}, 0};
	level_19.waves[4].wave_array[3] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 3 * a}, 0};
	level_19.waves[4].wave_array[4] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 4 * a}, 0};
	level_19.waves[4].wave_array[5] = (t_wave_elem){E_SLIME_BLUE, 0, 0, SDL_TRUE, {0, 5 * a}, 0};

	level_19.waves[5] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 41, SDL_FALSE, NULL};
	level_19.waves[5].wave_array = SDL_malloc(sizeof(*(level_19.waves[5].wave_array)) * level_19.waves[5].size);

	level_19.waves[5].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,	0, 0 * t, SDL_TRUE, {0, 116}, 0};
	level_19.waves[5].wave_array[1] =  (t_wave_elem){E_SLIME_SPINY,	0, 1 * t, SDL_TRUE, {0, 165}, 0};
	level_19.waves[5].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,	0, 2 * t, SDL_TRUE, {0, 147}, 0};
	level_19.waves[5].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,	0, 3 * t, SDL_TRUE, {0, 310}, 0};
	level_19.waves[5].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,	0, 4 * t, SDL_TRUE, {0, 173}, 0};
	level_19.waves[5].wave_array[5] =  (t_wave_elem){E_SLIME_SPINY,	0, 5 * t, SDL_TRUE, {0, 357}, 0};
	level_19.waves[5].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,	0, 6 * t, SDL_TRUE, {0, 323}, 0};
	level_19.waves[5].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,	0, 7 * t, SDL_TRUE, {0, 343}, 0};
	level_19.waves[5].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,	0, 8 * t, SDL_TRUE, {0, 97}, 0};
	level_19.waves[5].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,	0, 9 * t, SDL_TRUE, {0, 111}, 0};
	level_19.waves[5].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,	0, 10 * t, SDL_TRUE, {0, 212}, 0};
	level_19.waves[5].wave_array[11] = (t_wave_elem){E_SLIME_SPINY,	0, 11 * t, SDL_TRUE, {0, 132}, 0};
	level_19.waves[5].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,	0, 12 * t, SDL_TRUE, {0, 138}, 0};
	level_19.waves[5].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,	0, 13 * t, SDL_TRUE, {0, 192}, 0};
	level_19.waves[5].wave_array[14] = (t_wave_elem){E_SLIME_SPINY,	0, 14 * t, SDL_TRUE, {0, 202}, 0};
	level_19.waves[5].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,	0, 15 * t, SDL_TRUE, {0, 119}, 0};
	level_19.waves[5].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,	0, 16 * t, SDL_TRUE, {0, 225}, 0};
	level_19.waves[5].wave_array[17] = (t_wave_elem){E_SLIME_SPINY,	0, 17 * t, SDL_TRUE, {0, 202}, 0};
	level_19.waves[5].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,	0, 18 * t, SDL_TRUE, {0, 164}, 0};
	level_19.waves[5].wave_array[19] = (t_wave_elem){E_SLIME_SPINY,	0, 19 * t, SDL_TRUE, {0, 310}, 0};
	level_19.waves[5].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,	0, 20 * t, SDL_TRUE, {0, 101}, 0};
	level_19.waves[5].wave_array[21] = (t_wave_elem){E_SLIME_SPINY,	0, 21 * t, SDL_TRUE, {0, 69}, 0};
	level_19.waves[5].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,	0, 22 * t, SDL_TRUE, {0, 38}, 0};
	level_19.waves[5].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,	0, 23 * t, SDL_TRUE, {0, 298}, 0};
	level_19.waves[5].wave_array[24] = (t_wave_elem){E_SLIME_SPINY,	0, 24 * t, SDL_TRUE, {0, 332}, 0};
	level_19.waves[5].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,	0, 25 * t, SDL_TRUE, {0, 158}, 0};
	level_19.waves[5].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,	0, 26 * t, SDL_TRUE, {0, 210}, 0};
	level_19.waves[5].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,	0, 27 * t, SDL_TRUE, {0, 255}, 0};
	level_19.waves[5].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,	0, 28 * t, SDL_TRUE, {0, 281}, 0};
	level_19.waves[5].wave_array[29] = (t_wave_elem){E_SLIME_SPINY,	0, 29 * t, SDL_TRUE, {0, 227}, 0};
	level_19.waves[5].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,	0, 30 * t, SDL_TRUE, {0, 30}, 0};
	level_19.waves[5].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,	0, 31 * t, SDL_TRUE, {0, 350}, 0};
	level_19.waves[5].wave_array[32] = (t_wave_elem){E_SLIME_SPINY,	0, 32 * t, SDL_TRUE, {0, 109}, 0};
	level_19.waves[5].wave_array[33] = (t_wave_elem){E_SLIME_SPINY,	0, 33 * t, SDL_TRUE, {0, 120}, 0};
	level_19.waves[5].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,	0, 34 * t, SDL_TRUE, {0, 221}, 0};
	level_19.waves[5].wave_array[35] = (t_wave_elem){E_SLIME_BLUE,	0, 35 * t, SDL_TRUE, {0, 281}, 0};
	level_19.waves[5].wave_array[36] = (t_wave_elem){E_SLIME_BLUE,	0, 36 * t, SDL_TRUE, {0, 193}, 0};
	level_19.waves[5].wave_array[37] = (t_wave_elem){E_SLIME_SPINY,	0, 37 * t, SDL_TRUE, {0, 261}, 0};
	level_19.waves[5].wave_array[38] = (t_wave_elem){E_SLIME_SPINY,	0, 38 * t, SDL_TRUE, {0, 315}, 0};
	level_19.waves[5].wave_array[39] = (t_wave_elem){E_SLIME_BLUE,	0, 39 * t, SDL_TRUE, {0, 280}, 0};
	level_19.waves[5].wave_array[40] = (t_wave_elem){E_SLIME_BLUE,	0, 40 * t, SDL_TRUE, {0, 345}, 0};

	return (level_19);
}
