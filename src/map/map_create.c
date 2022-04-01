/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:33:22 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 19:58:50 by enijakow         ###   ########.fr       */
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
	while (index < 2)
	{
		map->portals[index].x = index + 1;
		map->portals[index].y = 0;
		map->portals[index].dir = D_SOUTH;
		screen_create(&map->portals[index].screen, gfx, 64*5, 64*5);
		screen_put(&map->portals[index].screen, 0, 0, 0xff00ff);
		index++;
	}
	map->portals[0].x = 1;
	map->portals[0].y = 0;
	map->portals[0].dir = D_SOUTH;
	map->portals[1].x = 2;
	map->portals[1].y = 0;
	map->portals[1].dir = D_SOUTH;
}
