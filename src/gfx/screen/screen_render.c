/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:35:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 17:35:07 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

void	screen_draw_slice(t_screen *screen, int x, int yup, int ydown, t_fl x_fact, t_tex *tex)
{
	int			y;
	t_fl		y_fact;

	y = 0;
	while (y < (int) screen_get_height(screen))
	{
		if (y >= yup && y <= ydown)
		{
			y_fact = (y - yup) / (t_fl) (ydown - yup);
			screen_put(screen, (unsigned int) x, (unsigned int) y, tex_at(tex, x_fact, y_fact));
		}
		else
			screen_put(screen, (unsigned int) x, (unsigned int) y, RGB_BLACK);
		y = y + 1;
	}
}

void	screen_render(t_screen *screen, t_map *map, t_vec2_and_angle pos, t_fl clip)
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
		map_raycast(map, pos, &hit, clip);
		// TODO, FIXME, XXX: hit.dist being zero!
		hit.dist = hit.dist;
		wall_height = (1 / (hit.dist)) * screen_get_height(screen) / cos(((x / (t_fl) screen_get_width(screen)) - 0.5f) * fov);
		screen_draw_slice(screen, x, screen_get_height(screen) / 2 - wall_height / 2, screen_get_height(screen) / 2 + wall_height / 2, hit.tex_x, hit.tex);
		x = x + 1;
	}
}
