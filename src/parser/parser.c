/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:09:28 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/28 17:55:34 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_parser.h"
#include "../include/cub_gfx.h"


bool	parser_parse_rgb(t_reader *reader, t_rgb *rgb)
{
	int		result_r;
	int		result_g;
	int		result_b;
	
	reader_skip_whitespace(reader);
	if (!reader_read_int(reader, &result_r))
		return (false);
	reader_skip_whitespace(reader);
	if (!reader_peeks(reader, ","))
		return (false);
	reader_skip_whitespace(reader);
	if (!reader_read_int(reader, &result_g))
		return (false);
	reader_skip_whitespace(reader);
	if (!reader_peeks(reader, ","))
		return (false);
	reader_skip_whitespace(reader);
	if (!reader_read_int(reader, &result_b))
		return (false);
	reader_skip_whitespace(reader);
	if (!reader_peeks(reader, "\n"))
		return (false);
	*rgb = rgb_create(result_r, result_g, result_b);
	return (true);
}

bool parser_parse_config_header(t_parser *parser, int *x)
{
	char	*str;
	t_rgb	color;
	
	while (reader_has_more(parser->reader))
	{
		*x = reader_skip_whitespace(parser->reader);
		if (reader_peeks(parser->reader, "\n"))
			; // Do nothing
		else if (reader_peeks(parser->reader, "NO"))
		{
			reader_skip_whitespace(parser->reader);
			reader_read_until_newline(parser->reader, &str);
			// TODO: Set northern texture to the texture
		}
		// TODO: et cetera
		else if (reader_peeks(parser->reader, "F"))
		{
			if (parser_parse_color(parser->reader, &color))
				// TODO: Set floor color
				;
			else
				return (false);
			
		}
		else if (reader_peeks(parser->reader, "C"))
		{
			if (parser_parse_color(parser->reader, &color))
				// TODO: Set ceiling color
				;
			else
				return (false);
			
		}
		else
			break ;
	}
}

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

bool	parser_parse_config(t_parser *parser)
{
	int		x;

	return (parser_parse_config_header(parser, &x)
			&& parser_parse_config_body(parser, x));
}


/*

   F	37       ,100,0

NO       ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

C	37   ,     30    ,    0
		1111111111111111111111111
		1000000000110000000000001
		1011000001110000000000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001    NO
10000000000000001101010010001
11000001110101011111011110N01
11110111 1110101 101111010001
11111111 1111111 111111111111
*/