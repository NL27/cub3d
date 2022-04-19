/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config_header.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:30 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/19 14:48:39 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

void	parser_parse_texture_trick(bool *result, t_screen *screen)
{
	*result = false;
	free(screen);
}

bool	parser_parse_texture(t_parser *parser, t_tex **texture, bool *result)
{
	char		*path;
	t_screen	*screen;

	reader_skip_whitespace(parser->reader);
	path = NULL;
	if (reader_read_until_newline(parser->reader, &path))
	{
		if (*texture != NULL)
		{
			screen_destroy(*texture);
			free(*texture);
			*texture = NULL;
		}
		screen = malloc(sizeof(t_screen));
		if (screen != NULL)
		{
			if (screen_create_from_image(screen, parser->gfx, path))
				*texture = screen;
			else
				parser_parse_texture_trick(result, screen);
		}
	}
	if (path != NULL)
		free(path);
	return (true);
}

bool	parser_parse_config_header_trick(t_parser *parser, bool *result)
{
	t_rgb	rgb;

	*result = true;
	if (reader_peeks(parser->reader, "F"))
	{
		*result = parser_parse_rgb(parser, &rgb);
		if (*result)
			map_set_color(parser->map, 0, rgb);
	}
	else if (reader_peeks(parser->reader, "C"))
	{
		*result = parser_parse_rgb(parser, &rgb);
		if (*result)
			map_set_color(parser->map, 1, rgb);
	}
	else
		return (false);
	return (true);
}

bool	parser_parse_config_header(t_parser *parser, int *x)
{
	bool	r;

	r = true;
	while (reader_has_more(parser->reader))
	{
		*x = reader_skip_whitespace(parser->reader);
		if (reader_peeks(parser->reader, "\n"))
			;
		else if (reader_peeks(parser->reader, "EA"))
			parser_parse_texture(parser, &parser->map->textures[D_EAST], &r);
		else if (reader_peeks(parser->reader, "NO"))
			parser_parse_texture(parser, &parser->map->textures[D_NORTH], &r);
		else if (reader_peeks(parser->reader, "WE"))
			parser_parse_texture(parser, &parser->map->textures[D_WEST], &r);
		else if (reader_peeks(parser->reader, "SO"))
			parser_parse_texture(parser, &parser->map->textures[D_SOUTH], &r);
		else if (parser_parse_config_header_trick(parser, &r))
			;
		else
			break ;
		if (!r)
			return (false);
	}
	return (r);
}
