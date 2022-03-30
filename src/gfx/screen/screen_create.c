/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:29:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/30 16:51:52 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_create(t_screen *screen, void *mlx_ptr, int width, int height)
{
	screen->height = height;
	screen->width = width;
	screen->mlx = mlx_ptr;
	screen->window = mlx_new_window(mlx_ptr, width, height, ":-)");
	screen->image = mlx_new_image(mlx_ptr, width, height);
	mlx_get_data_addr (screen->image, &screen->bpp, &screen->line_len, screen->endian);
}
