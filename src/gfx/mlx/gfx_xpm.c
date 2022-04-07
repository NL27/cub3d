/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:23:10 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/06 12:29:43 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_xpm(t_gfx *gfx, char *filename, t_screen *screen)
{
	filename = path;
	
	mlx_xpm_file_to_image(gfx->mlx, filename, screen->width, screen->height);
	// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
}
