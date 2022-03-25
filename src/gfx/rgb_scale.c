/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:00:37 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 14:06:40 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_gfx.h"

static int	cub_imin(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

t_rgb	rgb_scale(t_rgb rgb, t_fl scale)
{
	int	r;
	int	g;
	int	b;

	if (scale < 0)
		scale = 0;
	else if (scale > 1)
		scale = 1;
	rgb_split(rgb, &r, &g, &b);
	return (rgb_create(cub_imin(r * scale, 0xff), cub_imin(g * scale, 0xff), cub_imin(b * scale, 0xff)));
}
