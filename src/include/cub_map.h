/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:28:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 14:58:27 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_H
# define CUB_MAP_H

# include "../include/cub_ext.h"
# include "../include/cub_math.h"
# include "../include/cub_gfx.h"

typedef enum e_block
{
	BLOCK_NOTHING,
	BLOCK_AIR,
	BLOCK_WALL
}	t_block;

bool	block_is_solid(t_block block);

typedef enum e_direction
{
	D_NORTH = 0,
	D_SOUTH = 1,
	D_EAST = 2,
	D_WEST = 3,
	D_DIRECTION_COUNT
}	t_direction;

typedef struct s_map
{
	t_tex	*textures[D_DIRECTION_COUNT];
	int		width;
	int		height;
	t_block	*blocks;
}	t_map;

typedef struct s_hit
{
	t_fl	dist;
	int		hit_block_x;
	int		hit_block_y;
	t_fl	tex_x;
	t_tex	*tex;
}	t_hit;

bool	map_check_inbounds(t_map *map, int x, int y);
bool	map_resize(t_map *map, int w, int h);

void	map_create(t_map *map);
void	map_destroy(t_map *map);

int		map_get_width(t_map *map);
int		map_get_height(t_map *map);

t_block	map_at(t_map *map, int x, int y);
void	map_put(t_map *map, int x, int y, t_block block);

t_tex	*map_tex_at(t_map *map, int x, int y, enum e_direction dir);

bool	map_validate(t_map *map);

bool	map_raycast(t_map *map, t_vec2_and_angle pos, t_hit *hit);

#endif
