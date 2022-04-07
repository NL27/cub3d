/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:52:16 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 16:53:05 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "utils.h"
#include "stringbuilder/stringbuilder.h"

struct	s_trick
{
	ssize_t		bytes_read;
	ssize_t		current_byte;
};

char	*utils_read_file(char *path)
{
	int				fd;
	char			*result;
	struct s_trick	trick;
	t_stringbuilder	builder;
	char			buffer[128];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	stringbuilder_create(&builder);
	while (1)
	{
		trick.bytes_read = read(fd, buffer, sizeof(buffer));
		trick.current_byte = 0;
		if (trick.bytes_read <= 0)
			break ;
		while (trick.current_byte < trick.bytes_read)
			stringbuilder_append_char(&builder, buffer[trick.current_byte++]);
	}
	result = stringbuilder_finalize(&builder);
	stringbuilder_destroy(&builder);
	return (result);
}
