/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:58:16 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 12:28:27 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_put(t_screen *screen, unsigned int x, unsigned int y, t_rgb color)
{
	if (x >= 0 && y >= 0 && x < screen_get_width(screen) && y < screen_get_height(screen))
		*((t_rgb *) (screen->pixel_base + (y * screen->line_len + x * (screen->bpp / 8)))) = color;
}
