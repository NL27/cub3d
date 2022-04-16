/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:35:52 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 17:21:22 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

static void	map_resize_trick(t_map *map, int w, int h, t_block *nb)
{
	map->width = w;
	map->height = h;
	map->blocks = nb;
}

bool	map_resize(t_map *map, int w, int h)
{
	t_block	*new_blocks;
	int		xx;
	int		yy;

	if (w < 0 || h < 0)
		return (false);
	new_blocks = malloc(w * h * sizeof(t_block));
	if (new_blocks != NULL)
	{
		yy = 0;
		while (yy < h)
		{
			xx = 0;
			while (xx < w)
			{
				new_blocks[xx + yy * w] = map_at(map, xx, yy);
				xx = xx + 1;
			}
			yy = yy + 1;
		}
		if (map->blocks != NULL)
			free(map->blocks);
		map_resize_trick(map, w, h, new_blocks);
	}
	return (new_blocks != NULL);
}
