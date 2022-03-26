/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_skip_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:24 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/26 15:00:55 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	reader_skip_whitespace(t_reader *reader)
{
	while (reader_peek(*reader) == ' ' || reader_peek(*reader) == '\t')
		reader_advance(reader);
}
