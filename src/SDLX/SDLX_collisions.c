/***************************************************************************
 * FILENAME:    SDLX_collisions.c
 * DESCRIPTION: Takes care of some portion of the collision system.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 18Jun2021
***************************************************************************/

#include "SDLX.h"

#define SDLX_DEFAULT_CBUCKET_SIZE (50)

SDLX_collision_bucket	default_CollisionBucket;

int		SDLX_CollisionBucket_Init(SDLX_collision_bucket *dst, size_t type)
{
	dst->type = type;

	dst->capacity = SDLX_DEFAULT_CBUCKET_SIZE;
	dst->index = 0;

	dst->content = SDL_calloc(dst->capacity, sizeof(*dst->content));

	return (EXIT_SUCCESS);
}

void	SDLX_CollisionBucket_add(SDLX_collision_bucket *dst, SDLX_collison *body)
{
	if (dst == NULL)
		dst = &(default_CollisionBucket);

	if (dst->index + 1 >= dst->capacity)
	{
		dst->content = SDL_realloc(dst->content, sizeof(dst->content) * (dst->capacity * ALLOC_RATE));
		dst->capacity = dst->capacity * ALLOC_RATE;
	}

	dst->content[dst->index] = body;
	dst->index += 1;
}

void	SDLX_attempt_CollisionBucket(SDLX_collison *body, SDLX_collision_bucket *bucket)
{
	size_t	i;
	SDL_bool	collides;

	i = 0;
	while (i < bucket->index)
	{
		collides = body->detect(body->originator, bucket->content[i]->originator,
								body->detect_meta1, body->detect_meta2, body->detect_meta3);
		if (collides)
		{
			body->engage(body->originator, bucket->content[i]->originator,
						body->detect_meta1, body->detect_meta2, body->detect_meta3);
		}
		i++;
	}
}

/*
** The buckets will need to be scanned to see if any new collision type buckets
** got created.
**
** This can be implemented later when needed however.
*/

void	unnammed(void)
{
	size_t	i;
	SDLX_collision_bucket	*bucket;
	SDLX_collison			*body;

	bucket = NULL;
	body = NULL;
	while (SDL_TRUE) //scanning_collision_buckets
	{
		i = 0;
		while (i < body->response_amount)
		{
			if (bucket->type == body->response_type[i])
			{
				SDLX_attempt_CollisionBucket(body, bucket);
			}
			i++;
		}
	}
}