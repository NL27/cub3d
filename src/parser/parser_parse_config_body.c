/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_body.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:04:15 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:32:10 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static void	parser_body_trick(t_map *map, int *x, int *y, t_direction d)
{
	map_set_spawn(map, *x, *y, d);
	map_put(map, (*x)++, *y, BLOCK_AIR);
}

bool	parser_body_trick2(t_parser *parser, int *x, int *y)
{
	if (reader_peeks(parser->reader, "N"))
		parser_body_trick(parser->map, &x, &y, D_NORTH);
	else if (reader_peeks(parser->reader, "S"))
		parser_body_trick(parser->map, &x, &y, D_SOUTH);
	else if (reader_peeks(parser->reader, "E"))
		parser_body_trick(parser->map, &x, &y, D_EAST);
	else if (reader_peeks(parser->reader, "W"))
		parser_body_trick(parser->map, &x, &y, D_WEST);
	else
		return (false);
	return (true);
}

bool	parser_parse_config_body(t_parser *parser, int x)
{
	int		y;

	y = 0;
	while (reader_has_more(parser->reader))
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
			map_put(parser->map, x++, y, BLOCK_AIR);
		else if (reader_peeks(parser->reader, "1"))
			map_put(parser->map, x++, y, BLOCK_WALL);
		else if (parser_body_trick2(parser, &x, &y))
			;
		else
			reader_advance(parser->reader);
	}
	return (true);
}
