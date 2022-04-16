/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:22:58 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:14:04 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MATH_H
# define CUB_MATH_H

# include "cub_ext.h"

typedef float	t_fl;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec2
{
	t_fl	x;
	t_fl	y;
}	t_vec2;

typedef struct s_vec2_and_angle
{
	t_vec2	vec;
	t_fl	angle;
}	t_vec2_and_angle;

typedef enum e_direction
{
	D_EAST = 0,
	D_NORTH,
	D_WEST,
	D_SOUTH,
	D_FLOOR,
	D_CEILING,
	D_DIRECTION_COUNT
}	t_direction;

t_fl		direction_as_angle(t_direction dir);
t_direction	angle_as_direction(t_fl angle);

typedef struct s_clip
{
	t_direction	direction;
	int			limit;
}	t_clip;

bool		clip_is_clipped(t_clip *clip, int x, int y);

typedef struct s_map_raycast_args
{
	t_clip	*clip;
	bool	recursive;
}	t_map_raycast_args;

typedef struct s_screen_render_args
{
	t_vec2				plane_dist;
	t_map_raycast_args	*map_args;
}	t_screen_render_args;

#endif
