#include "../include/cub.h"
#include "../include/cub_map.h"

void	cub_shoot_portal(t_cub *cub)
{
	t_hit		hit;
	t_portal	*portal;
	static unsigned int	pnum = 0;

	map_raycast(&cub->map, cub->pos, &hit, NULL, false);
	portal = &cub->map.portals[pnum];
	pnum = (pnum + 1) % CUB_PORTAL_COUNT;
	portal->x = hit.hit_block_x;
	portal->y = hit.hit_block_y;
	portal->dir = hit.direction;
}
