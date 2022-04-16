/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:23:37 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:24:57 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_H
# define STRINGBUILDER_H

typedef struct s_stringbuilder
{
	unsigned int	write_head;
	unsigned int	buffer_size;
	char			*buffer;
}	t_stringbuilder;

void	stringbuilder_create(t_stringbuilder *sb);
void	stringbuilder_destroy(t_stringbuilder *sb);

void	stringbuilder_append_char(t_stringbuilder *sb, char c);
void	stringbuilder_append_str(t_stringbuilder *sb, char *str);
char	*stringbuilder_finalize(t_stringbuilder *sb);

#endif
