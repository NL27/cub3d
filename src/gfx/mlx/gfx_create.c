/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:58:32 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/01 11:52:56 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	gfx_create(t_gfx *gfx)
{
	gfx->mlx = mlx_init(); //must be the first function called on failure returns NULL
	if (gfx->mlx == NULL)
		printf("MLX INIT ERROR!");
}
