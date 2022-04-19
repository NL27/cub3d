/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:58:32 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 12:23:51 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_create(t_gfx *gfx, int width, int height)
{
	gfx->mlx = mlx_init();
	if (gfx->mlx == NULL)
		printf("MLX INIT ERROR!");
	gfx->window = mlx_new_window(gfx->mlx, width, height, "C3");
}
