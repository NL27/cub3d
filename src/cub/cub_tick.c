/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:27:15 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 13:57:10 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static bool	angle_match(t_fl a1, t_fl a2)
{
	return (fabs(atan2(sin(a1 - a2), cos(a1 - a2))) < (M_PI / 4.0f));
}

static void	move_trick1(t_fl x_dir, t_fl y_dir, int *dx, int *dy)
{
	if (x_dir < 0)
		*dx = -1;
	else
		*dx = 1;
	if (y_dir < 0)
		*dy = -1;
	else
		*dy = 1;
}

static void	move_trick2(t_map *map, t_vec2_and_angle *pos, int dx, int dy)
{
	int	c;

	c = 0;
	while (c < CUB_PORTAL_COUNT)
	{
		if ((int)(pos->vec.x + 0.15 * dx) == map->portals[c].x
			&& (int)(pos->vec.y + 0.15 * dy) == map->portals[c].y
			&& angle_match(pos->angle + M_PI,
				direction_as_angle(map->portals[c].dir)))
		{
			c = (c + 1) % CUB_PORTAL_COUNT;
			pos->vec.x = map->portals[c].x
				+ cos(direction_as_angle(map->portals[c].dir)) + 0.5f;
			pos->vec.y = map->portals[c].y
				- sin(direction_as_angle(map->portals[c].dir)) + 0.5f;
			pos->angle = direction_as_angle(map->portals[c].dir);
			return ;
		}
		c++;
	}
}

static void	move(t_map *map, t_vec2_and_angle *pos, t_fl x_dir, t_fl y_dir)
{
	int	dx;
	int	dy;

	move_trick1(x_dir, y_dir, &dx, &dy);
	move_trick2(map, pos, dx, dy);
	if (!block_is_solid(map_at(map,
				(int)(pos->vec.x + 0.1 * dx), (int)pos->vec.y)))
		pos->vec.x += x_dir;
	if (!block_is_solid(map_at(map,
				(int)pos->vec.x, (int)(pos->vec.y + 0.1 * dy))))
		pos->vec.y += y_dir;
}

static void	cub_tick_trick_on_track(t_cub *cub, t_fl speed)
{
	if (cub->keys.w || cub->keys.up)
		move(&cub->map, &cub->pos, cos(cub->pos.angle) * 0.02 * speed,
			-sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.s || cub->keys.down)
		move(&cub->map, &cub->pos, -cos(cub->pos.angle) * 0.02 * speed,
			sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.a)
		move(&cub->map, &cub->pos, -sin(cub->pos.angle) * 0.02 * speed,
			-cos(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.d)
		move(&cub->map, &cub->pos, sin(cub->pos.angle) * 0.02 * speed,
			cos(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.left)
		cub->pos.angle += 0.02 * speed;
	if (cub->keys.right)
		cub->pos.angle -= 0.02 * speed;
}

void	cub_tick(t_cub *cub)
{
	t_vec2				plane;
	t_fl				speed;

	speed = 2;
	cub_tick_trick_on_track(cub, speed);
	map_render_portals(&cub->map, cub->pos, true);
	map_render_portals(&cub->map, cub->pos, false);
	plane.x = 0;
	plane.y = 1;
	screen_render(&cub->screen, &cub->map, cub->pos,
		(struct s_screen_render_args){plane, NULL});
	if (cub->map_displayed)
		screen_render_minimap(&cub->screen, &cub->map, cub->pos);
	screen_blit(&cub->screen, &cub->gfx);
}
