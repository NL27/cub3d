/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:28:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 13:53:34 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_ext.h"

typedef enum e_block
{
	BLOCK_NOTHING,
	BLOCK_AIR,
	BLOCK_WALL
}	t_block;

bool	block_is_solid(t_block block);

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	t_block			*blocks;
}	t_map;

void	map_create(t_map *map);
void	map_destroy(t_map *map);

unsigned int	map_get_width(t_map *map);
unsigned int	map_get_height(t_map *map);

bool	map_check_inbounds(t_map *map, unsigned int x, unsigned int y);

void	map_resize(t_map *map, unsigned int w, unsigned int h);

t_block	map_at(t_map *map, unsigned int x, unsigned int y);
void	map_put(t_map *map, unsigned int x, unsigned int y, t_block block);
