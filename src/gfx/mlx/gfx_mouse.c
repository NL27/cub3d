/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:34:21 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 11:55:28 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_mouse(t_gfx *gfx, void (*mouse_rl)(int, int, void*), void *param)
{
	mlx_hook(gfx->window, 6, 0, (int (*)()) mouse_rl, param); //
}
