/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:37:46 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 14:42:43 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

static int	cub_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

void	map_put(t_map *map, int x, int y, t_block block)
{
	if (!map_check_inbounds(map, x, y))
	{
		if (x < 0 || y < 0 || !map_resize(map, cub_max(map_get_width(map), x + 1), cub_max(map_get_height(map), y + 1)))
			return ;
	}
	map->blocks[x + y * map_get_width(map)] = block;
}
