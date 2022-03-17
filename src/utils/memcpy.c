/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:39:11 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/17 14:40:07 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	utils_memcpy(void *dst, void *src, size_t size)
{
	size_t	s;

	s = 0;
	while (s < size)
	{
		((char *)dst)[s] = ((char *)src)[s];
		s = s + 1;
	}
}
