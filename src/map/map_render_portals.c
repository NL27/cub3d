/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 18:48:43 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_render_portals(t_map *map, t_vec2_and_angle player)
{
	unsigned int		index;
	t_vec2_and_angle	pos;
	t_vec2				dist;
	t_fl				alpha;
	t_clip				clip;
	
	(void) player;
	index = 0;
	while (index < 2)
	{
		alpha = direction_as_angle(map->portals[!index].dir) - direction_as_angle(map->portals[index].dir) + M_PI;
		dist.x = (player.vec.x - (map->portals[index].x + 0.5f));
		dist.y = (player.vec.y - (map->portals[index].y + 0.5f));
		pos.vec.x = dist.x * cos(alpha) - dist.y * sin(alpha);
		pos.vec.y = dist.x * sin(alpha) + dist.y * cos(alpha);
		pos.vec.x += map->portals[!index].x;
		pos.vec.y += map->portals[!index].y;
		pos.angle = direction_as_angle(map->portals[!index].dir);
		clip.direction = map->portals[!index].dir;
		if (map->portals[!index].dir == D_NORTH || map->portals[!index].dir == D_SOUTH)
			clip.limit = map->portals[!index].y;
		else if (map->portals[!index].dir == D_EAST || map->portals[!index].dir == D_WEST)
			clip.limit = map->portals[!index].x;
		screen_render(&map->portals[index].screen, map, pos, &clip);
		index++;
	}
}
