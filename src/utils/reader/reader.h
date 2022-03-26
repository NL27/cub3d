/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:32:25 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 17:24:16 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

typedef char *t_reader;

void	reader_create_on_string(t_reader *reader, char *str); //creates a new string 
void	reader_destroy(t_reader *reader);

bool	reader_has_more(t_reader *reader);	// *str != '\0'  -> checks if the char (*reader) of the string is not the NULL character. returns true if it is NOT NULL else returns false
void	reader_advance(t_reader *reader);	// str++		 -> increment the string (*reader) to the next char
char	reader_peek(t_reader *reader);		// *str   		 -> returns char (*reader) of the string at the current position
char	reader_read(t_reader *reader);		// *(str++)   	 -> uses first the peek fct & then the advance fct to read through the string char by char

bool	reader_peekc(t_reader *reader, char c);			// probably not needed as we have string peek
bool	reader_peeks(t_reader *reader, char *prefix);	// Check if prefix occurs, if so, consume it and return true, else leave it and return false
void	reader_skip_whitespace(t_reader *reader);		// Advance while pointing to a whitespace -> uses peek & advance fct in a while loop
bool	reader_check_newline(t_reader *reader);			// => reader_peeks(reader, "\n")	returns false if current char is Not Newline else advance & return true
bool	reader_check_empty_line(t_reader *reader);		// => { reader_skip_whitespace(reader); reader_check_newline(reader); } returns check_newline fct & skips whitespaces

bool	reader_read_int(t_reader *reader, int *result);	// checks for ints and returns the total result

NO MALLOC!!!
NO FREE!!!
NO OTHER FCTS!!!
ONLY THIS!!!!

#endif
