/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:10:30 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 14:58:52 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub_gfx.h"

t_rgb	tex_at(t_tex *tex, t_fl x, t_fl y)
{
	if (tex == NULL)
		return (rgb_create(x * 255, 0, y * 255));
	return (screen_at((t_screen *) tex, (int)(x
			* screen_get_width((t_screen *) tex)),
		(int)(y * screen_get_height((t_screen*) tex))));
}
