/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_skip_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:24 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/07 16:23:53 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

unsigned int	reader_skip_whitespace(t_reader *reader)
{
	unsigned int	spaces;

	spaces = 0;
	while (1)
	{
		if (reader_peek(reader) == ' ')
			spaces++;
		else if (reader_peek(reader) == '\t')
			spaces += 4;
		else
			break ;
		reader_advance(reader);
	}
	return (spaces);
}
