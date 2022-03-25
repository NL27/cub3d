/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_blit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:07:13 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/25 12:00:51 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_screen.h"


t_fl	rgb_get_brightness(t_rgb color)
{
	int	r;
	int	g;
	int	b;

	b = color & 0xff;
	g = (color >> 8) & 0xff;
	r = (color >> 16) & 0xff;
	return ((r + g + b) / (3.0f * 256.0f));
}

char	transform(t_rgb color)
{
	/*if (color == RGB_BLACK)
		return ('.');
	else if (color == RGB_GRAY)
		return ('!');
	return ('#');*/
	const char *letters = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	return (letters[(int) ((1 - rgb_get_brightness(color)) * 70) - 1]);
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
