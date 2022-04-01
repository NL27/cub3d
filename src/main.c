/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 11:51:39 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/cub_map.h"
#include "include/cub_gfx.h"
#include "utils/utils.h"

#include <unistd.h>

void	cub_main(char *config_file)
{
	char	*configuration;

	configuration = utils_read_file(config_file);
	if (configuration == NULL)
		printf("File not found!\n");
	else
	{
		// TODO: Create a parser and process the file!
	}
}

void	test()
{
	t_gfx	gfx;

	gfx_create(&gfx, 800, 600);
	sleep(3);
	gfx_destroy(&gfx);
/*	t_map		map;
	t_screen	screen;

	printf("Testing begins!\n");
	screen_create(&screen);
	map_create(&map);
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			map_put(&map, x, y, (x == 0 || y == 0 || x == 11 || y == 11) ? BLOCK_WALL : BLOCK_AIR);
		}
	}
	map_put(&map, 8, 4, BLOCK_WALL);
	map_put(&map, 8, 3, BLOCK_WALL);
	for (int y = 0; y < map_get_height(&map); y++)
	{
		for (int x = 0; x < map_get_width(&map); x++)
		{
			switch (map_at(&map, x, y))
			{
				case BLOCK_NOTHING: putchar('`'); break;
				case BLOCK_AIR:     putchar('.'); break;
				case BLOCK_WALL:    putchar('#'); break;
				default:            putchar('?'); break;
			}
			putchar(' ');
		}
		putchar('\n');
	}
	t_vec2_and_angle pos;
	pos.vec.x = 2;
	pos.vec.y = 2;
	pos.angle = 0;
	while (true)
	{
		screen_render(&screen, &map, pos);
		screen_blit(&screen);
		pos.angle -= 0.1;
		sleep(1);
	}
	printf("Testing ended! %u %u %d\n", map_get_width(&map), map_get_height(&map), map_validate(&map));
	map_destroy(&map);
	screen_destroy(&screen);*/
}

int		main(int argc, char *argv[])
{
	test();
	if (argc == 2)
		cub_main(argv[1]);
	else
	{
		printf("Error: Arguments!\n");
	}
	return (0);
}
