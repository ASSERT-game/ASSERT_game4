/***************************************************************************
 * FILENAME:    enemy.c
 * DESCRIPTION: Handles the slime
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Jun2021
***************************************************************************/

#include "main.h"

#define SPAWN_RAD (200)

void		slime_cyan_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	double	angle;

	slime_default_init(dst, "slime_cyan", C_E_BODY, 3, slime_blue_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);
	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);
	dst->speed = .85;

	if (mod >> 8 > 0)
		dst->speed = 1.5;

	dst->enemy_hurtbox.engage_meta1 = (void *)10;
	dst->enemy_hurtbox.detect = slime_detect_collision_once;

	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);
	dst->sprite.current = mod;
}

void		slime_spiny_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	double	angle;

	slime_default_init(dst, "slime_spiny", C_E_BODY, 1, slime_spiny_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);

	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);
	dst->speed = 2;
	// dst->meta1 = (void *)4;
	if (mod >> 8 > 0)
		dst->speed = .85;

	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);

	dst->enemy_hurtbox.engage_meta1 = (void *)10;
}

void		slime_inv_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	double	angle;

	slime_default_init(dst, "slime_inv", C_E_BODY, 1, slime_blue_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);

	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);
	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);
	dst->speed = 1.5;
	dst->enemy_hurtbox.engage_meta1 = (void *)15;
}

void		slime_blue_init(t_enemy *dst, SDL_Point loc, int mod)
{
	double	angle;

	slime_default_init(dst, "slime_blue", C_E_BODY, 1, slime_blue_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);
	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);
	dst->enemy_hurtbox.engage_meta1 = (void *)6;
	dst->speed = 1.5;

	fetch_slime_sprite(&(dst->sprite.sprite_data), 0);
	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);

	if (mod >> 8 > 0)
		dst->speed = .85;
	else
		dst->sprite.current = mod;

}

void		slime_green_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	slime_default_init(dst, "slime_green", C_E_BODY, 2, slime_blue_update);
	dst->sprite._dst.x = loc.x;
	dst->sprite._dst.y = loc.y;
	dst->meta1 = (void *)4;
	dst->enemy_hurtbox.engage_meta1 = (void *)10;
}

void		slime_yellow_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	double	angle;

	slime_default_init(dst, "slime_yellow", C_E_BODY, 2, slime_yellow_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);
	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);

	dst->speed = 1.25;

	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);
	dst->enemy_hurtbox.engage_meta1 = (void *)10;

	dst->meta2 = (void *)0;
}

void		slime_purple_init(t_enemy *dst, SDL_Point loc, SDL_UNUSED int mod)
{
	double	angle;

	slime_default_init(dst, "slime_purple", C_E_BODY, 3, slime_purple_update);
	angle = loc.y;
	circle_spawn(&(loc.x), &(loc.y), SPAWN_RAD, angle);
	dst->sprite._dst.x = loc.x - (dst->sprite._dst.w / 2);
	dst->sprite._dst.y = loc.y - (dst->sprite._dst.h / 2);

	dst->speed = 1.3;
	if (mod >> 8 > 0)
		dst->speed = .85;

	dst->delta.x = loc.x - (dst->sprite._dst.w / 2);
	dst->delta.y = loc.y - (dst->sprite._dst.h / 2);
	dst->meta2 = 0;
	dst->enemy_hurtbox.engage_meta1 = (void *)10;
}

void		*slime_collide(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	t_enemy			*slime;
	SDLX_collision	*hurtbox;

	slime = self;
	slime->hp -= 1;

	hurtbox = with;
	if (hurtbox->type == C_PLAYER)
		slime->hp = 0;

	return (NULL);
}

void	dead_slime(t_enemy *slime, SDL_UNUSED void *meta)
{
	if (slime->sprite.current >= 7)
		slime->isActive = SDL_FALSE;
	else
	{
		SDLX_RenderQueue_Add(NULL, &(slime->sprite));
		slime->sprite.current++;
	}

}

void	slime_blue_update(t_enemy *slime, SDL_UNUSED void *meta)
{
	size_t		*score;
	double		angle;
	double		dx, dy;

	angle = ptoa(slime->delta.x + 16, slime->delta.y + 16);

	dx = SDL_sin(angle) * (slime->speed);
	dy = SDL_cos(angle) * -(slime->speed);

	slime->delta.x -= dx;
	slime->delta.y -= dy;

	slime->sprite._dst.x = slime->delta.x;
	slime->sprite._dst.y = slime->delta.y;

	update_status(slime);

	if (slime->hp <= 0)
	{
		// slime->isActive = SDL_FALSE;
		score = slime->score_ptr;
		fetch_slime_sprite(&(slime->sprite.sprite_data), 1);
		slime->enemy_hurtbox.detect = NULL;
		slime->enemy_hurtbox.type = C_DEAD;
		slime->sprite.current = 0;
		slime->update = dead_slime;
		(*score)++;
	}
	else
	{
		SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
	}
	SDLX_RenderQueue_Add(NULL, &(slime->sprite));
	slime->sprite.current++;
}

void	slime_yellow_update(t_enemy *slime, SDL_UNUSED void *meta)
{
	SDL_bool	enraged;
	size_t		*score;
	double		angle;
	double		x, y;
	double		dx, dy;
	double		speed_addon;

	speed_addon = 0;
	enraged = SDL_FALSE;
	y = slime->delta.y;
	x = slime->delta.x;
	dx = x - MID_PLAY_WIDTH + (slime->sprite._dst.w / 2);
	dy = y - MID_PLAY_HEIGHT + (slime->sprite._dst.h / 2);

	if ((dx * dx) + (dy * dy) < 130 * 130)
	{
		enraged = SDL_TRUE;
		slime->meta2++;
	}

	if (enraged && slime->effects[EMP_FIELD].info == 0)
	{
		if ((int)slime->meta2 >= 22)
			speed_addon = 5;
		else
			speed_addon = -1.5;
	}

	angle = ptoa(slime->delta.x + 16, slime->delta.y + 16);

	dx = SDL_sin(angle) * (slime->speed + speed_addon);
	dy = SDL_cos(angle) * -(slime->speed + speed_addon);

	slime->delta.x -= dx;
	slime->delta.y -= dy;

	slime->sprite._dst.x = slime->delta.x;
	slime->sprite._dst.y = slime->delta.y;

	update_status(slime);

	if (slime->hp <= 0)
	{
		slime->isActive = SDL_FALSE;
		score = slime->score_ptr;
		(*score)++;
	}
	else
	{
		SDLX_RenderQueue_Add(NULL, &(slime->sprite));
		SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
	}

}

SDL_bool	goo_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collision	*hitbox;
	t_bullet		*self_attack;

	hitbox = with;

	self_attack = self;
	if (hitbox->type & self_attack->hitbox.response_amount)
	{
		if (SDL_HasIntersection(self_attack->hitbox.hitbox_ptr, hitbox->hitbox_ptr))
			self_attack->isActive = SDL_FALSE;
	}
	return (SDL_FALSE);
}

void	goo_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	SDL_Rect	play_area;

	bullet = self;

	if (bullet->isActive == SDL_FALSE)
		return ;

	play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (SDL_HasIntersection(&(bullet->sprite._dst), &(play_area)) == SDL_FALSE)
	{
		bullet->isActive = SDL_FALSE;
		SDL_free(bullet->sprite.sprite_data);
		return ;
	}

	double		angle;
	double		dx, dy;

	angle = ptoa(bullet->delta.x + 16, bullet->delta.y + 16);

	dx = SDL_sin(angle) * (bullet->vel.x);
	dy = SDL_cos(angle) * -(bullet->vel.x);

	bullet->delta.x -= dx;
	bullet->delta.y -= dy;

	bullet->sprite._dst.x = bullet->delta.x;
	bullet->sprite._dst.y = bullet->delta.y;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

void	slime_goo(t_bullet *goo, int x, int y)
{
	goo->sprite = SDLX_Sprite_Static(ASSETS"goo.png");
	goo->sprite.dst = SDLX_NULL_SELF;
	goo->sprite._dst = (SDL_Rect){x + 8, y + 8, 16, 16};
	goo->sprite.center = NULL;
	goo->sprite.angle = 0;
	goo->isActive = SDL_TRUE;

	goo->delta.x = goo->sprite._dst.x;
	goo->delta.y = goo->sprite._dst.y;

	goo->vel.x = 3;

	goo->update = goo_update;

	goo->hitbox.type = C_E_PROJECTILE | C_RECT;
	goo->hitbox.response_amount = C_PLAYER | C_MELEE | C_PROJECTILE | C_FIELD;
	goo->hitbox.engage_meta1 = (void *)15;
	goo->hitbox.originator = goo;
	goo->hitbox.hitbox_ptr = &(goo->sprite._dst);

	goo->hitbox.detect = goo_detect_collision;
}

void	slime_purple_update(t_enemy *slime, SDL_UNUSED void *meta)
{
	SDL_bool	fire_range;
	double		x, y;
	double		dx, dy;
	double		angle;
	size_t		*score;

	fire_range = SDL_FALSE;
	y = slime->delta.y;
	x = slime->delta.x;

	dx = x - MID_PLAY_WIDTH + (slime->sprite._dst.w / 2);
	dy = y - MID_PLAY_HEIGHT + (slime->sprite._dst.h / 2);

	if ((dx * dx) + (dy * dy) < 140 * 140)
	{
		fire_range = SDL_TRUE;
		slime->meta2++;
	}

	t_bullet	*goo;

	if (fire_range == SDL_TRUE)
	{
		if ((int)slime->meta2 >= 42)
		{
			goo = spawn_projectile_addr(slime->projectile_spawn);
			slime_goo(goo, x, y);
			slime->meta2 = (void *)0;
		}
	}
	else
	{
		angle = ptoa(slime->delta.x + 16, slime->delta.y + 16);

		dx = SDL_sin(angle) * (slime->speed);
		dy = SDL_cos(angle) * -(slime->speed);

		slime->delta.x -= dx;
		slime->delta.y -= dy;

		slime->sprite._dst.x = slime->delta.x;
		slime->sprite._dst.y = slime->delta.y;
	}


	update_status(slime);

	if (slime->hp <= 0)
	{
		slime->isActive = SDL_FALSE;
		score = slime->score_ptr;
		(*score)++;
	}

	SDLX_RenderQueue_Add(NULL, &(slime->sprite));
	SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
}

void	spine_update(void *self, SDL_UNUSED void *meta)
{
	t_bullet	*bullet;
	SDL_Rect	play_area;

	bullet = self;

	if (bullet->isActive == SDL_FALSE)
		return ;

	play_area = (SDL_Rect){0, 0, PLAY_WIDTH, PLAY_HEIGHT};
	if (SDL_HasIntersection(&(bullet->sprite._dst), &(play_area)) == SDL_FALSE)
	{
		bullet->isActive = SDL_FALSE;
		SDL_free(bullet->sprite.sprite_data);
		return ;
	}

	bullet->sprite._dst.x -= bullet->vel.x;
	bullet->sprite._dst.y -= bullet->vel.y;
	SDLX_RenderQueue_Add(NULL, &(bullet->sprite));
	SDLX_CollisionBucket_add(NULL, &(bullet->hitbox));
}

SDL_bool	spine_detect_collision(void *self, void *with, SDL_UNUSED void *meta1, SDL_UNUSED void *meta2)
{
	SDLX_collision	*hitbox;
	t_bullet		*self_attack;

	hitbox = with;

	self_attack = self;
	if (hitbox->type & C_E_PROJECTILE)
		return (SDL_FALSE);
	if (hitbox->type & self_attack->hitbox.response_amount)
	{
		if (SDL_HasIntersection(self_attack->hitbox.hitbox_ptr, hitbox->hitbox_ptr))
			self_attack->isActive = SDL_FALSE;
	}

	return (SDL_FALSE);
}

void	slime_spine(t_bullet *spine, int x, int y, double angle)
{
	spine->sprite = SDLX_Sprite_Static(ASSETS"spine.png");
	spine->sprite.dst = SDLX_NULL_SELF;
	spine->sprite._dst = (SDL_Rect){x + 8, y + 8, 16, 16};
	spine->sprite.center = NULL;
	spine->sprite.angle = (angle * 180 / M_PI) + 180;
	spine->isActive = SDL_TRUE;

	spine->vel.x = SDL_sin(angle) * 3;
	spine->vel.y = SDL_cos(angle) * -3;

	spine->update = spine_update;

	spine->hitbox.type = C_E_PROJECTILE | C_PROJECTILE;
	spine->hitbox.response_amount = C_PROJECTILE | C_PLAYER | C_MELEE | C_E_BODY;
	spine->hitbox.originator = spine;

	/* Careful with setting pointers to internal pointers that may change */
	spine->hitbox.hitbox_ptr = &(spine->sprite._dst);
	spine->hitbox.engage_meta1 = (void *)15;
	spine->meta = &(spine->sprite._dst);

	spine->hitbox.detect = spine_detect_collision;
}

void	slime_spiny_update(t_enemy *slime, SDL_UNUSED void *meta)
{
	size_t		*score;
	double		angle;
	double		dx, dy;
	double		x, y;
	double		speed;
	t_bullet	*spine;

	x = slime->delta.x + 16 - (PLAY_WIDTH / 2);
	y = slime->delta.y + 16 - (PLAY_HEIGHT / 2);

	speed = slime->speed;
	angle = ptoa(slime->delta.x + 16, slime->delta.y + 16);
	if (x * x + y * y < 88 * 88)
	{
		angle += M_PI_2;
		speed = 4;
	}

	dx = SDL_sin(angle) * (speed);
	dy = SDL_cos(angle) * -(speed);

	slime->delta.x -= dx;
	slime->delta.y -= dy;

	slime->sprite._dst.x = slime->delta.x;
	slime->sprite._dst.y = slime->delta.y;

	update_status(slime);

	if (slime->hp <= 0)
	{
		slime->isActive = SDL_FALSE;
		score = slime->score_ptr;
		(*score)++;
		angle = M_PI_4;
		spine = spawn_projectile_addr(slime->projectile_spawn);
		slime_spine(spine, slime->sprite._dst.x, slime->sprite._dst.y, angle);
		angle += M_PI_2;
		spine = spawn_projectile_addr(slime->projectile_spawn);
		slime_spine(spine, slime->sprite._dst.x, slime->sprite._dst.y, angle);
		angle += M_PI_2;
		spine = spawn_projectile_addr(slime->projectile_spawn);
		slime_spine(spine, slime->sprite._dst.x, slime->sprite._dst.y, angle);
		angle += M_PI_2;
		spine = spawn_projectile_addr(slime->projectile_spawn);
		slime_spine(spine, slime->sprite._dst.x, slime->sprite._dst.y, angle);
	}
	else
	{
		SDLX_RenderQueue_Add(NULL, &(slime->sprite));
		SDLX_CollisionBucket_add(NULL, &(slime->enemy_hurtbox));
	}
}