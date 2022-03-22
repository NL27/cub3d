/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:35:33 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/22 15:32:52 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int	reader_read_int(t_reader *reader, int *result)
{
	while (is_digit(reader) == true)
	{
		result = reader_peek(reader);
		reader_advance(reader);
	}
	return (result);
}
