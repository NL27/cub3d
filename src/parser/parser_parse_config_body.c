/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_body.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:04:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/28 18:04:35 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config_body(t_parser *parser, int x)
{
	int	y;
	
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
			// TODO: Set spawn position and direction
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "S"))
		{
			// TODO: Set spawn position and direction
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "E"))
		{
			// TODO: Set spawn position and direction
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(parser->reader, "W"))
		{
			// TODO: Set spawn position and direction
			map_put(parser->map, x++, y, BLOCK_AIR);
		}
		else
			return (false);
	}
}
