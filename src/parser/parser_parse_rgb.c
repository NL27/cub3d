/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:02:23 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/28 18:15:40 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_rgb(t_parser *parser, t_rgb *rgb)
{
	unsigned int	result_r;
	unsigned int	result_g;
	unsigned int	result_b;
	
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, &result_r))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, ","))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, &result_g))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, ","))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_read_uint(parser->reader, &result_b))
		return (false);
	reader_skip_whitespace(parser->reader);
	if (!reader_peeks(parser->reader, "\n"))
		return (false);
	// TODO: Range checks (0..255)
	*rgb = rgb_create((int) result_r, (int) result_g, (int) result_b);
	return (true);
}
