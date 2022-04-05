/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:55:56 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/05 15:00:04 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_keys(t_gfx* gfx, void (*press)(int, void*), void (*release)(int, void*), void *param)
{
	mlx_hook(gfx->window, 2, 0, (int (*)()) press, param);
	mlx_hook(gfx->window, 3, 0, (int (*)()) release, param);
}

/*
W_KEY = 87;
A_KEY = 65;
S_KEY = 83;
D_KEY = 68;
ESC_KEY = 27;
LEFT_KEY = 37;
RIGHT_KEY = 39;

void gfx_movements(keycode)
{
	if (keycode == W_KEY)
		move_forward;
	else if (keycode == S_KEY)
		move_backwards;
	else if (keycode == A_KEY)
		move_left;
	else if (keycode == D_KEY)
		move_right;
	else if (keycode == LEFT_KEY)
		rotate_view_left;
	else if (keycode == RIGHT_KEY)
		rotate_view_right;
	else if (keycode == ESC_KEY)
		exit_window;
}
*/
