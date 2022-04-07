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
	while (reader_peek(reader) == ' ' || reader_peek(reader) == '\t')
	{
		reader_advance(reader);
		spaces++;
	}
	return (spaces);
}
