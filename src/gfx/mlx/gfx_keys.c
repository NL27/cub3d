/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:55:56 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/03 14:14:21 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_keys(t_cub cub, int keycode)
{
	void	*param;

	mlx_key_hook(cub->screen, (*f)(keycode, param), param);
}

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
