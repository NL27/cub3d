/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:22:06 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 11:51:58 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	keys_create(struct s_keys *keys)
{
	keys->w = false;
	keys->s = false;
	keys->a = false;
	keys->d = false;
	keys->up = false;
	keys->down = false;
	keys->left = false;
	keys->right = false;
}

void	mouse_create(struct s_mouse *mouse)
{
	mouse->right = false;
	mouse->left = false;
	mouse->new_x = 0;
	mouse->old_x = 0;
	mouse->new_y = 0;
	mouse->old_y = 0;
}

void	cub_create(t_cub *cub)
{
	cub->map_displayed = false;
	cub->should_exit = false;
	keys_create(&cub->keys);
	mouse_create(&cub->mouse); //
	gfx_create(&cub->gfx, 800, 600);
	screen_create(&cub->screen, &cub->gfx, 800, 600);
	map_create(&cub->map, &cub->gfx);
	gfx_set_tick_function(&cub->gfx, (void *) cub_tick, cub);
	gfx_keys(&cub->gfx, (void *) cub_keydown, (void *) cub_keyup, cub);
	mlx_mouse_get_pos(cub->gfx.window, &cub->mouse.old_x, &cub->mouse.old_y); //
	mlx_hook(cub->gfx.window, 6, 0, (int (*)()) cub_mouse_rl, cub); //
}
