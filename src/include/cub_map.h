/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:28:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 14:41:42 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_ext.h"
#include "../include/cub_math.h"

typedef enum e_block
{
	BLOCK_NOTHING,
	BLOCK_AIR,
	BLOCK_WALL
}	t_block;

bool	block_is_solid(t_block block);

typedef struct s_map
{
	int		width;
	int		height;
	t_block	*blocks;
}	t_map;

bool	map_check_inbounds(t_map *map, int x, int y);
bool	map_resize(t_map *map, int w, int h);

void	map_create(t_map *map);
void	map_destroy(t_map *map);

int		map_get_width(t_map *map);
int		map_get_height(t_map *map);

t_block	map_at(t_map *map, int x, int y);
void	map_put(t_map *map, int x, int y, t_block block);

bool	map_validate(t_map *map);

bool	map_raycast(t_map *map, t_vec2_and_angle pos, t_vec2i *hit);
