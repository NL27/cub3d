/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:09:28 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/28 17:41:00 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/reader/reader.h"
#include "../include/cub_map.h"

/*
while the file has not reached the end ('\0')

check for empty lines & skip them (advance reader)

check for spaces before the prefixes & skip them
check for the prefixes NO, SO, WE, EA 
check for spaces after the prefixes & skip them
-> do smth (get the path for the textures)
until the new line put everything into a string & check if it is valid

check for spaces before the prefixes & skip them
check for the prefixes F & C 
check for spaces after the prefixes & skip them
-> do smth (get the ints without the commas into r, g, b values)
get the first number & put it into red
until the comma check for spaces after the first number & skip them
until the next number after the first comma check for spaces & skip them
get the second number & put it into green
until the comma check for spaces after the second number & skip them
until the next number after the second comma check for spaces & skip them
get the last number & put it into blue

check if there is nothing else in the map except "1, 0, N, S, E, W" -> validate map
if ' ' -> map_put(BLOCK_NOTHING)
if '1' -> map_put(BLOCK_WALL)
if '0' -> map_put(BLOCK_AIR)
if 'N' || 'S' || 'W' || 'E' -> startpoint direction

// Third Iteration
*/

bool	parser_parse_rgb(t_reader *reader, t_rgb *rgb)
{
	// TODO!
	reader_skip_whitespace(reader);
	result_r = reader_read_int(reader, result_r);
	reader_skip_whitespace(reader);
	if (reader_peekc(reader, ','))
		result_g = reader_read_int(reader, result_g);
	reader_skip_whitespace(reader);
	if (reader_peekc(reader, ',')
		result_b = reader_read_int(reader, result_b);
}

bool parser(t_map *map, t_reader *reader)
{
	char	*str;
	int		*result_r;
	int		*result_g;
	int		*result_b;
	int		x;
	int		y;
	t_rgb	color;

	while (reader_has_more(reader))
	{
		x = reader_skip_whitespace(reader);
		if (reader_peeks(reader, "\n"))
			; // Do nothing
		else if (reader_peeks(reader, "NO"))
		{
			reader_skip_whitespace(reader);
			str = reader_read_until_newline(reader, str);
			// TODO: Set northern texture to the texture
		}
		// TODO: et cetera
		else if (reader_peeks(reader, "F"))
		{
			if (parser_parse_color(reader, &color))
				// TODO: Set floor color
				;
			else
				return (false);
			
		}
		else if (reader_peeks(reader, "C"))
		{
			if (parser_parse_color(reader, &color))
				// TODO: Set ceiling color
				;
			else
				return (false);
			
		}
		else
			break ;
	}
	y = 0;
	while(reader_has_more(reader))
	{
		if (reader_peeks(reader, " "))
			x++;
		else if (reader_peeks(reader, "\n"))
		{
			x = 0;
			y++;
		}
		else if (reader_peeks(reader, "0"))
		{
			map_put(map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(reader, "1"))
		{
			map_put(map, x++, y, BLOCK_WALL);
		}
		else if (reader_peeks(reader, "N"))
		{
			// TODO: Set spawn position and direction
			map_put(map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(reader, "S"))
		{
			// TODO: Set spawn position and direction
			map_put(map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(reader, "E"))
		{
			// TODO: Set spawn position and direction
			map_put(map, x++, y, BLOCK_AIR);
		}
		else if (reader_peeks(reader, "W"))
		{
			// TODO: Set spawn position and direction
			map_put(map, x++, y, BLOCK_AIR);
		}
		else
			return (false);
	}
}

// Second Iteration

// void	parser(t_map *map, t_reader *reader)
// {
// 	char	*str;
// 	int		*result;
	
// 	while (reader != '\0')
// 	{
// 		if (reader == ' ' || reader == '\t' || reader == '\n')	// reader_skip_whitespace(reader) || reader_check_newline(reader);
// 			reader_advance(reader);
// 		if (reader_peeks(reader, NO) || reader_peeks(reader, SO) || reader_peeks(reader, WE) || reader_peeks(reader, EA))
// 		{
// 			reader_skip_whitespace(reader);
// 			while (reader != '\n')	// !check_newline(reader);
// 			{
// 				// str = reader_read(reader);
// 				str = reader_create_on_string(reader, str);
// 			}
// 		}
// 		else if (reader_peekc(reader, F) || reader_peekc(reader, C))
// 		{
// 			reader_skip_whitespace(reader);
// 			while (reader != '\n')
// 			{
// 				if (is_digit(reader))
// 					result = reader_read_int(reader, result);
// 				reader_skip_whitespace(reader);
// 				if (reader == ',')
// 				{
// 					reader_skip_whitespace(reader);
// 					result = reader_read_int(reader, result);
// 				}
// 			}
// 		}
// 		while (map_validate(map))
// 		{
// 			if (reader_peekc(reader, ' '))
// 				map_put(map, x, y, BLOCK_NOTHING);
// 			else if (reader_peekc(reader, '1'))
// 				map_put(map, x, y, BLOCK_WALL);
// 			else if (reader_peekc(reader, '0'))
// 				map_put(map, x, y, BLOCK_AIR);
// 			else if (reader_peekc(reader, N) || reader_peekc(reader, S) || reader_peekc(reader, W) || reader_peekc(reader, E))
// 				// put startpoint;
// 		}
// 	}
// }

// First try

// void	parser(t_map *map, t_reader *reader)
// {
// 	char *str;

// 	while (reader_has_more(reader))
// 	{
// 		if (reader_check_empty_line(reader) == true)
// 			break ;
// 		if (reader_peeks(reader, NO) == true)
// 			reader_create_on_string(reader, str);
// 		if (reader_peeks(reader, SO) == true)
// 			reader_create_on_string(reader, str);
// 		if (reader_peeks(reader, WE) == true)

// 		if (reader_peeks(reader, EA) == true)

// 		if (reader_peekc(reader, F) == true)

// 		if (reader_peekc(reader, C) == true)

// 	}
	
// 	if (map_validate(map) == true)
// 	{
// 	}
	
// }


/*

   F	37       ,100,0

NO       ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

C	37   ,     30    ,    0
		1111111111111111111111111
		1000000000110000000000001
		1011000001110000000000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001    NO
10000000000000001101010010001
11000001110101011111011110N01
11110111 1110101 101111010001
11111111 1111111 111111111111
*/