/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:29:10 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 14:33:34 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_create(t_screen *screen, t_gfx *gfx, int width, int height)
{
	screen->height = height;
	screen->width = width;
	screen->mlx = gfx->mlx;
	screen->image = mlx_new_image(screen->mlx, width, height);
	screen->pixel_base = mlx_get_data_addr(screen->image, &screen->bpp, &screen->line_len, &screen->endian);
}
