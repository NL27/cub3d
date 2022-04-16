/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:33:22 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 16:42:13 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_destroy(t_map *map)
{
	unsigned int	index;

	if (map->blocks != NULL)
		free(map->blocks);
	index = 0;
	while (index < D_DIRECTION_COUNT)
	{
		if (map->textures[index] != NULL)
		{
			screen_destroy(map->textures[index]);
			free(map->textures[index]);
		}
		index++;
	}
	index = 0;
	while (index < CUB_PORTAL_COUNT)
	{
		screen_destroy(&map->portals[index].screens[0]);
		screen_destroy(&map->portals[index].screens[1]);
		index++;
	}
}
