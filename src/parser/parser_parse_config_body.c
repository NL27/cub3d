/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_body.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:04:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/02 16:23:46 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config_body(t_parser *parser, int x)
{
	int		y;
	t_cub	cub;
	
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
			map_put(parser->map, x++, y, BLOCK_AIR);
			// TODO: Set spawn position and direction
			map_spawn(cub, x, y, 'N');
		}
		else if (reader_peeks(parser->reader, "S"))
		{
			map_put(parser->map, x++, y, BLOCK_AIR);
			// TODO: Set spawn position and direction
			map_spawn(cub, x, y, 'S');
		}
		else if (reader_peeks(parser->reader, "E"))
		{
			map_put(parser->map, x++, y, BLOCK_AIR);
			// TODO: Set spawn position and direction
			map_spawn(cub, x, y, 'E');
		}
		else if (reader_peeks(parser->reader, "W"))
		{
			map_put(parser->map, x++, y, BLOCK_AIR);
			// TODO: Set spawn position and direction
			map_spawn(cub, x, y, 'W');
		}
		else
			return (false);
	}
}

typedef struct s_cub
{
	t_vec2_and_angle	pos;
}	t_cub;

void	map_spawn(t_cub cub, int x, int y, char c)
{
	cub.pos.vec.x = x;
	cub.pos.vec.y = y;
	if (c == 'N')
		cub.pos.angle = M_PI / 2;
	else if (c == 'S')
		cub.pos.angle = M_PI * 2;
	else if (c == 'E')
		cub.pos.angle = 0;
	else if (c == 'W')
		cub.pos.angle = M_PI;
}
