/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 13:23:53 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

void	screen_draw_slice(t_screen *screen, t_vec2_and_angle pos, t_fl x_fisheye, int x, int yup, int ydown, t_fl x_fact, t_rgb color)
{
	const t_fl	fov = 45.0f * (M_PI / 180.0f);
	int			y;
	t_fl		y_fact;
	t_fl		y_angle;
	t_fl		dist;
	t_fl		floor_x;
	t_fl		floor_y;

	(void) x_fact;
	y = 0;
	while (y < (int) screen_get_height(screen))
	{
		if (y >= yup && y <= ydown)
		{
			y_fact = (y - yup) / (t_fl) (ydown - yup);
			//screen_put(screen, (unsigned int) x, (unsigned int) y, rgb_create((int) (0xff * x_fact), 0x00, (int) (0xff * y_fact)));
			screen_put(screen, (unsigned int) x, (unsigned int) y, color);
		}
		else
		{
			//screen_put(screen, (unsigned int) x, (unsigned int) y, RGB_BLACK);
			y_angle = ((y / (t_fl) screen_get_height(screen)) - 0.5f) * fov;
			dist = (tan(y_angle + M_PI / 2) * 0.5 / x_fisheye);
			if (y >= (int) screen_get_height(screen) / 2)
			{
				floor_x = cos(pos.angle) * dist - pos.vec.x;
				floor_y = -sin(pos.angle) * dist - pos.vec.y;
			}
			t_fl floor_x2 = floor_x;
			t_fl floor_y2 = floor_y;
			floor_x = floorf(floor_x);
			floor_y = floorf(floor_y);
			screen_put(screen, (unsigned int) x, (unsigned int) y, rgb_create(fabs(floor_x2) * 255, 0, fabs(floor_y2) * 255));
		}
		y = y + 1;
	}
}

void	screen_render(t_screen *screen, t_map *map, t_vec2_and_angle pos)
{
	const t_fl		fov = 60 * (M_PI / 180.0f);
	unsigned int	x;
	unsigned int	wall_height;
	t_fl			angle;
	t_hit			hit;

	angle = pos.angle;
	x = 0;
	while (x < screen_get_width(screen))
	{
		pos.angle = angle - ((x / (t_fl) screen_get_width(screen)) - 0.5f) * fov;
		map_raycast(map, pos, &hit);
		// TODO, FIXME, XXX: hit.dist being zero!
		hit.dist = hit.dist;
		wall_height = (1 / (hit.dist)) * screen_get_height(screen) / cos(((x / (t_fl) screen_get_width(screen)) - 0.5f) * fov);
		screen_draw_slice(screen, pos, cos(((x / (t_fl) screen_get_width(screen)) - 0.5f) * fov), x, screen_get_height(screen) / 2 - wall_height / 2, screen_get_height(screen) / 2 + wall_height / 2, hit.tex_x, ((hit.hit_block_x % 2) == (hit.hit_block_y % 2)) ? RGB_GRAY : RGB_WHITE);
		x = x + 1;
	}
}
