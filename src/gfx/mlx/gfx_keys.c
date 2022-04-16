/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:55:56 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 15:21:01 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_keys(t_gfx *gfx, void (*press)(int, void*),
	void (*release)(int, void*), void *param)
{
	mlx_hook(gfx->window, 2, 0, (int (*)()) press, param);
	mlx_hook(gfx->window, 3, 0, (int (*)()) release, param);
}
