/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_header.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:30 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/02 15:49:18 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

bool	parser_parse_config_header(t_parser *parser, int *x)
{
	t_rgb	rgb;
	
	while (reader_has_more(parser->reader))
	{
		*x = reader_skip_whitespace(parser->reader);
		if (reader_peeks(parser->reader, "\n"))
			; // Do nothing
		else if (reader_peeks(parser->reader, "EA"))
			parser_parse_texture(parser->reader, parser->map->textures[0]);
		else if (reader_peeks(parser->reader, "NO"))
			parser_parse_texture(parser->reader, parser->map->textures[1]);
		else if (reader_peeks(parser->reader, "WE"))
			parser_parse_texture(parser->reader, parser->map->textures[2]);
		else if (reader_peeks(parser->reader, "SO"))
			parser_parse_texture(parser->reader, parser->map->textures[3]);
		else if (reader_peeks(parser->reader, "F"))
		{
			if (parser_parse_rgb(parser->reader, &rgb))
				// TODO: Set floor color with rgb values
				parser_parse_heaven_hell(&rgb, parser, parser->map->textures[4]);
			else
				return (false);
		}
		else if (reader_peeks(parser->reader, "C"))
		{
			if (parser_parse_rgb(parser->reader, &rgb))
				// TODO: Set ceiling color with rgb values
				parser_parse_heaven_hell(&rgb, parser, parser->map->textures[5]);
			else
				return (false);
		}
		else
			break ;
	}
}

void	parser_parse_heaven_hell(t_rgb *rgb, t_parser *parser, t_map *texture[D_DIRECTION_COUNT])
{
	parser->map->textures[D_DIRECTION_COUNT] = rgb;
}

void	parser_parse_texture(t_parser *parser, t_map *texture[D_DIRECTION_COUNT])
{
	char	*str;
	
	reader_skip_whitespace(parser->reader);
	reader_read_until_newline(parser->reader, &str);
	// TODO: Set eastern texture to the texture
	if (reader_peekc(parser->reader, '.'))
	{
		while (!reader_peekc(parser->reader, ' ') || !reader_peekc(parser->reader, '\t') || !reader_peekc(parser->reader, '\0') || !reader_peekc(parser->reader, '\n'))
		{
			parser->map->textures[D_DIRECTION_COUNT] = reader_read(parser->reader);
			reader_advance(parser->reader);
		}
	}
}

// void	parser_parse_texture_north(t_parser *parser, t_map *texture[1])
// {
// 	reader_skip_whitespace(parser->reader);
// 	reader_read_until_newline(parser->reader, &str);
// 	// TODO: Set northern texture to the texture
// 	if (reader_peekc(parser->reader, '.'))
// 	{
// 		while (!reader_peekc(parser->reader, ' ') || !reader_peekc(parser->reader, '\t') || !reader_peekc(parser->reader, '\0') || !reader_peekc(parser->reader, '\n'))
// 		{
// 			*texture[1] = reader_read(parser->reader);
// 			reader_advance(parser->reader);
// 		}
// 	}
// }

// void	parser_parse_texture_west(t_parser *parser, t_map *texture[2])
// {
// 	reader_skip_whitespace(parser->reader);
// 	reader_read_until_newline(parser->reader, &str);
// 	// TODO: Set western texture to the texture
// 	if (reader_peekc(parser->reader, '.'))
// 	{
// 		while (!reader_peekc(parser->reader, ' ') || !reader_peekc(parser->reader, '\t') || !reader_peekc(parser->reader, '\0') || !reader_peekc(parser->reader, '\n'))
// 		{
// 			*texture[2] = reader_read(parser->reader);
// 			reader_advance(parser->reader);
// 		}
// 	}
// }

// void	parser_parse_texture_south(t_parser *parser, t_map *texture[3])
// {
// 	reader_skip_whitespace(parser->reader);
// 	reader_read_until_newline(parser->reader, &str);
// 	// TODO: Set southern texture to the texture
// 	if (reader_peekc(parser->reader, '.'))
// 	{
// 		while (!reader_peekc(parser->reader, ' ') || !reader_peekc(parser->reader, '\t') || !reader_peekc(parser->reader, '\0') || !reader_peekc(parser->reader, '\n'))
// 		{
// 			*texture[3] = reader_read(parser->reader);
// 			reader_advance(parser->reader);
// 		}
// 	}
// }
