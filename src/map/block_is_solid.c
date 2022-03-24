/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_is_solid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:20:50 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 14:21:16 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

bool	block_is_solid(t_block block)
{
	return (block == BLOCK_WALL);
}
