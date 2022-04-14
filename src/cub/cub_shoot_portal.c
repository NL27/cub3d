#include "../include/cub.h"
#include "../include/cub_map.h"

void	cub_shoot_portal(t_cub *cub)
{
	t_hit	hit;

	map_raycast(&cub->map, cub->pos, &hit, NULL, false);
	printf("%d %d\n", hit.hit_block_x, hit.hit_block_y);
}
