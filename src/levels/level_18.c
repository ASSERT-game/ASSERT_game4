#include "main.h"
#include "entity.h"

t_wave_m	level_18(void)
{
	t_wave_m level_18 = {
		.wave_id = 17,
		.tick = 0,
		.completed_no = 0,

		.win_kill_count = 0,
		.win_wave_no = 5,
		.win_wave = 0,

		.size = 5,
	};

	level_18.waves = SDL_malloc(sizeof(*(level_18.waves)) * level_18.size);

	level_18.waves[0] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_TRUE, 12, SDL_FALSE, NULL};
	level_18.waves[0].wave_array = SDL_malloc(sizeof(*(level_18.waves[0].wave_array)) * level_18.waves[0].size);

	int	a = 360 / 12;
	level_18.waves[0].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 0 * a}, 0};
	level_18.waves[0].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 1 * a}, 0};
	level_18.waves[0].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 2 * a}, 0};
	level_18.waves[0].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 3 * a}, 0};
	level_18.waves[0].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 4 * a}, 0};
	level_18.waves[0].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 5 * a}, 0};
	level_18.waves[0].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 6 * a}, 0};
	level_18.waves[0].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 7 * a}, 0};
	level_18.waves[0].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 8 * a}, 0};
	level_18.waves[0].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 9 * a}, 0};
	level_18.waves[0].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 10 * a}, 0};
	level_18.waves[0].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, 0, SDL_TRUE, {0, 11 * a}, 0};

	level_18.waves[1] = (t_wave){0, WAVE_TICKS, 42, SDL_FALSE, SDL_FALSE, 29, SDL_FALSE, NULL};
	level_18.waves[1].wave_array = SDL_malloc(sizeof(*(level_18.waves[1].wave_array)) * level_18.waves[1].size);

	int	t = 14;
	level_18.waves[1].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, 0 * t,  SDL_TRUE, {0, 349}, 0};
	level_18.waves[1].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, 1 * t,  SDL_TRUE, {0, 312}, 0};
	level_18.waves[1].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, 2 * t,  SDL_TRUE, {0, 198}, 0};
	level_18.waves[1].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, 3 * t,  SDL_TRUE, {0, 58}, 0};
	level_18.waves[1].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, 4 * t,  SDL_TRUE, {0, 339}, 0};
	level_18.waves[1].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, 5 * t,  SDL_TRUE, {0, 249}, 0};
	level_18.waves[1].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, 6 * t,  SDL_TRUE, {0, 331}, 0};
	level_18.waves[1].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, 7 * t,  SDL_TRUE, {0, 127}, 0};
	level_18.waves[1].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, 8 * t,  SDL_TRUE, {0, 237}, 0};
	level_18.waves[1].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, 9 * t,  SDL_TRUE, {0, 144}, 0};
	level_18.waves[1].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, 10 * t, SDL_TRUE, {0, 219}, 0};
	level_18.waves[1].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, 11 * t, SDL_TRUE, {0, 142}, 0};
	level_18.waves[1].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, 12 * t, SDL_TRUE, {0, 110}, 0};
	level_18.waves[1].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, 13 * t, SDL_TRUE, {0, 40}, 0};
	level_18.waves[1].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, 14 * t, SDL_TRUE, {0, 200}, 0};
	level_18.waves[1].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, 15 * t, SDL_TRUE, {0, 351}, 0};
	level_18.waves[1].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, 16 * t, SDL_TRUE, {0, 157}, 0};
	level_18.waves[1].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, 17 * t, SDL_TRUE, {0, 70}, 0};
	level_18.waves[1].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, 18 * t, SDL_TRUE, {0, 306}, 0};

	level_18.waves[1].wave_array[19] = (t_wave_elem){E_SLIME_INV,  0, 15 + 2 * t,  SDL_TRUE, {0, 198}, 0};
	level_18.waves[1].wave_array[20] = (t_wave_elem){E_SLIME_INV,  0, 15 + 3 * t,  SDL_TRUE, {0, 58}, 0};
	level_18.waves[1].wave_array[21] = (t_wave_elem){E_SLIME_INV,  0, 15 + 6 * t,  SDL_TRUE, {0, 331}, 0};
	level_18.waves[1].wave_array[22] = (t_wave_elem){E_SLIME_INV,  0, 15 + 7 * t,  SDL_TRUE, {0, 127}, 0};
	level_18.waves[1].wave_array[23] = (t_wave_elem){E_SLIME_INV,  0, 15 + 10 * t, SDL_TRUE, {0, 219}, 0};
	level_18.waves[1].wave_array[24] = (t_wave_elem){E_SLIME_INV,  0, 15 + 12 * t, SDL_TRUE, {0, 110}, 0};
	level_18.waves[1].wave_array[25] = (t_wave_elem){E_SLIME_INV,  0, 15 + 13 * t, SDL_TRUE, {0, 40}, 0};
	level_18.waves[1].wave_array[26] = (t_wave_elem){E_SLIME_INV,  0, 15 + 14 * t, SDL_TRUE, {0, 200}, 0};
	level_18.waves[1].wave_array[27] = (t_wave_elem){E_SLIME_INV,  0, 15 + 15 * t, SDL_TRUE, {0, 351}, 0};
	level_18.waves[1].wave_array[28] = (t_wave_elem){E_SLIME_INV,  0, 15 + 16 * t, SDL_TRUE, {0, 157}, 0};

	level_18.waves[2] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 41, SDL_FALSE, NULL};
	level_18.waves[2].wave_array = SDL_malloc(sizeof(*(level_18.waves[2].wave_array)) * level_18.waves[2].size);

	a = 360 / 16;
	level_18.waves[2].wave_array[0] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 0}, 0};
	level_18.waves[2].wave_array[1] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 1}, 0};
	level_18.waves[2].wave_array[2] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 2}, 0};
	level_18.waves[2].wave_array[3] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 3}, 0};
	level_18.waves[2].wave_array[4] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 4}, 0};
	level_18.waves[2].wave_array[5] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 5}, 0};
	level_18.waves[2].wave_array[6] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 6}, 0};
	level_18.waves[2].wave_array[7] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 7}, 0};
	level_18.waves[2].wave_array[8] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 8}, 0};
	level_18.waves[2].wave_array[9] =  (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE,  {0, a * 9}, 0};
	level_18.waves[2].wave_array[10] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 10}, 0};
	level_18.waves[2].wave_array[11] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 11}, 0};
	level_18.waves[2].wave_array[12] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 12}, 0};
	level_18.waves[2].wave_array[13] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 13}, 0};
	level_18.waves[2].wave_array[14] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 14}, 0};
	level_18.waves[2].wave_array[15] = (t_wave_elem){E_SLIME_CYAN,  0, 0, SDL_TRUE, {0, a * 15}, 0};

	level_18.waves[2].wave_array[16] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 0, SDL_TRUE, {0, 90}, 0};
	level_18.waves[2].wave_array[17] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 15, SDL_TRUE, {0, 90}, 0};
	level_18.waves[2].wave_array[18] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 30, SDL_TRUE, {0, 90}, 0};
	level_18.waves[2].wave_array[19] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 45, SDL_TRUE, {0, 90}, 0};
	level_18.waves[2].wave_array[20] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 0, SDL_TRUE, {0, 270}, 0};
	level_18.waves[2].wave_array[21] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 15, SDL_TRUE, {0, 270}, 0};
	level_18.waves[2].wave_array[22] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 30, SDL_TRUE, {0, 270}, 0};
	level_18.waves[2].wave_array[23] = (t_wave_elem){E_SLIME_CYAN,  0, 15 + 45, SDL_TRUE, {0, 270}, 0};
	level_18.waves[2].wave_array[24] = (t_wave_elem){E_SLIME_PURP,  0, 80, SDL_TRUE, {0, 90}, 0};
	level_18.waves[2].wave_array[25] = (t_wave_elem){E_SLIME_PURP,  0, 80, SDL_TRUE, {0, 270}, 0};

	level_18.waves[2].wave_array[26] = (t_wave_elem){E_SLIME_PURP,  0, 160 + 64, SDL_TRUE,	{0, 54}, 0};
	level_18.waves[2].wave_array[27] = (t_wave_elem){E_SLIME_CYAN,  0, 160 + 0, SDL_TRUE,	{0, 54}, 0};
	level_18.waves[2].wave_array[28] = (t_wave_elem){E_SLIME_CYAN,  0, 160 + 15, SDL_TRUE,	{0, 54}, 0};
	level_18.waves[2].wave_array[29] = (t_wave_elem){E_SLIME_CYAN,  0, 160 + 30, SDL_TRUE,	{0, 54}, 0};
	level_18.waves[2].wave_array[30] = (t_wave_elem){E_SLIME_CYAN,  0, 160 + 45, SDL_TRUE,	{0, 54}, 0};
	level_18.waves[2].wave_array[31] = (t_wave_elem){E_SLIME_PURP,  0, 200 + 64, SDL_TRUE,	{0, 111}, 0};
	level_18.waves[2].wave_array[32] = (t_wave_elem){E_SLIME_CYAN,  0, 200 + 0, SDL_TRUE,	{0, 111}, 0};
	level_18.waves[2].wave_array[33] = (t_wave_elem){E_SLIME_CYAN,  0, 200 + 15, SDL_TRUE,	{0, 111}, 0};
	level_18.waves[2].wave_array[34] = (t_wave_elem){E_SLIME_CYAN,  0, 200 + 30, SDL_TRUE,	{0, 111}, 0};
	level_18.waves[2].wave_array[35] = (t_wave_elem){E_SLIME_CYAN,  0, 200 + 45, SDL_TRUE,	{0, 111}, 0};
	level_18.waves[2].wave_array[36] = (t_wave_elem){E_SLIME_PURP,  0, 240 + 64, SDL_TRUE,	{0, 285}, 0};
	level_18.waves[2].wave_array[37] = (t_wave_elem){E_SLIME_CYAN,  0, 240 + 0, SDL_TRUE,	{0, 285}, 0};
	level_18.waves[2].wave_array[38] = (t_wave_elem){E_SLIME_CYAN,  0, 240 + 15, SDL_TRUE,	{0, 285}, 0};
	level_18.waves[2].wave_array[39] = (t_wave_elem){E_SLIME_CYAN,  0, 240 + 30, SDL_TRUE,	{0, 285}, 0};
	level_18.waves[2].wave_array[40] = (t_wave_elem){E_SLIME_CYAN,  0, 240 + 45, SDL_TRUE,	{0, 285}, 0};

	level_18.waves[3] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 29, SDL_FALSE, NULL};
	level_18.waves[3].wave_array = SDL_malloc(sizeof(*(level_18.waves[3].wave_array)) * level_18.waves[3].size);

	t = 20;
	level_18.waves[3].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 0, SDL_TRUE, {0, 280}, 0};
	level_18.waves[3].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 1, SDL_TRUE, {0, 103}, 0};
	level_18.waves[3].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 2, SDL_TRUE, {0, 111}, 0};
	level_18.waves[3].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 3, SDL_TRUE, {0, 22}, 0};
	level_18.waves[3].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 4, SDL_TRUE, {0, 341}, 0};
	level_18.waves[3].wave_array[5] =  (t_wave_elem){E_SLIME_PURP,  0, t * 5, SDL_TRUE, {0, 20}, 0};
	level_18.waves[3].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 6, SDL_TRUE, {0, 102}, 0};
	level_18.waves[3].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 7, SDL_TRUE, {0, 265}, 0};
	level_18.waves[3].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 8, SDL_TRUE, {0, 133}, 0};
	level_18.waves[3].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, t * 9, SDL_TRUE, {0, 25}, 0};
	level_18.waves[3].wave_array[10] = (t_wave_elem){E_SLIME_PURP,  0, t * 10, SDL_TRUE, {0, 36}, 0};
	level_18.waves[3].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, t * 11, SDL_TRUE, {0, 188}, 0};
	level_18.waves[3].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, t * 12, SDL_TRUE, {0, 270}, 0};
	level_18.waves[3].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, t * 13, SDL_TRUE, {0, 307}, 0};
	level_18.waves[3].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, t * 14, SDL_TRUE, {0, 131}, 0};
	level_18.waves[3].wave_array[15] = (t_wave_elem){E_SLIME_PURP,  0, t * 15, SDL_TRUE, {0, 360}, 0};
	level_18.waves[3].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, t * 16, SDL_TRUE, {0, 300}, 0};
	level_18.waves[3].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, t * 17, SDL_TRUE, {0, 27}, 0};
	level_18.waves[3].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, t * 18, SDL_TRUE, {0, 359}, 0};
	level_18.waves[3].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, t * 19, SDL_TRUE, {0, 103}, 0};
	level_18.waves[3].wave_array[20] = (t_wave_elem){E_SLIME_PURP,  0, t * 20, SDL_TRUE, {0, 182}, 0};
	level_18.waves[3].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, t * 21, SDL_TRUE, {0, 202}, 0};
	level_18.waves[3].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, t * 22, SDL_TRUE, {0, 51}, 0};
	level_18.waves[3].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, t * 23, SDL_TRUE, {0, 320}, 0};

	t = (t * 24) / 5;
	level_18.waves[3].wave_array[24] = (t_wave_elem){E_SLIME_INV,  0, t * 0, SDL_TRUE, {0, 159}, 0};
	level_18.waves[3].wave_array[25] = (t_wave_elem){E_SLIME_INV,  0, t * 1, SDL_TRUE, {0, 354}, 0};
	level_18.waves[3].wave_array[26] = (t_wave_elem){E_SLIME_INV,  0, t * 2, SDL_TRUE, {0, 19}, 0};
	level_18.waves[3].wave_array[27] = (t_wave_elem){E_SLIME_INV,  0, t * 3, SDL_TRUE, {0, 310}, 0};
	level_18.waves[3].wave_array[28] = (t_wave_elem){E_SLIME_INV,  0, t * 4, SDL_TRUE, {0, 20}, 0};

	level_18.waves[4] = (t_wave){0, WAVE_PREV_DEFEAT, 0, SDL_FALSE, SDL_FALSE, 86, SDL_FALSE, NULL};
	level_18.waves[4].wave_array = SDL_malloc(sizeof(*(level_18.waves[4].wave_array)) * level_18.waves[4].size);

	t = 20;
	a = 10;
	level_18.waves[4].wave_array[0] =  (t_wave_elem){E_SLIME_BLUE,  0, 0 * t, SDL_TRUE,  {0, 0 * a}, 0};
	level_18.waves[4].wave_array[1] =  (t_wave_elem){E_SLIME_BLUE,  0, 1 * t, SDL_TRUE,  {0, 1 * a}, 0};
	level_18.waves[4].wave_array[2] =  (t_wave_elem){E_SLIME_BLUE,  0, 2 * t, SDL_TRUE,  {0, 2 * a}, 0};
	level_18.waves[4].wave_array[3] =  (t_wave_elem){E_SLIME_BLUE,  0, 3 * t, SDL_TRUE,  {0, 3 * a}, 0};
	level_18.waves[4].wave_array[4] =  (t_wave_elem){E_SLIME_BLUE,  0, 4 * t, SDL_TRUE,  {0, 4 * a}, 0};
	level_18.waves[4].wave_array[5] =  (t_wave_elem){E_SLIME_BLUE,  0, 5 * t, SDL_TRUE,  {0, 5 * a}, 0};
	level_18.waves[4].wave_array[6] =  (t_wave_elem){E_SLIME_BLUE,  0, 6 * t, SDL_TRUE,  {0, 6 * a}, 0};
	level_18.waves[4].wave_array[7] =  (t_wave_elem){E_SLIME_BLUE,  0, 7 * t, SDL_TRUE,  {0, 7 * a}, 0};
	level_18.waves[4].wave_array[8] =  (t_wave_elem){E_SLIME_BLUE,  0, 8 * t, SDL_TRUE,  {0, 8 * a}, 0};
	level_18.waves[4].wave_array[9] =  (t_wave_elem){E_SLIME_BLUE,  0, 9 * t, SDL_TRUE,  {0, 9 * a}, 0};
	level_18.waves[4].wave_array[10] = (t_wave_elem){E_SLIME_BLUE,  0, 10 * t, SDL_TRUE, {0, 10 * a}, 0};
	level_18.waves[4].wave_array[11] = (t_wave_elem){E_SLIME_BLUE,  0, 11 * t, SDL_TRUE, {0, 11 * a}, 0};
	level_18.waves[4].wave_array[12] = (t_wave_elem){E_SLIME_BLUE,  0, 12 * t, SDL_TRUE, {0, 12 * a}, 0};
	level_18.waves[4].wave_array[13] = (t_wave_elem){E_SLIME_BLUE,  0, 13 * t, SDL_TRUE, {0, 13 * a}, 0};
	level_18.waves[4].wave_array[14] = (t_wave_elem){E_SLIME_BLUE,  0, 14 * t, SDL_TRUE, {0, 14 * a}, 0};
	level_18.waves[4].wave_array[15] = (t_wave_elem){E_SLIME_BLUE,  0, 15 * t, SDL_TRUE, {0, 15 * a}, 0};
	level_18.waves[4].wave_array[16] = (t_wave_elem){E_SLIME_BLUE,  0, 16 * t, SDL_TRUE, {0, 16 * a}, 0};
	level_18.waves[4].wave_array[17] = (t_wave_elem){E_SLIME_BLUE,  0, 17 * t, SDL_TRUE, {0, 17 * a}, 0};
	level_18.waves[4].wave_array[18] = (t_wave_elem){E_SLIME_BLUE,  0, 18 * t, SDL_TRUE, {0, 18 * a}, 0};
	level_18.waves[4].wave_array[19] = (t_wave_elem){E_SLIME_BLUE,  0, 19 * t, SDL_TRUE, {0, 19 * a}, 0};
	level_18.waves[4].wave_array[20] = (t_wave_elem){E_SLIME_BLUE,  0, 20 * t, SDL_TRUE, {0, 20 * a}, 0};
	level_18.waves[4].wave_array[21] = (t_wave_elem){E_SLIME_BLUE,  0, 21 * t, SDL_TRUE, {0, 21 * a}, 0};
	level_18.waves[4].wave_array[22] = (t_wave_elem){E_SLIME_BLUE,  0, 22 * t, SDL_TRUE, {0, 22 * a}, 0};
	level_18.waves[4].wave_array[23] = (t_wave_elem){E_SLIME_BLUE,  0, 23 * t, SDL_TRUE, {0, 23 * a}, 0};
	level_18.waves[4].wave_array[24] = (t_wave_elem){E_SLIME_BLUE,  0, 24 * t, SDL_TRUE, {0, 24 * a}, 0};
	level_18.waves[4].wave_array[25] = (t_wave_elem){E_SLIME_BLUE,  0, 25 * t, SDL_TRUE, {0, 25 * a}, 0};
	level_18.waves[4].wave_array[26] = (t_wave_elem){E_SLIME_BLUE,  0, 26 * t, SDL_TRUE, {0, 26 * a}, 0};
	level_18.waves[4].wave_array[27] = (t_wave_elem){E_SLIME_BLUE,  0, 27 * t, SDL_TRUE, {0, 27 * a}, 0};
	level_18.waves[4].wave_array[28] = (t_wave_elem){E_SLIME_BLUE,  0, 28 * t, SDL_TRUE, {0, 28 * a}, 0};
	level_18.waves[4].wave_array[29] = (t_wave_elem){E_SLIME_BLUE,  0, 29 * t, SDL_TRUE, {0, 29 * a}, 0};
	level_18.waves[4].wave_array[30] = (t_wave_elem){E_SLIME_BLUE,  0, 30 * t, SDL_TRUE, {0, 30 * a}, 0};
	level_18.waves[4].wave_array[31] = (t_wave_elem){E_SLIME_BLUE,  0, 31 * t, SDL_TRUE, {0, 31 * a}, 0};
	level_18.waves[4].wave_array[32] = (t_wave_elem){E_SLIME_BLUE,  0, 32 * t, SDL_TRUE, {0, 32 * a}, 0};
	level_18.waves[4].wave_array[33] = (t_wave_elem){E_SLIME_BLUE,  0, 33 * t, SDL_TRUE, {0, 33 * a}, 0};
	level_18.waves[4].wave_array[34] = (t_wave_elem){E_SLIME_BLUE,  0, 34 * t, SDL_TRUE, {0, 34 * a}, 0};
	level_18.waves[4].wave_array[35] = (t_wave_elem){E_SLIME_BLUE,  0, 35 * t, SDL_TRUE, {0, 35 * a}, 0};
	level_18.waves[4].wave_array[36] = (t_wave_elem){E_SLIME_BLUE,  0, 36 * t, SDL_TRUE, {0, 36 * a}, 0};
	level_18.waves[4].wave_array[37] = (t_wave_elem){E_SLIME_BLUE,  0, 37 * t, SDL_TRUE, {0, 37 * a}, 0};
	level_18.waves[4].wave_array[38] = (t_wave_elem){E_SLIME_BLUE,  0, 38 * t, SDL_TRUE, {0, 38 * a}, 0};
	level_18.waves[4].wave_array[39] = (t_wave_elem){E_SLIME_BLUE,  0, 39 * t, SDL_TRUE, {0, 39 * a}, 0};
	level_18.waves[4].wave_array[40] = (t_wave_elem){E_SLIME_BLUE,  0, 40 * t, SDL_TRUE, {0, 40 * a}, 0};
	level_18.waves[4].wave_array[41] = (t_wave_elem){E_SLIME_BLUE,  0, 41 * t, SDL_TRUE, {0, 41 * a}, 0};
	level_18.waves[4].wave_array[42] = (t_wave_elem){E_SLIME_BLUE,  0, 42 * t, SDL_TRUE, {0, 42 * a}, 0};

	level_18.waves[4].wave_array[43] = (t_wave_elem){E_SLIME_BLUE,  0, 0 * t, SDL_TRUE,  {0, 180 + 0 * a}, 0};
	level_18.waves[4].wave_array[44] = (t_wave_elem){E_SLIME_BLUE,  0, 1 * t, SDL_TRUE,  {0, 180 + 1 * a}, 0};
	level_18.waves[4].wave_array[45] = (t_wave_elem){E_SLIME_BLUE,  0, 2 * t, SDL_TRUE,  {0, 180 + 2 * a}, 0};
	level_18.waves[4].wave_array[46] = (t_wave_elem){E_SLIME_BLUE,  0, 3 * t, SDL_TRUE,  {0, 180 + 3 * a}, 0};
	level_18.waves[4].wave_array[47] = (t_wave_elem){E_SLIME_BLUE,  0, 4 * t, SDL_TRUE,  {0, 180 + 4 * a}, 0};
	level_18.waves[4].wave_array[48] = (t_wave_elem){E_SLIME_BLUE,  0, 5 * t, SDL_TRUE,  {0, 180 + 5 * a}, 0};
	level_18.waves[4].wave_array[49] = (t_wave_elem){E_SLIME_BLUE,  0, 6 * t, SDL_TRUE,  {0, 180 + 6 * a}, 0};
	level_18.waves[4].wave_array[50] = (t_wave_elem){E_SLIME_BLUE,  0, 7 * t, SDL_TRUE,  {0, 180 + 7 * a}, 0};
	level_18.waves[4].wave_array[51] = (t_wave_elem){E_SLIME_BLUE,  0, 8 * t, SDL_TRUE,  {0, 180 + 8 * a}, 0};
	level_18.waves[4].wave_array[52] = (t_wave_elem){E_SLIME_BLUE,  0, 9 * t, SDL_TRUE,  {0, 180 + 9 * a}, 0};
	level_18.waves[4].wave_array[53] = (t_wave_elem){E_SLIME_BLUE,  0, 10 * t, SDL_TRUE, {0, 180 + 10 * a}, 0};
	level_18.waves[4].wave_array[54] = (t_wave_elem){E_SLIME_BLUE,  0, 11 * t, SDL_TRUE, {0, 180 + 11 * a}, 0};
	level_18.waves[4].wave_array[55] = (t_wave_elem){E_SLIME_BLUE,  0, 12 * t, SDL_TRUE, {0, 180 + 12 * a}, 0};
	level_18.waves[4].wave_array[56] = (t_wave_elem){E_SLIME_BLUE,  0, 13 * t, SDL_TRUE, {0, 180 + 13 * a}, 0};
	level_18.waves[4].wave_array[57] = (t_wave_elem){E_SLIME_BLUE,  0, 14 * t, SDL_TRUE, {0, 180 + 14 * a}, 0};
	level_18.waves[4].wave_array[58] = (t_wave_elem){E_SLIME_BLUE,  0, 15 * t, SDL_TRUE, {0, 180 + 15 * a}, 0};
	level_18.waves[4].wave_array[59] = (t_wave_elem){E_SLIME_BLUE,  0, 16 * t, SDL_TRUE, {0, 180 + 16 * a}, 0};
	level_18.waves[4].wave_array[60] = (t_wave_elem){E_SLIME_BLUE,  0, 17 * t, SDL_TRUE, {0, 180 + 17 * a}, 0};
	level_18.waves[4].wave_array[61] = (t_wave_elem){E_SLIME_BLUE,  0, 18 * t, SDL_TRUE, {0, 180 + 18 * a}, 0};
	level_18.waves[4].wave_array[62] = (t_wave_elem){E_SLIME_BLUE,  0, 19 * t, SDL_TRUE, {0, 180 + 19 * a}, 0};
	level_18.waves[4].wave_array[63] = (t_wave_elem){E_SLIME_BLUE,  0, 20 * t, SDL_TRUE, {0, 180 + 20 * a}, 0};
	level_18.waves[4].wave_array[64] = (t_wave_elem){E_SLIME_BLUE,  0, 21 * t, SDL_TRUE, {0, 180 + 21 * a}, 0};
	level_18.waves[4].wave_array[65] = (t_wave_elem){E_SLIME_BLUE,  0, 22 * t, SDL_TRUE, {0, 180 + 22 * a}, 0};
	level_18.waves[4].wave_array[66] = (t_wave_elem){E_SLIME_BLUE,  0, 23 * t, SDL_TRUE, {0, 180 + 23 * a}, 0};
	level_18.waves[4].wave_array[67] = (t_wave_elem){E_SLIME_BLUE,  0, 24 * t, SDL_TRUE, {0, 180 + 24 * a}, 0};
	level_18.waves[4].wave_array[68] = (t_wave_elem){E_SLIME_BLUE,  0, 25 * t, SDL_TRUE, {0, 180 + 25 * a}, 0};
	level_18.waves[4].wave_array[69] = (t_wave_elem){E_SLIME_BLUE,  0, 26 * t, SDL_TRUE, {0, 180 + 26 * a}, 0};
	level_18.waves[4].wave_array[70] = (t_wave_elem){E_SLIME_BLUE,  0, 27 * t, SDL_TRUE, {0, 180 + 27 * a}, 0};
	level_18.waves[4].wave_array[71] = (t_wave_elem){E_SLIME_BLUE,  0, 28 * t, SDL_TRUE, {0, 180 + 28 * a}, 0};
	level_18.waves[4].wave_array[72] = (t_wave_elem){E_SLIME_BLUE,  0, 29 * t, SDL_TRUE, {0, 180 + 29 * a}, 0};
	level_18.waves[4].wave_array[73] = (t_wave_elem){E_SLIME_BLUE,  0, 30 * t, SDL_TRUE, {0, 180 + 30 * a}, 0};
	level_18.waves[4].wave_array[74] = (t_wave_elem){E_SLIME_BLUE,  0, 31 * t, SDL_TRUE, {0, 180 + 31 * a}, 0};
	level_18.waves[4].wave_array[75] = (t_wave_elem){E_SLIME_BLUE,  0, 32 * t, SDL_TRUE, {0, 180 + 32 * a}, 0};
	level_18.waves[4].wave_array[76] = (t_wave_elem){E_SLIME_BLUE,  0, 33 * t, SDL_TRUE, {0, 180 + 33 * a}, 0};
	level_18.waves[4].wave_array[77] = (t_wave_elem){E_SLIME_BLUE,  0, 34 * t, SDL_TRUE, {0, 180 + 34 * a}, 0};
	level_18.waves[4].wave_array[78] = (t_wave_elem){E_SLIME_BLUE,  0, 35 * t, SDL_TRUE, {0, 180 + 35 * a}, 0};
	level_18.waves[4].wave_array[79] = (t_wave_elem){E_SLIME_BLUE,  0, 36 * t, SDL_TRUE, {0, 180 + 36 * a}, 0};
	level_18.waves[4].wave_array[80] = (t_wave_elem){E_SLIME_BLUE,  0, 37 * t, SDL_TRUE, {0, 180 + 37 * a}, 0};
	level_18.waves[4].wave_array[81] = (t_wave_elem){E_SLIME_BLUE,  0, 38 * t, SDL_TRUE, {0, 180 + 38 * a}, 0};
	level_18.waves[4].wave_array[82] = (t_wave_elem){E_SLIME_BLUE,  0, 39 * t, SDL_TRUE, {0, 180 + 39 * a}, 0};
	level_18.waves[4].wave_array[83] = (t_wave_elem){E_SLIME_BLUE,  0, 40 * t, SDL_TRUE, {0, 180 + 40 * a}, 0};
	level_18.waves[4].wave_array[84] = (t_wave_elem){E_SLIME_BLUE,  0, 41 * t, SDL_TRUE, {0, 180 + 41 * a}, 0};
	level_18.waves[4].wave_array[85] = (t_wave_elem){E_SLIME_BLUE,  0, 42 * t, SDL_TRUE, {0, 180 + 42 * a}, 0};

	return (level_18);
}