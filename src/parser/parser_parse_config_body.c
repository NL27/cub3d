/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_body.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:04:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 17:07:02 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config_body(t_parser *parser, int x)
{
	int		y;
	
	y = 0;
	while(reader_has_more(parser->reader))
	{
		if (reader_peeks(parser->reader, " "))
			x++;
		else if (reader_peeks(parser->reader, "\t"))
			x += 4;
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
			map_set_spawn(parser->map, x, y, D_NORTH);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "S"))
		{
			map_set_spawn(parser->map, x, y, D_SOUTH);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "E"))
		{
			map_set_spawn(parser->map, x, y, D_EAST);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "W"))
		{
			map_set_spawn(parser->map, x, y, D_WEST);
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else
			reader_advance(parser->reader);
	}
	return (true);
}
