/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:27:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 18:05:32 by nlenoch          ###   ########.fr       */
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
		t_vec2_and_angle view, t_map_portal_args p)
{
	unsigned int		next_index;
	t_map_portal_vars	v;

	next_index = (p.index + 1) % CUB_PORTAL_COUNT;
	if (map->portals[p.index].dir == D_NORTH
		|| map->portals[p.index].dir == D_SOUTH)
		v.alpha = ((3 / 4.0f) * M_PI * 2.0f)
			- direction_as_angle(map->portals[p.index].dir);
	else
		v.alpha = ((1 / 4.0f) * M_PI * 2.0f)
			- direction_as_angle(map->portals[p.index].dir);
	v.beta = direction_as_angle(map->portals[p.index].dir)
		- direction_as_angle(map->portals[next_index].dir) + M_PI;
	v.dist.x = (view.vec.x - (map->portals[p.index].x + 0.5f));
	v.dist.y = (view.vec.y - (map->portals[p.index].y + 0.5f));
	v.target = vec_rotate(v.dist, v.alpha);
	v.render_pos = vec_rotate(v.dist, v.beta);
	v.mov.x = -0.5f;
	v.mov.y = 0;
	v.mov = vec_rotate(v.mov, -direction_as_angle(map->portals[next_index].dir));
	v.pos.vec.x = map->portals[next_index].x - v.mov.x + 0.5f + v.render_pos.x;
	v.pos.vec.y = map->portals[next_index].y - v.mov.y + 0.5f + v.render_pos.y;
	v.pos.angle = direction_as_angle(map->portals[next_index].dir);
	v.clip.direction = map->portals[next_index].dir;
	if (map->portals[next_index].dir == D_NORTH
		|| map->portals[next_index].dir == D_SOUTH)
		v.clip.limit = map->portals[next_index].y;
	else if (map->portals[next_index].dir == D_EAST
		|| map->portals[next_index].dir == D_WEST)
		v.clip.limit = map->portals[next_index].x;
	v.args.clip = &v.clip;
	v.args.recursive = p.recursive;
	screen_render(screen, map, v.pos,
		(struct s_screen_render_args){v.target, &v.args});
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
				portal_pos, (t_map_portal_args){index, !recursive});
		}
		else
			map_render_portal(map, &map->portals[index].screens[recursive],
				player, (t_map_portal_args){index, !recursive});
		index++;
	}
}
