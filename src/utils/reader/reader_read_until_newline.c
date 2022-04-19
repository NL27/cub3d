/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_until_newline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:41:58 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 13:42:34 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "reader.h"
#include "../stringbuilder/stringbuilder.h"

bool	reader_read_until_newline(t_reader *reader, char **str)
{
	char			c;
	t_stringbuilder	sb;

	stringbuilder_create(&sb);
	while (!reader_check_newline(reader))
	{
		c = reader_read(reader);
		if (c != ' ' && c != '\t')
			stringbuilder_append_char(&sb, c);
	}
	*str = stringbuilder_finalize(&sb);
	stringbuilder_destroy(&sb);
	return (*str != NULL);
}
