/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:02:13 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 14:25:12 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"
#include "map_internal.h"

static void	map_set_rayvars(t_rayvars *vars, t_vec2_and_angle pos)
{
	vars->x_start = pos.vec.x;
	vars->y_start = pos.vec.y;
	vars->x_pos = (int) pos.vec.x;
	vars->y_pos = (int) pos.vec.y;
	vars->ray_dir_x = cos(pos.angle);
	vars->ray_dir_y = -sin(pos.angle);
	vars->delta_dist_x = fabs(1.0f / vars->ray_dir_x);
	vars->delta_dist_y = fabs(1.0f / vars->ray_dir_y);
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (pos.vec.x - vars->x_pos) * vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->x_pos + 1.0f - pos.vec.x) * vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (pos.vec.y - vars->y_pos) * vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->y_pos + 1.0f - pos.vec.y) * vars->delta_dist_y;
	}
}

static bool	is_hit(t_block block)
{
	return (block == BLOCK_NOTHING || block_is_solid(block));
}

static bool	map_raycast_core(t_map *map, t_hit *hit, t_rayvars vars)
{
	bool	side;
	
	side = false;
	while (!is_hit(map_at(map, vars.x_pos, vars.y_pos)))
	{
		if (vars.side_dist_x < vars.side_dist_y)
		{
			vars.side_dist_x += vars.delta_dist_x;
			vars.x_pos += vars.step_x;
			side = false;
		}
		else
		{
			vars.side_dist_y += vars.delta_dist_y;
			vars.y_pos += vars.step_y;
			side = true;
		}
	}
	if (side)
	{
		hit->dist = (vars.side_dist_y - vars.delta_dist_y);
		hit->tex_x = hit->dist * vars.ray_dir_x;
	}
	else
	{
		hit->dist = (vars.side_dist_x - vars.delta_dist_x);
		hit->tex_x = hit->dist * vars.ray_dir_y;
	}
	hit->tex_x = hit->tex_x - floorf(hit->tex_x);
	hit->hit_block_x = vars.x_pos;
	hit->hit_block_y = vars.y_pos;
	return (true);
}

bool	map_raycast(t_map *map, t_vec2_and_angle pos, t_hit *hit)
{
	t_rayvars	vars;

	map_set_rayvars(&vars, pos);
	return (map_raycast_core(map, hit, vars));
}
