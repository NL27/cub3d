/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_shoot_portal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:41 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 17:03:36 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/cub_map.h"

void	cub_shoot_portal(t_cub *cub)
{
	t_hit				hit;
	t_portal			*portal;
	static unsigned int	pnum = 0;

	map_raycast(&cub->map, cub->pos, &hit, NULL);
	portal = &cub->map.portals[pnum];
	pnum = (pnum + 1) % CUB_PORTAL_COUNT;
	portal->x = hit.hit_block_x;
	portal->y = hit.hit_block_y;
	portal->dir = hit.direction;
}
