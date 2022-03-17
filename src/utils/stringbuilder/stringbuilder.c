/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:29:53 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/17 14:46:28 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../utils.h"

#include "stringbuilder.h"

void	stringbuilder_create(t_stringbuilder *sb)
{
	sb->write_head = 0;
	sb->buffer_size = 128;
	sb->buffer = malloc(128 * sizeof(char));
}

void	stringbuilder_destroy(t_stringbuilder *sb)
{
	if (sb->buffer != NULL)
		free(sb->buffer);
}

void	stringbuilder_append_char(t_stringbuilder *sb, char c)
{
	char	*buf2;

	if (sb->write_head >= sb->buffer_size)
	{
		buf2 = malloc(sizeof(char) * (sb->buffer_size + 128));
		if (buf2 == NULL)
			return ;
		utils_memcpy(buf2, sb->buffer, sb->write_head);
		free(sb->buffer);
		sb->buffer = buf2;
		sb->buffer_size = sb->buffer_size + 128;
	}
	sb->buffer[sb->write_head] = c;
	sb->write_head = sb->write_head + 1;
}

void	stringbuilder_append_str(t_stringbuilder *sb, char *str)
{
	while (*str != '\0')
	{
		stringbuilder_append_char(sb, *str);
		str = str + 1;
	}
}

char	*stringbuilder_finalize(t_stringbuilder *sb)
{
	char	*result;

	result = malloc(sizeof(char) * (sb->write_head + 1));
	if (result != NULL)
	{
		utils_memcpy(result, sb->buffer, sb->write_head);
		result[sb->write_head] = '\0';
	}
	return (result);
}
