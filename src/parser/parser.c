/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:09:28 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 14:39:48 by nlenoch          ###   ########.fr       */
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
	(void) parser;
}

void	parser_create(t_parser *parser, t_gfx *gfx,
		t_map *map, t_reader *reader)
{
	parser->gfx = gfx;
	parser->map = map;
	parser->reader = reader;
}
