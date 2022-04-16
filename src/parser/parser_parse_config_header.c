/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_header.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:30 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:35:09 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	parser_parse_texture(t_parser *parser, t_tex **texture)
{
	char		*path;
	t_screen	*screen;

	(void) texture;
	reader_skip_whitespace(parser->reader);
	path = NULL;
	if (reader_read_until_newline(parser->reader, &path))
	{
		// TODO, FIXME, XXX: What if the texture is to be parsed twice? -> Leak!
		screen = malloc(sizeof(t_screen));
		if (screen != NULL)
		{
			screen_create_from_image(screen, parser->gfx, path);
			*texture = screen;
		}
	}
	if (path != NULL)
		free(path);
}

bool	parser_parse_config_header_trick(t_parser *parser)
{
	t_rgb	rgb;

	if (reader_peeks(parser->reader, "F"))
	{
		if (parser_parse_rgb(parser, &rgb))
			map_set_color(parser->map, 0, rgb);
		else
			return (false);
	}
	else if (reader_peeks(parser->reader, "C"))
	{
		if (parser_parse_rgb(parser, &rgb))
			map_set_color(parser->map, 1, rgb);
		else
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	parser_parse_config_header(t_parser *parser, int *x)
{
	while (reader_has_more(parser->reader))
	{
		*x = reader_skip_whitespace(parser->reader);
		if (reader_peeks(parser->reader, "\n"))
			;
		else if (reader_peeks(parser->reader, "EA"))
			parser_parse_texture(parser, &parser->map->textures[D_EAST]);
		else if (reader_peeks(parser->reader, "NO"))
			parser_parse_texture(parser, &parser->map->textures[D_NORTH]);
		else if (reader_peeks(parser->reader, "WE"))
			parser_parse_texture(parser, &parser->map->textures[D_WEST]);
		else if (reader_peeks(parser->reader, "SO"))
			parser_parse_texture(parser, &parser->map->textures[D_SOUTH]);
		else if (parser_parse_config_header_trick(parser))
			;
		else
			break ;
	}
	return (true);
}
