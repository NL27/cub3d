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

static void	cub_tick_trick_on_track(t_cub *cub, t_fl speed)
{
	if (cub->keys.w || cub->keys.up)
		cub_move(&cub->map, &cub->pos, cos(cub->pos.angle) * 0.02 * speed,
			-sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.s || cub->keys.down)
		cub_move(&cub->map, &cub->pos, -cos(cub->pos.angle) * 0.02 * speed,
			sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.a)
		cub_move(&cub->map, &cub->pos, -sin(cub->pos.angle) * 0.02 * speed,
			-cos(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.d)
		cub_move(&cub->map, &cub->pos, sin(cub->pos.angle) * 0.02 * speed,
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
