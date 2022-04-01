/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tex_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:05:44 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 15:19:59 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_tex	*map_tex_at(t_map *map, int x, int y, enum e_direction dir)
{
	if (x == map->portals[0].x && y == map->portals[0].y && dir == map->portals[0].dir)
		return (&map->portals[0].screen);
	if (x == map->portals[1].x && y == map->portals[1].y && dir == map->portals[1].dir)
		return (&map->portals[1].screen);
	return (map->textures[dir]);
}
