/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:35:52 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 14:08:00 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

bool	map_resize(t_map *map, unsigned int w, unsigned int h)
{
	t_block			*new_blocks;
	unsigned int	xx;
	unsigned int	yy;

	new_blocks = malloc(w * h * sizeof(t_block));
	if (new_blocks != NULL)
	{
		yy = 0;
		while (yy < h)
		{
			xx = 0;
			while (xx < w)
			{
				if (map_check_inbounds(map, xx, yy))
					new_blocks[xx + yy * w] = map->blocks[xx + yy * map_get_width(map)];
				else
					new_blocks[xx + yy * w] = BLOCK_NOTHING;
				xx = xx + 1;
			}
			yy = yy + 1;
		}
		map->width = w;
		map->height = h;
		if (map->blocks != NULL)
			free(map->blocks);
		map->blocks = new_blocks;
	}
	return (new_blocks != NULL);
}
