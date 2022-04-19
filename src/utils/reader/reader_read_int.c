/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:35:33 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 13:41:03 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "reader.h"

static bool	is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

bool	reader_read_uint(t_reader *reader, unsigned int *result)
{
	unsigned long	value;
	unsigned int	nr;

	nr = 0;
	value = 0;
	while (reader_has_more(reader))
	{
		if (!is_digit(reader_peek(reader)))
			break ;
		value = 10 * value + reader_peek(reader) - '0';
		nr++;
		if (value > INT_MAX)
			return (false);
		reader_advance(reader);
	}
	*result = (unsigned int) value;
	return (nr > 0);
}
