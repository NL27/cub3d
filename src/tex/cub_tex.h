/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:50:16 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/29 11:41:13 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_TEX_H
# define CUB_TEX_H

#include "../include/cub_gfx.h"

typedef struct s_tex
{
	/* mlx stuff */
}	t_tex;

void	tex_create(t_tex *tex, const char *image_path);
void	tex_destroy(t_tex *tex);

t_rgb	tex_get(t_tex *tex, t_fl x, t_fl y);
void	tex_put(t_tex *tex, t_fl x, t_fl y, t_rgb color);

/*
typedef struct s_tex
{
    // irgendwas mit mlx
} t_tex;

void tex_create(t_tex *tex, const char *image_path, [optional: t_gfx *gfx, falls du den MLX-Pointer brauchst]);  // Laedt und allocatet das Image, speichert es im s_tex
void tex_destroy(t_tex *tex);  // Loescht das Image wieder (natuerlich mit free/delete/destroy())

t_rgb tex_get(t_tex *tex, t_fl x, t_fl y);  // 0 <= x < 1. (alias: x ist zwischen 0 (einschliesslich) und 1 (nicht eingeschlossen))
void  tex_put(t_put *tex, t_fl x, t_fl y, t_rgb color);
*/

#endif