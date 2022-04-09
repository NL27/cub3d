/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:33:22 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 13:50:40 by enijakow         ###   ########.fr       */
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
	}
}
