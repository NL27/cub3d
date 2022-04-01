/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 16:36:19 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_render_portals(t_map *map, t_vec2_and_angle player)
{
	t_screen			*screen;
	unsigned int		index;
	t_vec2_and_angle	pos;
	
	(void) player;
	index = 0;
	while (index < 2)
	{
		screen = &map->portals[index].screen;
		// TODO: Add the direction of the other portal
		//pos.angle = -atan2(player.vec.y - map->portals[index].y, player.vec.x - map->portals[index].x) - direction_as_angle(map->portals[index].dir) + direction_as_angle(map->portals[!index].dir);
		pos.angle = -atan2(player.vec.y - map->portals[index].y, player.vec.x - map->portals[index].x) + direction_as_angle(map->portals[!index].dir) - direction_as_angle(map->portals[index].dir);
		pos.vec.x = map->portals[!index].x + cos(pos.angle) * 1.5 + 0.5f;
		pos.vec.y = map->portals[!index].y - sin(pos.angle) * 1.5 + 0.5f;
		screen_render(screen, map, pos);
		index++;
	}
}
