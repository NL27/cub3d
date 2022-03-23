/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:37:46 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 14:10:52 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_put(t_map *map, unsigned int x, unsigned int y, t_block block)
{
	if (!map_check_inbounds(map, x, y))
	{
		if (!map_resize(map, x + 1, y + 1))
			return ;
	}
	map->blocks[x + y * map_get_width(map)] = block;
}
