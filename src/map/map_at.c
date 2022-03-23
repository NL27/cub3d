/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:36:35 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 13:51:33 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_block	map_at(t_map *map, unsigned int x, unsigned int y)
{
	(void) map;
	(void) x;
	(void) y;
	if (x == 0 || y == 0)
		return (BLOCK_WALL);
	return (BLOCK_NOTHING);
}
