/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouse_rl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:28:45 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 12:12:08 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cub_mouse_rl(int x, int y, t_cub *cub)
{
	// printf("X %d\n", x);
	(void) y;
	cub->mouse.old_x = x;
	mlx_mouse_get_pos(cub->gfx.window, &cub->mouse.new_x, &cub->mouse.new_y); //
	if (cub->mouse.new_x > cub->mouse.old_x)
	{
		cub->mouse.right = true;
		cub->mouse.left = false;
	}
	else if (cub->mouse.new_x < cub->mouse.old_x)
	{
		cub->mouse.left = true;
		cub->mouse.right = false;
	}
	else if (cub->mouse.new_x == cub->mouse.old_x)
	{
		cub->mouse.left = false;
		cub->mouse.right = false;
	}
}
