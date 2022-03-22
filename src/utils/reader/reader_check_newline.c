/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_newline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:23:56 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/22 13:27:11 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

bool	reader_check_newline(t_reader *reader)
{
	if (reader_peek(reader) == '\n')
	{
		reader_advance(reader);
		return (true);
	}
	else
		return (false);
}
