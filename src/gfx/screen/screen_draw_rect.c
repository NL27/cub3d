/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:00:39 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 15:00:41 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_draw_rect(t_screen *screen, t_vec2i pos, t_vec2i wh, t_rgb color)
{
	int	x;
	int	y;

	y = 0;
	while (y < wh.x)
	{
		x = 0;
		while (x < wh.y)
		{
			screen_put(screen, x + pos.x, y + pos.y, color);
			x++;
		}
		y++;
	}
}
