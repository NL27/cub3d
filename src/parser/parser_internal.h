/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:59:55 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/28 18:01:47 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

#include "../include/cub_parser.h"
#include "../include/cub_gfx.h"

bool	parser_parse_rgb(t_parser *parser, t_rgb *rgb);
bool	parser_parse_config_header(t_parser *parser, int *x);
bool	parser_parse_config_body(t_parser *parser, int x);

#endif
