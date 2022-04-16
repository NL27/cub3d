/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:38:37 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 16:25:56 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

struct	s_trick
{
	size_t		bytes_read;
	size_t		current_byte;
};

void	utils_memcpy(void *dst, void *src, size_t size);
char	*utils_read_file(char *path);

#endif
