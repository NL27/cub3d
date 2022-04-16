/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:09:28 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_vec2	vec_rotate(t_vec2 v, t_fl alpha)
{
	t_vec2	result;

	result.x = v.x * cos(alpha) - v.y * sin(alpha);
	result.y = v.x * sin(alpha) + v.y * cos(alpha);
	return (result);
}

void	map_render_portal(t_map *map, t_screen *screen,
		t_vec2_and_angle view, unsigned int index, bool recursive)
{
	unsigned int		next_index;
	t_vec2_and_angle	pos;
	t_vec2				dist;
	t_vec2				target;
	t_vec2				render_pos;
	t_vec2				mov;
	t_fl				alpha;
	t_fl				beta;
	t_clip				clip;
	t_map_raycast_args	args;

	next_index = (index + 1) % CUB_PORTAL_COUNT;
	if (map->portals[index].dir == D_NORTH
		|| map->portals[index].dir == D_SOUTH)
		alpha = ((3 / 4.0f) * M_PI * 2.0f)
			- direction_as_angle(map->portals[index].dir);
	else
		alpha = ((1 / 4.0f) * M_PI * 2.0f)
			- direction_as_angle(map->portals[index].dir);
	beta = direction_as_angle(map->portals[index].dir)
		- direction_as_angle(map->portals[next_index].dir) + M_PI;
	dist.x = (view.vec.x - (map->portals[index].x + 0.5f));
	dist.y = (view.vec.y - (map->portals[index].y + 0.5f));
	target = vec_rotate(dist, alpha);
	render_pos = vec_rotate(dist, beta);
	mov.x = -0.5f;
	mov.y = 0;
	mov = vec_rotate(mov, -direction_as_angle(map->portals[next_index].dir));
	pos.vec.x = map->portals[next_index].x - mov.x + 0.5f + render_pos.x;
	pos.vec.y = map->portals[next_index].y - mov.y + 0.5f + render_pos.y;
	pos.angle = direction_as_angle(map->portals[next_index].dir);
	clip.direction = map->portals[next_index].dir;
	if (map->portals[next_index].dir == D_NORTH
		|| map->portals[next_index].dir == D_SOUTH)
		clip.limit = map->portals[next_index].y;
	else if (map->portals[next_index].dir == D_EAST
		|| map->portals[next_index].dir == D_WEST)
		clip.limit = map->portals[next_index].x;
	args.clip = &clip;
	args.recursive = recursive;
	screen_render(screen, map, pos, target, &args);
}

void	map_render_portals(t_map *map, t_vec2_and_angle player, bool recursive)
{
	unsigned int		index;
	t_vec2_and_angle	portal_pos;

	(void) player;
	index = 0;
	while (index < CUB_PORTAL_COUNT)
	{
		if (recursive)
		{
			portal_pos.angle = -direction_as_angle(map->portals[index].dir);
			portal_pos.vec.x = map->portals[index].x
				+ cos(portal_pos.angle) * 2 + 0.5f;
			portal_pos.vec.y = map->portals[index].y
				+ sin(portal_pos.angle) * 2 + 0.5f;
			map_render_portal(map, &map->portals[index].screens[recursive],
				portal_pos, index, !recursive);
		}
		else
			map_render_portal(map, &map->portals[index].screens[recursive],
				player, index, !recursive);
		index++;
	}
}
