/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_body.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:04:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 14:33:31 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	map_spawn(t_map *map, int x, int y, t_direction dir)
{
	(void)	map;
	(void)	x;
	(void)	y;
	(void)	dir;
	/*cub.pos.vec.x = x;
	cub.pos.vec.y = y;
	if (c == 'N')
		cub.pos.angle = M_PI / 2;
	else if (c == 'S')
		cub.pos.angle = M_PI * 2;
	else if (c == 'E')
		cub.pos.angle = 0;
	else if (c == 'W')
		cub.pos.angle = M_PI;*/
}

bool	parser_parse_config_body(t_parser *parser, int x)
{
	int		y;
	
	y = 0;
	while(reader_has_more(parser->reader))
	{
		if (reader_peeks(parser->reader, " "))
			x++;
		else if (reader_peeks(parser->reader, "\n"))
		{
			x = 0;
			y++;
		}
		else if (reader_peeks(parser->reader, "0"))
		{
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "1"))
		{
			map_put(parser->map, x++, y, BLOCK_WALL);
		}
		else if (reader_peeks(parser->reader, "N"))
		{
			map_spawn(parser->map, x, y, D_NORTH);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "S"))
		{
			map_spawn(parser->map, x, y, D_SOUTH);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "E"))
		{
			map_spawn(parser->map, x, y, D_EAST);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "W"))
		{
			map_spawn(parser->map, x, y, D_WEST);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else
			return (false);
	}
	return (true);
}
