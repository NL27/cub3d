/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:02:23 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:38:47 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static bool	range_check(unsigned int i)
{
	return (i >= 0 && i <= 0xff);
}

bool	parser_parse_rgb_trick(t_parser *parser,
								unsigned int *result_r,
								unsigned int *result_g,
								unsigned int *result_b)
{
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, result_r))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, ","))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, result_g))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, ","))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, result_b))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, "\n"))
		return (false);
	return (true);
}

bool	parser_parse_rgb(t_parser *parser, t_rgb *rgb)
{
	unsigned int	result_r;
	unsigned int	result_g;
	unsigned int	result_b;

	if (!parser_parse_rgb_trick(parser, &result_r, &result_g, &result_b))
		return (false);
	if (!range_check(result_r)
		|| !range_check(result_g)
		|| !range_check(result_b))
		return (false);
	*rgb = rgb_create((int) result_r, (int) result_g, (int) result_b);
	return (true);
}
