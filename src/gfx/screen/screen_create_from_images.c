/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_create_from_images.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:17:57 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/03 14:42:32 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_create_from_images(t_screen *screen, const char *path)
{
	mlx_xpx_file_to_image(screen->mlx, path, screen->width, screen->height);
	mlx_png_file_to_image(screen->mlx, path, screen->width, screen->height);
}
