/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:08:41 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 11:07:17 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "cub_ext.h"
# include "cub_gfx.h"
# include "cub_map.h"

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_cub
{
	t_gfx				gfx;
	t_screen			screen;
	t_map				map;
	t_vec2_and_angle	pos;
	t_keys				keys;
	bool				map_displayed;
}	t_cub;

void	cub_create(t_cub *cub);
void	cub_destroy(t_cub *cub);

void	cub_tick(t_cub *cub);
void	cub_keyup(int key, t_cub *cub);
void	cub_keydown(int key, t_cub *cub);

void	cub_shoot_portal(t_cub *cub);

#endif
