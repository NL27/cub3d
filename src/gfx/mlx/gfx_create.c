/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:58:32 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/30 16:52:31 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_create(t_gfx *gfx, int window_witdh, int window_height)
{
	gfx->mlx = mlx_init(); //must be the first function called on failure returns NULL
	if (gfx->mlx == NULL)
		printf("MLX INIT ERROR!");
}
