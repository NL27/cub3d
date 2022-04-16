/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:28:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 18:14:53 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_H
# define CUB_MAP_H

# include "../include/cub_ext.h"
# include "../include/cub_math.h"
# include "../include/cub_gfx.h"

# define CUB_PORTAL_COUNT 2

typedef enum e_block
{
	BLOCK_NOTHING,
	BLOCK_AIR,
	BLOCK_WALL
}	t_block;

bool	block_is_solid(t_block block);

typedef struct s_portal
{
	int				x;
	int				y;
	t_direction		dir;
	t_screen		screens[2];
}	t_portal;

typedef struct s_map
{
	int					width;
	int					height;
	t_block				*blocks;
	t_vec2_and_angle	spawn;
	unsigned int		spawnpoints_defined;
	t_portal			portals[CUB_PORTAL_COUNT];
	t_tex				*textures[D_DIRECTION_COUNT];
	t_rgb				colors[2];
}	t_map;

typedef struct s_hit
{
	t_fl		dist;
	int			hit_block_x;
	int			hit_block_y;
	t_fl		tex_x;
	t_tex		*tex;
	t_direction	direction;
}	t_hit;

bool	map_check_inbounds(t_map *map, int x, int y);
bool	map_resize(t_map *map, int w, int h);

void	map_create(t_map *map, t_gfx *gfx);
void	map_destroy(t_map *map);

int		map_get_width(t_map *map);
int		map_get_height(t_map *map);

t_block	map_at(t_map *map, int x, int y);
void	map_put(t_map *map, int x, int y, t_block block);

t_tex	*map_tex_at(t_map *map, t_vec2i at,
			enum e_direction dir, bool recursive);
void	map_set_color(t_map *map, unsigned int number, t_rgb color);
t_rgb	map_get_color(t_map *map, unsigned int number);

void	map_set_spawn(t_map *map, int x, int y, t_direction dir);
bool	map_validate(t_map *map);

bool	map_raycast(t_map *map, t_vec2_and_angle pos, t_hit *hit,
			t_map_raycast_args *opt_args);
void	map_render_portals(t_map *map, t_vec2_and_angle player, bool recursive);

typedef struct s_map_portal_vars
{
	t_vec2_and_angle	pos;
	t_vec2				dist;
	t_vec2				target;
	t_vec2				render_pos;
	t_vec2				mov;
	t_fl				alpha;
	t_fl				beta;
	t_clip				clip;
	t_map_raycast_args	args;
	unsigned int		next_index;
}	t_map_portal_vars;

typedef struct s_map_portal_args
{
	unsigned int	index;
	bool			recursive;
}	t_map_portal_args;

#endif
