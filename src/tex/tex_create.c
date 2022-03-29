/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:59:34 by nlenoch           #+#    #+#             */
/*   Updated: 2022/03/29 11:57:53 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_tex.h"

void	tex_create(t_tex *tex, const char *image_path)
{
	mlx_init(); //must be the first function called on failure returns NULL
	if (mlx_init() == NULL)
		printf("MLX INIT ERROR!");
	mlx_new_image();
	
	mlx_put_image_to_window();
}
