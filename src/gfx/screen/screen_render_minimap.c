/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:02:17 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 15:16:29 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

void	screen_render_minimap(t_screen *screen, t_map *map,
		t_vec2_and_angle pos)
{
	const int	size = 10;
	const int	range = 25;
	int			dx;
	int			dy;
	t_fl		flx;
	t_fl		fly;

	flx = pos.vec.x - (int) pos.vec.x;
	fly = pos.vec.y - (int) pos.vec.y;
	dy = -range;
	while (dy <= range)
	{
		dx = -range;
		while (dx <= range)
		{
			if (map_at(map, pos.vec.x + dx, pos.vec.y + dy) == BLOCK_WALL)
			{
				screen_draw_rect(screen, (t_vec2i){((dx - flx) * size)
					+ screen_get_width(screen) / 2,
					((dy - fly) * size) + screen_get_height(screen) / 2},
					(t_vec2i){size, size}, RGB_GRAY);
			}
			dx++;
		}
		dy++;
	}
	screen_draw_rect(screen, (t_vec2i){screen_get_width(screen) / 2 - size / 2,
		screen_get_height(screen) / 2 - size / 2},
		(t_vec2i){size, size}, RGB_RED);
}
