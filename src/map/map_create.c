/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:33:22 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 16:54:14 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_create(t_map *map, t_gfx *gfx)
{
	unsigned int	index;

	map->width = 0;
	map->height = 0;
	map->blocks = NULL;
	index = 0;
	while (index < D_DIRECTION_COUNT)
	{
		map->textures[index] = NULL;
		index++;
	}
	index = 0;
	while (index < CUB_PORTAL_COUNT)
	{
		// Put the portals into negative space
		map->portals[index].x = -1;
		map->portals[index].y = -1;
		map->portals[index].dir = D_SOUTH;
		screen_create(&map->portals[index].screens[0], gfx, 64*5, 64*5);
		screen_create(&map->portals[index].screens[1], gfx, 64*5, 64*5);
		index++;
	}
}
