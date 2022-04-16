/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:20 by nlenoch           #+#    #+#             */
/*   Updated: 2022/04/16 16:41:20 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cub_destroy(t_cub *cub)
{
	map_destroy(&cub->map);
	screen_destroy(&cub->screen);
	gfx_destroy(&cub->gfx);
}
