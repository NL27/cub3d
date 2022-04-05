/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_set_tick_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:44:01 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/05 14:46:10 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_set_tick_function(t_gfx *gfx, void (*f)(void*), void *value)
{
    mlx_loop_hook(gfx->mlx, (int (*)()) f, value);
}
