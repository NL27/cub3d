/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:28:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/21 14:32:56 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_block
{
	BLOCK_NOTHING,
	BLOCK_AIR,
	BLOCK_WALL
}	t_block;

bool	block_is_solid(t_block block);

struct s_map
{
}	t_map;

void	map_create(t_map *map);
void	map_destroy(t_map *map);

unsigned int	map_get_width(t_map *map);
unsigned int	map_get_height(t_map *map);

void	map_resize(t_map *map, unsigned int w, unsigned int h);

t_block	map_at(t_map *map, unsigned int x, unsigned int y);
void	map_put(t_map *map, t_block block);
