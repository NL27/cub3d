/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:29:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:30:53 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_create_from_image(t_screen *screen, t_gfx *gfx, char *path)
{
	screen->mlx = gfx->mlx;
	screen->image = mlx_png_file_to_image(gfx->mlx, path,
			&screen->width, &screen->height);
	// TODO: Handle NULL
	screen->pixel_base = mlx_get_data_addr(screen->image, &screen->bpp,
			&screen->line_len, &screen->endian);
}

void	screen_create(t_screen *screen, t_gfx *gfx, int width, int height)
{
	int	x;
	int	y;

	screen->height = height;
	screen->width = width;
	screen->mlx = gfx->mlx;
	screen->image = mlx_new_image(screen->mlx, width, height);
	screen->pixel_base = mlx_get_data_addr(screen->image, &screen->bpp,
			&screen->line_len, &screen->endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			screen_put(screen, x, y, rgb_create((int)((x / (t_fl)width) * 256),
					0, (int)((y / (t_fl)height) * 256)));
			x++;
		}
		y++;
	}
}
