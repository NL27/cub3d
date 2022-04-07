/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:00:24 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/07 14:00:08 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

# include "../include/cub_map.h"
# include "../utils/reader/reader.h"

typedef struct s_parser
{
	t_reader	*reader;
	t_map		*map;
}	t_parser;

bool	parser_reader(char *configuration, t_map *map);

void	parser_create(t_parser *parser, t_map *map, t_reader *reader);
void	parser_destroy(t_parser *parser);

bool	parser_parse_config(t_parser *parser);

#endif
