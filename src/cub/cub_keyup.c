/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:33 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 17:50:20 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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
	if (key == 14)
		cub_shoot_portal(cub);
	if (key == 53)
	{
		cub_destroy(cub);
		exit(0);
	}
}
