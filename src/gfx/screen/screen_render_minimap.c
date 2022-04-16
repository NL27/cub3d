/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:02:17 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 17:30:04 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

static void	screen_render_minimap_trick(t_vec2 *fl, int *dy,
		t_vec2_and_angle pos, int range)
{
	fl->x = pos.vec.x - (int) pos.vec.x;
	fl->y = pos.vec.y - (int) pos.vec.y;
	*dy = -range;
}

void	screen_render_minimap(t_screen *screen, t_map *map,
		t_vec2_and_angle pos)
{
	const int	size = 10;
	const int	range = 25;
	t_vec2i		d;
	t_vec2		fl;

	screen_render_minimap_trick(&fl, &d.y, pos, range);
	while (d.y <= range)
	{
		d.x = -range;
		while (d.x <= range)
		{
			if (map_at(map, pos.vec.x + d.x, pos.vec.y + d.y) == BLOCK_WALL)
			{
				screen_draw_rect(screen, (t_vec2i){((d.x - fl.x) * size)
					+ screen_get_width(screen) / 2,
					((d.y - fl.y) * size) + screen_get_height(screen) / 2},
					(t_vec2i){size, size}, RGB_GRAY);
			}
			d.x++;
		}
		d.y++;
	}
	screen_draw_rect(screen, (t_vec2i){screen_get_width(screen) / 2 - size / 2,
		screen_get_height(screen) / 2 - size / 2}, (t_vec2i){size, size},
		RGB_RED);
}
