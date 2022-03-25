/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:07:43 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 14:08:23 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INTERNAL_H
# define MAP_INTERNAL_H

# include "../include/cub_map.h"

typedef struct s_rayvars
{
	t_fl	x_start;
	t_fl	y_start;
	int		x_pos;
	int		y_pos;
	int		step_x;
	int		step_y;
	t_fl	ray_dir_x;
	t_fl	ray_dir_y;
	t_fl	side_dist_x;
	t_fl	side_dist_y;
	t_fl	delta_dist_x;
	t_fl	delta_dist_y;
}	t_rayvars;

#endif
