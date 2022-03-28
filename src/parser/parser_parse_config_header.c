/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_header.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:30 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/28 18:03:58 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config_header(t_parser *parser, int *x)
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
