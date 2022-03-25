/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 14:20:59 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_screen.h"

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
		screen_draw_slice(screen, x, screen_get_height(screen) / 2 - wall_height / 2, screen_get_height(screen) / 2 + wall_height / 2, rgb_scale(((hit.hit_block_x % 2) == (hit.hit_block_y % 2)) ? RGB_WHITE : RGB_GRAY, hit.tex_x));
		x = x + 1;
	}
}
