/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:35:33 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/28 18:14:30 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "reader.h"

bool	reader_read_uint(t_reader *reader, unsigned int *result)
{
	unsigned long	value;

	value = 0;
	while (reader_has_more(reader))
	{
		if (!is_digit(reader_peek(reader)))
			break ;
		value = 10 * value + reader_peek(reader) - '0';
		if (value > INT_MAX)
			return (false);
		reader_advance(reader);
	}
	*result = (unsigned int) value;
	return (true);
}
