/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/01 18:02:10 by enijakow         ###   ########.fr       */
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

typedef struct s_cub
{
	t_gfx				gfx;
	t_screen			screen;
	t_map				map;
	t_vec2_and_angle	pos;
}	t_cub;

void	f(void *ptr)
{
	t_cub	*cub;

	cub = (t_cub *) ptr;
	map_render_portals(&cub->map, cub->pos);
	screen_render(&cub->screen, &cub->map, cub->pos, -1);
	screen_blit(&cub->screen, &cub->gfx);
	//cub->pos.angle += 0.015;
	//cub->pos.vec.x -= 0.0015;
	cub->pos.vec.y += 0.005;
}

void	test()
{
	t_cub	cub;

	gfx_create(&cub.gfx, 800, 600);
	screen_create(&cub.screen, &cub.gfx, 800, 600);
	map_create(&cub.map, &cub.gfx);
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			map_put(&cub.map, x, y, (x == 0 || y == 0 || x == 11 || y == 11) ? BLOCK_WALL : BLOCK_AIR);
		}
	}
	map_put(&cub.map, 7, 5, BLOCK_WALL);
	map_put(&cub.map, 7, 4, BLOCK_WALL);
	map_put(&cub.map, 7, 3, BLOCK_WALL);
	
	cub.pos.vec.x = 2;
	cub.pos.vec.y = 2;
	cub.pos.angle = M_PI/2.0f;
	mlx_loop_hook(cub.gfx.mlx, (int(*)()) f, &cub);
	mlx_loop(cub.gfx.mlx);
	map_destroy(&cub.map);
	screen_destroy(&cub.screen);
	gfx_destroy(&cub.gfx);
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
