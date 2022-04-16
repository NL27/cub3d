/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:02:13 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:10:20 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"
#include "map_internal.h"

static void	map_set_rayvars_trick(t_rayvars *vars, t_vec2_and_angle pos,
		t_clip *clip, bool recursive)
{
	vars->recursive = recursive;
	vars->clip = clip;
	vars->x_start = pos.vec.x;
	vars->y_start = pos.vec.y;
	vars->x_pos = (int) pos.vec.x;
	vars->y_pos = (int) pos.vec.y;
	vars->ray_dir_x = cos(pos.angle);
	vars->ray_dir_y = -sin(pos.angle);
	vars->delta_dist_x = fabs(1.0f / vars->ray_dir_x);
	vars->delta_dist_y = fabs(1.0f / vars->ray_dir_y);
}

static void	map_set_rayvars(t_rayvars *vars, t_vec2_and_angle pos,
		t_clip *clip, bool recursive)
{
	map_set_rayvars_trick(vars, pos, clip, recursive);
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (pos.vec.x - vars->x_pos) * vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->x_pos + 1.0f
				- pos.vec.x) * vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (pos.vec.y - vars->y_pos) * vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->y_pos + 1.0f
				- pos.vec.y) * vars->delta_dist_y;
	}
}

static bool	is_hit(t_block block)
{
	return (block == BLOCK_NOTHING || block_is_solid(block));
}

static void	map_raycast_core_trick1(t_rayvars *vars, bool *side)
{
	if (vars->side_dist_x < vars->side_dist_y)
	{
		vars->side_dist_x += vars->delta_dist_x;
		vars->x_pos += vars->step_x;
		*side = false;
	}
	else
	{
		vars->side_dist_y += vars->delta_dist_y;
		vars->y_pos += vars->step_y;
		*side = true;
	}
}

static void	map_raycast_core_trick3(t_hit *hit, t_direction dir)
{
	hit->direction = dir;
	hit->tex_x = 1 - hit->tex_x;
}

static void	map_raycast_core_trick2(t_rayvars *vars, t_hit *hit, bool *side)
{
	if (*side)
	{
		hit->dist = (vars->side_dist_y - vars->delta_dist_y);
		hit->tex_x = hit->dist * vars->ray_dir_x + vars->x_start;
		hit->tex_x = hit->tex_x - (int) hit->tex_x;
		if (vars->step_y < 0)
			hit->direction = D_SOUTH;
		else
			map_raycast_core_trick3(hit, D_NORTH);
	}
	else
	{
		hit->dist = (vars->side_dist_x - vars->delta_dist_x);
		hit->tex_x = hit->dist * vars->ray_dir_y + vars->y_start;
		hit->tex_x = hit->tex_x - (int) hit->tex_x;
		if (vars->step_x < 0)
			map_raycast_core_trick3(hit, D_EAST);
		else
			hit->direction = D_WEST;
	}
}

static bool	map_raycast_core(t_map *map, t_hit *hit, t_rayvars vars)
{
	bool	side;
	int		steps;

	side = false;
	steps = 0;
	while (!(is_hit(map_at(map, vars.x_pos, vars.y_pos)) && !clip_is_clipped(
				vars.clip, vars.x_pos, vars.y_pos)) && steps++ < 50)
	{
		map_raycast_core_trick1(&vars, &side);
	}
	map_raycast_core_trick2(&vars, hit, &side);
	hit->hit_block_x = vars.x_pos;
	hit->hit_block_y = vars.y_pos;
	hit->tex = map_tex_at(map, hit->hit_block_x, hit->hit_block_y,
			hit->direction, vars.recursive);
	return (true);
}

bool	map_raycast(t_map *map, t_vec2_and_angle pos, t_hit *hit,
			t_map_raycast_args *opt_args)
{
	t_rayvars	vars;

	if (opt_args != NULL)
		map_set_rayvars(&vars, pos, opt_args->clip, opt_args->recursive);
	else
		map_set_rayvars(&vars, pos, NULL, false);
	return (map_raycast_core(map, hit, vars));
}
