/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 18:10:42 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_render_portals(t_map *map, t_vec2_and_angle player)
{
	t_screen			*screen;
	unsigned int		index;
	t_vec2_and_angle	pos;
	t_vec2				dist;
	t_fl				alpha;
	
	(void) player;
	index = 0;
	while (index < 2)
	{
		screen = &map->portals[index].screen;
		// TODO: Add the direction of the other portal
		//pos.angle = -atan2(player.vec.y - map->portals[index].y, player.vec.x - map->portals[index].x) + direction_as_angle(map->portals[!index].dir) - direction_as_angle(map->portals[index].dir);
		alpha = direction_as_angle(map->portals[!index].dir) - direction_as_angle(map->portals[index].dir);
		dist.x = (player.vec.x - map->portals[index].x + 0.5f);
		dist.y = (player.vec.y - map->portals[index].y + 0.5f);
		pos.angle = direction_as_angle(map->portals[!index].dir);
		pos.vec.x = -(dist.x * cos(alpha) - dist.y * sin(alpha));
		pos.vec.y = dist.x * sin(alpha) + dist.y * cos(alpha);
		pos.vec.x += map->portals[!index].x;
		pos.vec.y += map->portals[!index].y;
		screen_render(screen, map, pos, sqrt(dist.x * dist.x + dist.y * dist.y) + 0.55);
		index++;
	}
}
