/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:33:22 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 14:57:19 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

void	map_create(t_map *map)
{
	unsigned int	index;

	map->width = 0;
	map->height = 0;
	map->blocks = NULL;
	index = 0;
	while (index < D_DIRECTION_COUNT)
	{
		map->textures[index] = NULL;
		index++;
	}
}
