/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 19:56:26 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_vec2	vec_rotate(t_vec2 v, t_fl alpha)
{
	t_vec2	result;

	printf("%f\n", (alpha / (2 * M_PI)) * 360);

	result.x = v.x * cos(alpha) - v.y * sin(alpha);
	result.y = v.x * sin(alpha) + v.y * cos(alpha);

	return (result);
}

void	map_render_portals(t_map *map, t_vec2_and_angle player)
{
	unsigned int		index;
	t_vec2_and_angle	pos;
	t_vec2				dist;
	t_vec2				target;
	t_vec2				render_pos;
	t_vec2				mov;
	t_fl				alpha;
	t_fl				beta;
	t_clip				clip;
	
	(void) player;
	index = 0;
	while (index < 2)
	{
		alpha = -direction_as_angle(map->portals[index].dir) + (3 / 4.0f) * M_PI * 2.0f;
		beta = direction_as_angle(map->portals[index].dir) - direction_as_angle(map->portals[!index].dir) + M_PI;
		dist.x = (player.vec.x - (map->portals[index].x + 0.5f));
		dist.y = (player.vec.y - (map->portals[index].y + 0.5f));
		target = vec_rotate(dist, alpha);
		render_pos = vec_rotate(dist, beta);
		mov.x = 1;
		mov.y = 0;
		mov = vec_rotate(mov, -direction_as_angle(map->portals[index].dir));
		pos.vec.x = map->portals[!index].x + mov.x + 0.5f + render_pos.x;
		pos.vec.y = map->portals[!index].y + mov.y + render_pos.y;
		pos.angle = direction_as_angle(map->portals[!index].dir);
		clip.direction = map->portals[!index].dir;
		if (map->portals[!index].dir == D_NORTH || map->portals[!index].dir == D_SOUTH)
			clip.limit = map->portals[!index].y;
		else if (map->portals[!index].dir == D_EAST || map->portals[!index].dir == D_WEST)
			clip.limit = map->portals[!index].x;
		//target.x = (player.vec.x - (map->portals[index].x + 0.5f)) / 2.0f;
		//target.y = (player.vec.y - (map->portals[index].y + 0.5f)) / 2.0f;
		screen_render(&map->portals[index].screen, map, pos, &clip, target);
		index++;
	}
}
