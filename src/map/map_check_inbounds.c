/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_inbounds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:51:43 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 13:53:06 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

bool	map_check_inbounds(t_map *map, unsigned int x, unsigned int y)
{
	return ((x >= 0) && (y >= 0)
			&& (x < map_get_width(map)) && (y < map_get_height(map)));
}
