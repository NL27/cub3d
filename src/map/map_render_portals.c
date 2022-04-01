/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 15:48:14 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_render_portals(t_map *map, t_vec2_and_angle player)
{
	unsigned int		index;
	t_vec2_and_angle	pos;
	
	index = 0;
	while (index < 2)
	{
		// pos.angle = player_angle + (2 / 4.0f) * M_PI * 2;
		pos.angle = -atan2(player.vec.y - map->portals[index].y, player.vec.x - map->portals[index].x);
		pos.vec.x = map->portals[!index].x + cos(pos.angle) * 1.5 + 0.5f;
		pos.vec.y = map->portals[!index].y - sin(pos.angle) * 1.5 + 0.5f;
		screen_render(&map->portals[index].screen, map, pos);
		index++;
	}
}
