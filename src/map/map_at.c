/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:36:35 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 14:28:28 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_block	map_at(t_map *map, int x, int y)
{
	if (!map_check_inbounds(map, x, y))
		return (BLOCK_NOTHING);
	return (map->blocks[x + y * map_get_width(map)]);
}
