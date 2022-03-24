/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_screen.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:47:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 15:31:57 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_ext.h"
#include "../include/cub_gfx.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

typedef struct s_screen
{
	t_rgb	text[SCREEN_WIDTH][SCREEN_HEIGHT];
}	t_screen;

void			screen_create(t_screen *screen);
void			screen_destroy(t_screen *screen);

unsigned int	screen_get_width(t_screen *screen);
unsigned int	screen_get_height(t_screen *screen);
void			screen_put(t_screen *screen, unsigned int x, unsigned int y, t_rgb color);
void			screen_blit(t_screen *screen);
