/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:33 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 14:11:18 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cub_exit(t_cub *cub);

static void	cub_toggle_mouse(t_cub *cub)
{
	mlx_mouse_get_pos(cub->gfx.window,
		&cub->mouse.old_x, &cub->mouse.old_y);
	cub->mouse_locked = !cub->mouse_locked;
}

void	cub_keyup(int key, t_cub *cub)
{
	if (key == 13)
		cub->keys.w = false;
	if (key == 1)
		cub->keys.s = false;
	if (key == 0)
		cub->keys.a = false;
	if (key == 2)
		cub->keys.d = false;
	if (key == 126)
		cub->keys.up = false;
	if (key == 125)
		cub->keys.down = false;
	if (key == 123)
		cub->keys.left = false;
	if (key == 124)
		cub->keys.right = false;
	if (key == 48)
		cub->map_displayed = !cub->map_displayed;
	if (key == 46)
		cub_toggle_mouse(cub);
	if (key == 14)
		cub_shoot_portal(cub);
	if (key == 53)
		cub_exit(cub);
}
