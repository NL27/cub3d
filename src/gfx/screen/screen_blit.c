/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_blit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:07:13 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 14:35:30 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_blit(t_screen *screen, t_gfx *gfx)
{
	mlx_put_image_to_window(screen->mlx, gfx->window, screen->image, 0, 0);	
}
