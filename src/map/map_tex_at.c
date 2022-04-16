/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tex_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:05:44 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:49:19 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_tex	*map_tex_at(t_map *map, int x, int y,
		enum e_direction dir, bool recursive)
{
	unsigned int	index;

	(void) recursive;
	index = 0;
	while (index < CUB_PORTAL_COUNT)
	{
		if (x == map->portals[index].x && y == map->portals[index].y
			&& dir == map->portals[index].dir)
			return (&map->portals[index].screens[recursive]);
		index++;
	}
	return (map->textures[dir]);
}
