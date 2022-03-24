/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_gfx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:27:03 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 16:03:22 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GFX_H
# define CUB_GFX_H

# include "cub_ext.h"
# include "cub_math.h"

typedef unsigned int	t_rgb;

#define RGB_BLACK 0
#define RGB_WHITE 0xffffff
#define RGB_GRAY  0xaaaaaa

bool	rgb_is_black(t_rgb rgb);


typedef struct s_tex
{
}	t_tex;

t_rgb			tex_at(t_tex *tex, t_fl x, t_fl y);

#endif
