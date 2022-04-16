/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:32:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:24:44 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdbool.h>

typedef char	*t_reader;

void			reader_create_on_string(t_reader *reader, char *str);
void			reader_destroy(t_reader *reader);

bool			reader_has_more(t_reader *reader);
void			reader_advance(t_reader *reader);
char			reader_peek(t_reader *reader);
char			reader_read(t_reader *reader);
bool			reader_peekc(t_reader *reader, char c);
bool			reader_peeks(t_reader *reader, char *prefix);
unsigned int	reader_skip_whitespace(t_reader *reader);
bool			reader_check_newline(t_reader *reader);
bool			reader_check_empty_line(t_reader *reader);
bool			reader_read_until_newline(t_reader *reader, char **str);
bool			reader_read_uint(t_reader *reader, unsigned int *result);

#endif
