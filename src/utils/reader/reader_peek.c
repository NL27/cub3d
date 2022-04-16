/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:04:43 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 14:22:57 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

bool	reader_peekc(t_reader *reader, char c)
{
	return (reader_peek(reader) == c);
}

bool	reader_peeks(t_reader *reader, char *prefix)
{
	char	*tmp;

	tmp = *reader;
	while (*prefix != '\0')
	{
		if (*prefix != reader_read(reader))
		{
			*reader = tmp;
			return (false);
		}
		prefix++;
	}
	return (true);
}
