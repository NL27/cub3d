/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:58:32 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/01 14:33:55 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_create(t_gfx *gfx, int width, int height)
{
	gfx->mlx = mlx_init(); //must be the first function called on failure returns NULL
	if (gfx->mlx == NULL)
		printf("MLX INIT ERROR!");
	gfx->window = mlx_new_window(gfx->mlx, width, height, ":-)");
}
