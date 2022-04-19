/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_rayvars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:26:42 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 14:28:23 by nlenoch          ###   ########.fr       */
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

void	map_set_rayvars(t_rayvars *vars, t_vec2_and_angle pos,
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

bool	is_hit(t_block block)
{
	return (block == BLOCK_NOTHING || block_is_solid(block));
}
