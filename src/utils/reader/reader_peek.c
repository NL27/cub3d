/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:04:43 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/22 13:35:09 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

bool	reader_peekc(t_reader *reader, char c)
{
	return (reader_peek(**reader) == c);
}

bool	reader_peeks(t_reader *reader, char *prefix)
{
	// while (reader_peekc(reader) == true)
	// 	reader_advance(reader);
	if (reader == prefix)
		return (true);
	return (false);
}
