/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouse_rl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:28:45 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 14:13:35 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cub_mouse_rl(int x, int y, t_cub *cub)
{
	(void) x;
	(void) y;
	if (cub->mouse_locked)
	{
		mlx_mouse_get_pos(cub->gfx.window,
			&cub->mouse.new_x, &cub->mouse.new_y);
		mlx_mouse_move(cub->gfx.window, cub->mouse.old_x, cub->mouse.old_y);
		cub->pos.angle -= (t_fl)((cub->mouse.new_x
					- cub->mouse.old_x) / 1500.0f);
	}
}
