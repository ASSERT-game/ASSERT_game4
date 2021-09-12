/***************************************************************************
 * FILENAME:    player.c
 * DESCRIPTION: Player struct file.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.54.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 12Jun2021
***************************************************************************/

#include "main.h"

void	crosshair_init(SDLX_Sprite *crosshair)
{
	*crosshair = SDLX_Sprite_Static(ASSETS"crosshair.png");

	crosshair->dst = &(crosshair->_dst);
	crosshair->_dst = (SDL_Rect){(PLAY_WIDTH) / 2 - 40, (PLAY_HEIGHT) / 2 - 40, 80, 80};
}

void	update_crosshair(SDLX_Sprite *crosshair)
{
	double x, y;

	x = g_GameInput.GameInput.leftaxis.x / 32767.0;
	y = g_GameInput.GameInput.leftaxis.y / 32767.0;

	if (SDL_fabs(x) > 0.25 || SDL_fabs(y) > .25)
	{
		g_GameInput.GameInput.primary.x = x * 3 + MID_PLAY_WIDTH;
		g_GameInput.GameInput.primary.y = y * 3 + MID_PLAY_HEIGHT;
	}

	if (g_GameInput.GameInput.primary.y <= PLAY_HEIGHT)
		crosshair->angle = SDLX_Radian_to_Degree(ptoa(g_GameInput.GameInput.primary.x, g_GameInput.GameInput.primary.y)) - 90 - 45;

	SDLX_RenderQueue_Add(NULL, crosshair);
}

SDL_bool	player_hit(SDL_UNUSED void *self, void *with, SDL_UNUSED void *meta, SDL_UNUSED void *meta1)
{
	SDLX_collision	*hitbox;
	t_player		*player;

	player = self;
	hitbox = with;
	if (hitbox->type & player->player_hurtbox.response_amount)
	{
		if (SDLX_Collide_RectToRect(hitbox, &(player->player_hurtbox)))
			return (SDL_TRUE);
	}
	return (SDL_FALSE);
}

void		*player_collide(void *self, SDL_UNUSED void *with, SDL_UNUSED void *meta, SDL_UNUSED void *meta1)
{
	t_player	*player;
	SDLX_collision	*object;
	int				damage_taken;


	player = self;
	object = with;
	damage_taken = (int)(object->engage_meta1);
	player->hp -= damage_taken;

	return (NULL);
}

void	resize_healthbar(t_player *self)
{
	if (self->hp > self->max_hp)
		self->hp = self->max_hp;

	self->hp_s._dst.w = lerp32(((double)self->hp) / self->max_hp, 16, PLAY_WIDTH - 16);

	if (self->hpl_s._dst.w > self->hp_s._dst.w)
		self->hpl_s._dst.w--;
	else if (self->hpl_s._dst.w < self->hp_s._dst.w)
		self->hpl_s._dst.w = self->hp_s._dst.w;
}

void	player_update(t_player *self)
{
	t_weapon	*weapon;
	t_bullet	*bullet_addr;
	static int	time;

	weapon = self->weapon_equip;
	if (weapon->trigger(weapon) == SDL_TRUE)
	{
		weapon->curr = weapon->start;
		bullet_addr = spawn_projectile_addr(&(self->attacks));
		weapon->factory(bullet_addr, (SDL_Point){0, 0}, 0, self);
	}

	resize_healthbar(self);
	self->heart.current++;
	time++;
	double angle = SDLX_Radian_to_Degree(ptoa(g_GameInput.GameInput.primary.x, g_GameInput.GameInput.primary.y)) - 90;
	if (0 <= angle && angle <= 180)
		self->sprite.flip = SDL_FLIP_NONE;
	else
		self->sprite.flip = SDL_FLIP_HORIZONTAL;

	if (time % 2 == 0 || self->hp > 50)
		self->sprite.current++;


	SDLX_RenderQueue_Add(NULL, &(self->heart));
	SDLX_RenderQueue_Add(NULL, &(self->hp_s));
	SDLX_RenderQueue_Add(NULL, &(self->hpl_s));
	SDLX_RenderQueue_Add(NULL, &(self->sprite));

	SDLX_CollisionBucket_add(NULL, &(self->player_hurtbox));
}

void	player_init(t_player *player)
{
	fetch_bunny_sprite(&(player->sprite.sprite_data), 0);
	// player->sprite = SDLX_Sprite_Static(ASSETS"bunny.png");
	player->sprite.dst = &(player->sprite._dst);
	player->sprite._dst = (SDL_Rect){(PLAY_WIDTH - 48) / 2, (PLAY_HEIGHT - 48) / 2, 48, 48};

	SDLX_new_Sprite(&(player->hp_s));
	fetch_hp_sprite(&(player->hp_s.sprite_data), 1);
	player->hp_s._dst = (SDL_Rect){20, 375, 0, 8};

	SDLX_new_Sprite(&(player->hpl_s));
	fetch_hp_sprite(&(player->hpl_s.sprite_data), -1);
	player->hpl_s._dst = (SDL_Rect){20, 375, 50, 8};

	SDLX_new_Sprite(&(player->heart));
	fetch_hp_sprite(&(player->heart.sprite_data), 3);
	player->heart._dst = (SDL_Rect){4, 364, 32, 32};

	player->hp =		100;
	player->max_hp =	100;

	player->player_hurtbox.originator = player;
	player->player_hurtbox.detect = player_hit;
	player->player_hurtbox.engage = player_collide;
	player->player_hurtbox.type = C_PLAYER;
	player->player_hurtbox.response_amount = C_E_BODY | C_E_PROJECTILE;

	player->hurtbox.x = player->sprite._dst.x + 10;
	player->hurtbox.y = player->sprite._dst.y + 10;
	player->hurtbox.h = player->sprite._dst.h - 20;
	player->hurtbox.w = player->sprite._dst.w - 20;

	player->player_hurtbox.hitbox_ptr = &(player->hurtbox);

	player->score = 0;

	init_attack_array(&(player->attacks));
}
