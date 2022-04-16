/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_set_tick_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:44:01 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 15:21:55 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_set_tick_function(t_gfx *gfx, void (*f)(void*), void *value)
{
	mlx_loop_hook(gfx->mlx, (int (*)()) f, value);
}
