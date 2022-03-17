/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_gfx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:27:03 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/17 15:32:43 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GFX_H
# define CUB_GFX_H

# include "cub_ext.h"

typedef float			t_fl;
typedef unsigned int	t_rgb;

typedef struct s_tex
{
}	t_tex;

t_rgb			tex_at(t_tex *tex, t_fl x, t_fl y);

typedef struct s_screen
{
}	t_screen;

unsigned int	screen_get_width(t_screen *screen);
unsigned int	screen_get_height(t_screen *screen);
void			screen_put(t_screen *screen, int x, int y, t_rgb color);

#endif
