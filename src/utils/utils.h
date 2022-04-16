/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:38:37 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 14:25:35 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

struct	s_trick
{
	ssize_t		bytes_read;
	ssize_t		current_byte;
};

void	utils_memcpy(void *dst, void *src, size_t size);
char	*utils_read_file(char *path);

#endif
