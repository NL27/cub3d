/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:02:40 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 14:03:29 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_gfx.h"

void	rgb_split(t_rgb rgb, int *r, int *g, int *b)
{
	*b = rgb & 0xff;
	*g = (rgb >> 8) & 0xff;
	*r = (rgb >> 16) & 0xff;
}
