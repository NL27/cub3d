/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:23:38 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 14:24:33 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

bool	reader_has_more(t_reader *reader)
{
	return (reader_peek(reader) != '\0');
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
