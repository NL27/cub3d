/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/19 14:21:48 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

void	screen_draw_slice(t_screen *screen, t_map *map,
	t_screen_draw_slice_trick args)
{
	int			y;
	t_fl		y_fact;

	y = 0;
	while (y < (int) screen_get_height(screen))
	{
		if (y >= args.yup && y <= args.ydown)
		{
			y_fact = (y - args.yup) / (t_fl)(args.ydown - args.yup);
			screen_put(screen, (unsigned int) args.x, (unsigned int) y,
				tex_at(args.tex, args.x_fact, y_fact));
		}
		else
			screen_put(screen, (unsigned int) args.x, (unsigned int) y,
				map_get_color(map, y < ((int) screen_get_height(screen) / 2)));
		y = y + 1;
	}
}

void	screen_render(t_screen *screen, t_map *map, t_vec2_and_angle pos,
		t_screen_render_args args)
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
		fov_angle = atan2(args.plane_dist.x - ((x / (t_fl)
						screen_get_width(screen)) - 0.5f), args.plane_dist.y);
		pos.angle = player_angle + fov_angle;
		map_raycast(map, pos, &hit, args.map_args);
		if (hit.dist == 0.0f)
			hit.dist = 0.001f;
		wall_height = (1 / (hit.dist)) * screen_get_height(screen)
			/ cos(fov_angle) * args.plane_dist.y;
		screen_draw_slice(screen, map,
			(t_screen_draw_slice_trick){
			x, screen_get_height(screen) / 2 - wall_height / 2,
			screen_get_height(screen) / 2 + wall_height / 2, hit.tex_x,
			hit.tex});
		x = x + 1;
	}
}
