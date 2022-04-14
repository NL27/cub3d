#include "../include/cub.h"

void	cub_create(t_cub *cub)
{
	cub->keys.w = false;
	cub->keys.s = false;
	cub->keys.a = false;
	cub->keys.d = false;
	cub->keys.up = false;
	cub->keys.down = false;
	cub->keys.left = false;
	cub->keys.right = false;
	gfx_create(&cub->gfx, 800, 600);
	screen_create(&cub->screen, &cub->gfx, 800, 600);
	map_create(&cub->map, &cub->gfx);
	gfx_set_tick_function(&cub->gfx, (void *) cub_tick, cub);
	gfx_keys(&cub->gfx, (void *) cub_keydown, (void *) cub_keyup, cub);
}
