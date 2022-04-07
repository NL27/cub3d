/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_header.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:30 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 16:40:44 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

/*
void	parser_parse_heaven_hell(t_rgb *rgb, t_parser *parser)
{
	parser->map->textures[D_DIRECTION_COUNT] = rgb;
}
*/

void	parser_parse_texture(t_parser *parser, t_tex **texture)
{
	char	*str;
	
	(void) texture;
	reader_skip_whitespace(parser->reader);
	reader_read_until_newline(parser->reader, &str);	// What if there are spaces after this?
	// while (!reader_peekc(parser->reader, ' ') || !reader_peekc(parser->reader, '\t') || !reader_peekc(parser->reader, '\0') || !reader_peekc(parser->reader, '\n'))
	// {
	// 	parser->map->textures[D_DIRECTION_COUNT] = reader_read(parser->reader);
	// 	reader_advance(parser->reader);
	// }

	// TODO: Actually load the texture ;)
}

bool	parser_parse_config_header(t_parser *parser, int *x)
{
	t_rgb	rgb;
	
	while (reader_has_more(parser->reader))
	{
		*x = reader_skip_whitespace(parser->reader);
		if (reader_peeks(parser->reader, "\n"))
			; // Do nothing
		else if (reader_peeks(parser->reader, "EA"))
			parser_parse_texture(parser, &parser->map->textures[D_EAST]);
		else if (reader_peeks(parser->reader, "NO"))
			parser_parse_texture(parser, &parser->map->textures[D_NORTH]);
		else if (reader_peeks(parser->reader, "WE"))
			parser_parse_texture(parser, &parser->map->textures[D_WEST]);
		else if (reader_peeks(parser->reader, "SO"))
			parser_parse_texture(parser, &parser->map->textures[D_SOUTH]);
		else if (reader_peeks(parser->reader, "F"))
		{
			printf("Reached F!\n");
			if (parser_parse_rgb(parser, &rgb))
				// TODO: Set floor color with rgb values
				;
			else
				return (false);
		}
		else if (reader_peeks(parser->reader, "C"))
		{
			printf("Reached C!\n");
			if (parser_parse_rgb(parser, &rgb))
				// TODO: Set ceiling color with rgb values
				;
			else
				return (false);
		}
		else
			break ;
	}
	printf("True!\n");
	return (true);
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
