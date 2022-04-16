/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:08:04 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

void	screen_draw_slice(t_screen *screen, t_map *map, int x, int yup,
		int ydown, t_fl x_fact, t_tex *tex)
{
	int			y;
	t_fl		y_fact;

	y = 0;
	while (y < (int) screen_get_height(screen))
	{
		if (y >= yup && y <= ydown)
		{
			y_fact = (y - yup) / (t_fl)(ydown - yup);
			screen_put(screen, (unsigned int) x, (unsigned int) y,
				tex_at(tex, x_fact, y_fact));
		}
		else
			screen_put(screen, (unsigned int) x, (unsigned int) y,
				map_get_color(map, y < ((int) screen_get_height(screen) / 2)));
		y = y + 1;
	}
}

void	screen_render(t_screen *screen, t_map *map, t_vec2_and_angle pos,
		t_vec2 plane_dist, t_map_raycast_args *args)
{
	unsigned int		x;
	unsigned int		wall_height;
	t_fl				player_angle;
	t_fl				fov_angle;
	t_hit				hit;

	player_angle = pos.angle;
	x = 0;
	while (x < screen_get_width(screen))
	{
		fov_angle = atan2(plane_dist.x - ((x / (t_fl)
						screen_get_width(screen)) - 0.5f), plane_dist.y);
		pos.angle = player_angle + fov_angle;
		map_raycast(map, pos, &hit, args);
		// TODO, FIXME, XXX: hit.dist being zero!
		hit.dist = hit.dist;
		wall_height = (1 / (hit.dist)) * screen_get_height(screen)
			/ cos(fov_angle) * plane_dist.y;
		screen_draw_slice(screen, map, x, screen_get_height(screen) / 2
			- wall_height / 2, screen_get_height(screen)
			/ 2 + wall_height / 2, hit.tex_x, hit.tex);
		x = x + 1;
	}
}
