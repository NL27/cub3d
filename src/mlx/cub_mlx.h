/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:04 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/29 12:03:23 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB_MLX_H
#define	CUB_MLH_H

#include "../include/cub_gfx.h"

typedef struct s_gfx
{
	/* mlx stuff */
}	t_gfx;

void	gfx_create(t_gfx *gfx, int window_width, int window_height);
void	gfx_destroy(t_gfx *gfx);

void	gfx_put_pixel(t_gfx *gfx, int x, int y, t_rgb color);


/*
typedef struct s_gfx
{
    // Das hier ist eigentlich nur ein Wrapper um den magischen "mlx-pointer"
} t_gfx;

void gfx_create(t_gfx *gfx, int window_width, int window_height);  // Das hier macht mlx_init und so nen Quatsch
void gfx_destroy(t_gfx *gfx); // Das Gegenteil :)

void gfx_put_pixel(t_gfx *gfx, int x, int y, t_rgb color);
*/
#endif