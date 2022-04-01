/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_is_clipped.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:23:08 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 18:50:07 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_math.h"

bool	clip_is_clipped(t_clip *clip, int x, int y)
{
	if (clip == NULL)
		return (false);
	else if (clip->direction == D_NORTH)
		return (y >= clip->limit);
	else if (clip->direction == D_SOUTH)
		return (y <= clip->limit);
	else if (clip->direction == D_EAST)
		return (x <= clip->limit);
	else if (clip->direction == D_WEST)
		return (x >= clip->limit);
	return (false);
}
