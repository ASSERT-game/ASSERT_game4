/***************************************************************************
 * FILENAME:    input.c
 * DESCRIPTION: Keyboard input for game.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 07Jul2021
***************************************************************************/

#include "main.h"

void	set_levels(t_level_progress (*levels)[5][5])
{
	(*levels)[0][0] = (t_level_progress){ SDL_TRUE, SDL_FALSE, level_01_init,  null_cannon()};
	(*levels)[0][1] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_02_init, null_cannon()};
	(*levels)[0][2] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_03_init, null_cannon()};
	(*levels)[0][3] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_04_init, null_cannon()};
	(*levels)[0][4] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_05_init, shield_cannon()};
	(*levels)[1][0] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_06_init, null_cannon()};
	(*levels)[1][1] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_07_init, null_cannon()};
	(*levels)[1][2] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_08_init, null_cannon()};
	(*levels)[1][3] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_09_init, null_cannon()};
	(*levels)[1][4] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_10_init, ghostfire_cannon()};
	(*levels)[2][0] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_11_init, null_cannon()};
	(*levels)[2][1] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_12_init, null_cannon()};
	(*levels)[2][2] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_13_init, faser_cannon()};
	(*levels)[2][3] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_14_init, null_cannon()};
	(*levels)[2][4] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_15_init, emp_cannon()};
	(*levels)[3][0] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_16_init, null_cannon()};
	(*levels)[3][1] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_17_init, null_cannon()};
	(*levels)[3][2] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_18_init, null_cannon()};
	(*levels)[3][3] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_19_init, null_cannon()};

	(*levels)[3][4] = (t_level_progress){ SDL_FALSE, SDL_FALSE, level_20_init, laser_cannon()};
}

SDLX_iMap	*blaster_key_map(size_t *size)
{
	static SDLX_iMap	key_map[] =
	{
		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_SCANCODE_SPACE},
		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_SCANCODE_KP_ENTER},
		(SDLX_iMap){&BMAP(button_START),	1, SDL_SCANCODE_ESCAPE},

		(SDLX_iMap){&BMAP(button_num1),	1, SDL_SCANCODE_1},
		(SDLX_iMap){&BMAP(button_num2),	1, SDL_SCANCODE_2},
		(SDLX_iMap){&BMAP(button_num3),	1, SDL_SCANCODE_3},
		(SDLX_iMap){&BMAP(button_num4),	1, SDL_SCANCODE_4},

		(SDLX_iMap){&BMAP(button_num1),	1, SDL_SCANCODE_A},
		(SDLX_iMap){&BMAP(button_num2),	1, SDL_SCANCODE_S},
		(SDLX_iMap){&BMAP(button_num3),	1, SDL_SCANCODE_D},
		(SDLX_iMap){&BMAP(button_num4),	1, SDL_SCANCODE_F},

		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_1},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_2},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_3},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_4},

		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_A},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_S},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_D},
		(SDLX_iMap){&BMAP(button_primleft),	2, SDL_SCANCODE_F},
	};

	*size = sizeof(key_map) / sizeof(*key_map);
	return (&key_map[0]);
}

SDLX_iMap	*blaster_pad_map(size_t *size)
{
	static SDLX_iMap	key_map[] =
	{
		(SDLX_iMap){&BMAP(button_num1),	1, SDL_CONTROLLER_BUTTON_DPAD_LEFT},
		(SDLX_iMap){&BMAP(button_num3),	1, SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
		(SDLX_iMap){&BMAP(button_num2),	1, SDL_CONTROLLER_BUTTON_DPAD_UP},
		(SDLX_iMap){&BMAP(button_num4),	1, SDL_CONTROLLER_BUTTON_DPAD_DOWN},

		(SDLX_iMap){&BMAP(button_num1),	1, SDL_CONTROLLER_BUTTON_Y},
		(SDLX_iMap){&BMAP(button_num2),	1, SDL_CONTROLLER_BUTTON_X},
		(SDLX_iMap){&BMAP(button_num3),	1, SDL_CONTROLLER_BUTTON_B},
		(SDLX_iMap){&BMAP(button_num4),	1, SDL_CONTROLLER_BUTTON_A},

		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_CONTROLLER_BUTTON_DPAD_LEFT},
		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_CONTROLLER_BUTTON_DPAD_UP},
		(SDLX_iMap){&BMAP(button_primleft),	1, SDL_CONTROLLER_BUTTON_DPAD_DOWN},

		(SDLX_iMap){&BMAP(button_START),	1, SDL_CONTROLLER_BUTTON_START},
	};

	*size = sizeof(key_map) / sizeof(*key_map);
	return (&key_map[0]);
}