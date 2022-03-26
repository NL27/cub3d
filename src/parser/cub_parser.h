/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:00:24 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/25 17:21:59 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

typedef struct s_parser
{
	
}	t_parser;

void	parser(t_map *map, t_reader *reader); // takes the reader & the map as input to output the map layout (calls map put in a loop)

#endif