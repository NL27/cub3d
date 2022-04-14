#include "../include/cub.h"

void	cub_destroy(t_cub *cub)
{
	map_destroy(&cub->map);
	screen_destroy(&cub->screen);
	gfx_destroy(&cub->gfx);
}
