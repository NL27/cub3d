/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_blit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:07:13 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 16:05:14 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_screen.h"


bool	rgb_is_black(t_rgb rgb);


char	transform(t_rgb color)
{
	if (color == RGB_BLACK)
		return ('.');
	else if (color == RGB_GRAY)
		return ('!');
	return ('#');
}

void	screen_blit(t_screen *screen)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < screen_get_height(screen))
	{
		x = 0;
		while (x < screen_get_width(screen))
		{
			putchar(transform(screen->text[x][y]));
			x = x + 1;
		}
		y = y + 1;
		putchar('\n');
	}
}
