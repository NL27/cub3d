/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:09:28 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/07 14:46:53 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config(t_parser *parser)
{
	int	x;

	return (parser_parse_config_header(parser, &x)
			&& parser_parse_config_body(parser, x));
}

void	parser_destroy(t_parser *parser)
{
	if (parser->map != NULL)
		free(parser->map);
	if (parser->reader != NULL)
		free(parser->reader);
}

void	parser_create(t_parser *parser, t_map *map, t_reader *reader)
{
	parser->map = map;
	parser->reader = reader;
}



/*

   F	37       ,100,0

NO       ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA     ./path_to_east_texture





C	37   ,     30    ,    0






		1111111111111111111111111       111     
		1000000000110000000000001       101
		1011000001110000000000001       111
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
1111111111111111111111



   111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N01
11110111 1110101 101111010001
11111111 1111111 111111111111
*/