/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:58:25 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/07 17:15:17 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_set_spawn(t_map *map, int x, int y, t_direction dir)
{
	map->spawn.vec.x = x + 0.5;
	map->spawn.vec.y = y + 0.5;
	map->spawn.angle = direction_as_angle(dir);
	map->spawnpoints_defined++;
}
