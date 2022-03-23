/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:17:16 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 14:46:35 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

bool	map_validate_block(t_map *map, int x, int y)
{
	int	dx;
	int	dy;

	if (map_at(map, x, y) == BLOCK_AIR)
	{
		dx = -1;
		while (dx <= 1)
		{
			dy = -1;
			while (dy <= 1)
			{
				if (map_at(map, x + dx, y + dy) == BLOCK_NOTHING)
					return (false);
				dy++;
			}
			dx++;
		}
	}
	return (true);
}

bool	map_validate(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_get_height(map))
	{
		x = 0;
		while (x < map_get_width(map))
		{
			if (!map_validate_block(map, x, y))
				return (false);
			x = x + 1;
		}
		y = y + 1;
	}
	return (true);
}
