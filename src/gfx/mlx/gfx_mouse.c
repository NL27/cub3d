/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:34:21 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/03 14:01:24 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_mouse(t_cub cub, int x, int y)
{
	y = 0;
	mlx_mouse_hide();
	mlx_mouse_move(cub->screen, x, y);
	mlx_mouse_get_pos(cub->screen, x, y);
	// y is not needed as only the rotation on the x achsis is needed
}
