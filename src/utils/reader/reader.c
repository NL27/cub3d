/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:23:20 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/19 14:23:54 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	reader_create_on_string(t_reader *reader, char *str)
{
	*reader = str;
}

void	reader_destroy(t_reader *reader)
{
	(void) reader;
}
