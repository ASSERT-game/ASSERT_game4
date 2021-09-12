/***************************************************************************
 * FILENAME:    weapon_manager.c
 * DESCRIPTION: Manager for the projectiles and enemy systems.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 21Jun2021
***************************************************************************/

#include "main.h"

#define DEFAULT_E_SIZE (200)
#define DEFAULT_P_SIZE (200)

void	init_enemy_array(t_enemy_m *manager) { manager->capacity = DEFAULT_E_SIZE; SDLX_CALLOC_M(manager->entity_array, manager->capacity); }
void	init_attack_array(t_attacks *manager) { manager->capacity = DEFAULT_P_SIZE; SDLX_CALLOC_M(manager->attacks, manager->capacity); }

void	enemy_apply_fn(void *ptr) {t_enemy *enemy = ptr; if (enemy->isActive) { enemy->update(enemy, NULL); } }
void	projectile_apply_fn(void *ptr) {t_bullet *projectile = ptr; if (projectile->isActive) { projectile->update(projectile, NULL); } }

void	projectile_update(t_attacks *attacks) { SDLX_xIter(attacks->attacks, attacks->capacity, sizeof(*(attacks->attacks)), projectile_apply_fn); }
void	iter_enemies(t_enemy_m *enemies) { SDLX_xIter(enemies->entity_array, enemies->capacity, sizeof(*(enemies->entity_array)), enemy_apply_fn); }

t_bullet	*spawn_projectile_addr(t_attacks *dst)
{
	size_t		ix;

	ix = 0;
	while (ix < dst->capacity && dst->attacks[ix].isActive == SDL_TRUE)
		ix++;

	SDL_assert(ix < dst->capacity);
	return (&(dst->attacks[ix]));
}

t_enemy *spawn_enemy_addr(t_enemy_m *manager)
{
	size_t	ix;

	ix = 0;
	while (ix < manager->capacity && manager->entity_array[ix].isActive == SDL_TRUE)
		ix++;

	SDL_assert(ix < manager->capacity);
	return (&(manager->entity_array[ix]));
}
