/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:22:58 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 14:49:17 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MATH_H
# define CUB_MATH_H

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

#endif
