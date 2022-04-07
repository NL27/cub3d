/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:25:11 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/06 12:30:25 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_png(t_gfx *gfx, char *filename, t_screen *screen)
{
	filename = path;
	
	mlx_png_file_to_image(gfx->mlx, filename, screen->width, screen->height);
	// void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
}
