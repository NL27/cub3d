/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_gfx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:27:03 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 12:27:39 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GFX_H
# define CUB_GFX_H

# include "cub_ext.h"
# include "cub_math.h"
# include "cub_map.h"

typedef unsigned int	t_rgb;

#define RGB_BLACK 0
#define RGB_WHITE 0xffffff
#define RGB_GRAY  0xaaaaaa

bool	rgb_is_black(t_rgb rgb);

t_rgb	rgb_create(int r, int g, int b);
void	rgb_split(t_rgb rgb, int *r, int *g, int *b);
t_rgb	rgb_scale(t_rgb rgb, t_fl scale);

typedef struct s_gfx
{
	void	*mlx;
}	t_gfx;

void	gfx_create(t_gfx *gfx);
void	gfx_destroy(t_gfx *gfx);

typedef struct s_screen
{
	void	*mlx;
	void	*window;
	void	*image;
	int		height;
	int		width;
	char	*pixel_base;
	int		line_len;
	int		bpp;
	int		endian;
}	t_screen;

void			screen_create(t_screen *screen, t_gfx *gfx, int width, int height);
void			screen_destroy(t_screen *screen);

unsigned int	screen_get_width(t_screen *screen);
unsigned int	screen_get_height(t_screen *screen);
void			screen_put(t_screen *screen, unsigned int x, unsigned int y, t_rgb color);
void			screen_blit(t_screen *screen);

void			screen_render(t_screen *screen, t_map *map, t_vec2_and_angle pos);

typedef struct s_tex
{
}	t_tex;

void	tex_create(t_tex *tex, const char *image_path);
void	tex_destroy(t_tex *tex);

t_rgb	tex_at(t_tex *tex, t_fl x, t_fl y);



#endif
