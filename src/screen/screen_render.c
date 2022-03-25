/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 12:04:29 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_screen.h"

int		cub_imin(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

t_rgb	rgb_scale(t_rgb color, t_fl scale)
{
	int	r;
	int	g;
	int	b;

	if (scale < 0)
		scale = 0;
	else if (scale > 1)
		scale = 1;

	b = color & 0xff;
	g = (color >> 8) & 0xff;
	r = (color >> 16) & 0xff;

	return (cub_imin((int) (r * scale), 0xff) << 16 | cub_imin((int) (g * scale), 0xff) << 8 | cub_imin((int) (b * scale), 0xff));
}

void	screen_draw_slice(t_screen *screen, int x, int yup, int ydown, t_rgb color)
{
	int	y;

	y = 0;
	while (y < (int) screen_get_height(screen))
	{
		if (y >= yup && y <= ydown)
			screen_put(screen, (unsigned int) x, (unsigned int) y, color);
		else
			screen_put(screen, (unsigned int) x, (unsigned int) y, RGB_BLACK);
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
		hit.dist = hit.dist * cos(((x / (t_fl) screen_get_width(screen)) - 0.5f) * fov);
		wall_height = (1 / hit.dist) * screen_get_height(screen);
		screen_draw_slice(screen, x, screen_get_height(screen) / 2 - wall_height / 2, screen_get_height(screen) / 2 + wall_height / 2, rgb_scale(((hit.hit_block_x % 2) == (hit.hit_block_y % 2)) ? RGB_WHITE : RGB_GRAY, 1 / hit.dist));
		x = x + 1;
	}
}
