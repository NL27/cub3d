/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:29:04 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/22 13:34:36 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

bool	reader_check_empty_line(t_reader *reader)
{
	reader_skip_whitespace(reader);
	return (reader_check_newline(reader));
}
