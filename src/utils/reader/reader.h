/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:32:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/17 17:42:38 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

typedef char *t_reader;

void	reader_create_on_string(t_reader *reader, char *str);
void	reader_destroy(t_reader *reader);

bool	reader_has_more(t_reader *reader);	// *str != '\0'
void	reader_advance(t_reader *reader);	// str++
char	reader_peek(t_reader *reader);		// *str
char	reader_read(t_reader *reader);		// *(str++)   (peek & then advance)

bool	reader_peeks(t_reader *reader, char *prefix);	// Check if prefix occurs, if so, consume it and return true, else leave it and return false
void	reader_skip_whitespace(t_reader *reader);		// Advance while pointing to a whitespace
bool	reader_check_newline(t_reader *reader);	// => reader_peeks(reader, "\n")
bool	reader_check_empty_line(t_reader *reader);	// => { reader_skip_whitespace(reader); reader_check_newline(reader); }

#endif
