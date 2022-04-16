/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:22:06 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 14:22:09 by nlenoch          ###   ########.fr       */
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

void	cub_create(t_cub *cub)
{
	cub->map_displayed = false;
	cub->should_exit = false;
	keys_create(&cub->keys);
	gfx_create(&cub->gfx, 800, 600);
	screen_create(&cub->screen, &cub->gfx, 800, 600);
	map_create(&cub->map, &cub->gfx);
	gfx_set_tick_function(&cub->gfx, (void *) cub_tick, cub);
	gfx_keys(&cub->gfx, (void *) cub_keydown, (void *) cub_keyup, cub);
	// if (cub->should_exit)
	// 	cub_destroy(cub);
}
