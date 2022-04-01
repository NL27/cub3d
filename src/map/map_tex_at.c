/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tex_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:05:44 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 14:58:39 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_tex	*map_tex_at(t_map *map, int x, int y, enum e_direction dir)
{
	(void) x;
	(void) y;
	return (map->textures[dir]);
}
