/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_as_angle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:00:53 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 16:18:00 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_map.h"

t_fl	direction_as_angle(t_direction dir)
{
	return (dir * (M_PI / 2.0f));
}
