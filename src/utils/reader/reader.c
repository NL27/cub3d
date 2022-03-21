/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:23:20 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/21 14:24:46 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	reader_create_on_string(t_reader *reader, char *str)
{
	*reader = str;
}

bool	reader_has_more(t_reader *reader)
{
	return (reader_peek(reader) != '/0');
}

void	reader_advance(t_reader *reader)
{
	(*reader)++;
}

char	reader_peek(t_reader *reader)
{
	return (**reader);
}

char	reader_read(t_reader *reader)
{
	char	character;

	character = reader_peek(reader);
	reader_advance(reader);
	return (character);
}
