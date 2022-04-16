/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keydown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:28 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 15:22:30 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cub_keydown(int key, t_cub *cub)
{
	if (key == 13)
		cub->keys.w = true;
	if (key == 1)
		cub->keys.s = true;
	if (key == 0)
		cub->keys.a = true;
	if (key == 2)
		cub->keys.d = true;
	if (key == 126)
		cub->keys.up = true;
	if (key == 125)
		cub->keys.down = true;
	if (key == 123)
		cub->keys.left = true;
	if (key == 124)
		cub->keys.right = true;
}
