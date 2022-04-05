/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tex_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:05:44 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/05 18:12:41 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_tex	*map_tex_at(t_map *map, int x, int y, enum e_direction dir)
{
	unsigned int	index;

	index = 0;
	while (index < CUB_PORTAL_COUNT)
	{
		if (x == map->portals[index].x && y == map->portals[index].y && dir == map->portals[index].dir)
			return (&map->portals[index].screen);
		index++;
	}
	return (map->textures[dir]);
}
