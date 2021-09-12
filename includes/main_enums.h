/***************************************************************************
 * FILENAME:    main_enums.h
 * DESCRIPTION: File with the enums used in blaster.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 16Jul2021
***************************************************************************/

#ifndef MAIN_ENUMS_H
# define MAIN_ENUMS_H

# define ABILITY_CHANGED (2)

enum	BLASTER_UI_SPRITES
{
	BACK_NORM,
	BACK_HOVER,

	PLAY_NORM,
	PLAY_HOVER,
	PAUSE_NORM,

	MMENU_NORM,
	MMENU_HOVER,
	MREDO_NORM,
	MREDO_HOVER,
	MPLAY_NORM,
	MPLAY_HOVER,
	MBACK,

	LMENU_NORM,
	LMENU_HOVER,
	LREDO_NORM,
	LREDO_HOVER,
	LNEXT_NORM,
	LNEXT_HOVER,
	LBACK_UI,
	DBACK_UI,

	ABILITY,
	ABILITY_SEL,

	EMPTY_UI,

	LOCK_NORM = 512,
	LOCK_HOVER,
	INCO_FRAME,
	COMP_FRAME,
};

enum	e_weapon_types
{
	B_NONE		= 0b00000,
	B_MAINHAND	= 0b00001,
	B_OFFHAND	= 0b00010,
	B_DEFENSE	= 0b00100,
	B_SPECIAL	= 0b01000,
};

enum	e_collision_types
{
	/* The lower bits are box type and how to interpret box types */

	C_RECT			= 0b00000000000000000001, /* Regular Rectangle */
	C_ARECT			= 0b00000000000000000010, /* Angled Rectangle */
	C_CIRCLE		= 0b00000000000000000100, /* Circle Collision */

	/* The following bits are categorical types */

	C_PLAYER		= 0b00000000000000001000, /* Player */
	C_PROJECTILE	= 0b00000000000000010000, /* Player Projectile */
	C_MELEE			= 0b00000000000000100000, /* Player Melee */
	C_FIELD			= 0b00000000000001000000, /* Player Melee */
	C_E_PROJECTILE	= 0b00000000000010000000, /* Enemy Projectile */
	C_E_BODY		= 0b00000000000100000000, /* Enemy Body */

	C_DEAD			= 0b00000000001000000000, /* Dead / No-Collide */
	C_NONE			= C_DEAD, /* Dead / No-Collide */
};

enum	e_effects
{
	RUNIC_SHIELD,
	EMP_FIELD,
	GHOST_BURN,

	EFFECT_SIZE
};

#endif