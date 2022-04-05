/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/05 15:15:57 by enijakow         ###   ########.fr       */
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
		// parser_reader(configuration);
	}
}

// typedef struct s_everything{
// 	char	*direction_texture[4];
//	t_rgb	*color_heaven;
//	t_rgb	*color_hell;
// }	t_everything;

/*
direction_texture[0] = North = ./...
direction_texture[1] = South = ./...
direction_texture[2] = East = ./...
direction_texture[3] = West = ./...

direction_texture[4] = Heaven = rgb_color
direction_texture[5] = Hell = rgb_color
*/

// void	parser_reader(char *configuration)
// {
// 	t_parser	*parser;
	
// 	if (!parser_parse_config(parser))
// 		break ;
	
// }

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_cub
{
	t_gfx				gfx;
	t_screen			screen;
	t_map				map;
	t_vec2_and_angle	pos;
	t_keys				keys;
}	t_cub;

void	f(void *ptr)
{
	t_cub	*cub;
	t_vec2	plane;
	t_fl	speed;

	speed = 2;
	cub = (t_cub *) ptr;
	if (cub->keys.w || cub->keys.up)
	{
		cub->pos.vec.x += cos(cub->pos.angle) * 0.02 * speed;
		cub->pos.vec.y -= sin(cub->pos.angle) * 0.02 * speed;
	}
	if (cub->keys.s || cub->keys.down)
	{
		cub->pos.vec.x -= cos(cub->pos.angle) * 0.01 * speed;
		cub->pos.vec.y += sin(cub->pos.angle) * 0.01 * speed;
	}
	if (cub->keys.a)
	{
		cub->pos.vec.x -= sin(cub->pos.angle) * 0.01 * speed;
		cub->pos.vec.y -= cos(cub->pos.angle) * 0.01 * speed;
	}
	if (cub->keys.d)
	{
		cub->pos.vec.x += sin(cub->pos.angle) * 0.01 * speed;
		cub->pos.vec.y += cos(cub->pos.angle) * 0.01 * speed;
	}
	if (cub->keys.left)
		cub->pos.angle += 0.02 * speed;
	if (cub->keys.right)
		cub->pos.angle -= 0.02 * speed;
	map_render_portals(&cub->map, cub->pos);
	plane.x = 0;
	plane.y = 1;
	screen_render(&cub->screen, &cub->map, cub->pos, NULL, plane);
	screen_blit(&cub->screen, &cub->gfx);
}

void	g(int key, void *ptr)
{
	t_cub	*cub;

	cub = (t_cub *) ptr;
	if (key == 13)
		cub->keys.w = true;
	if (key == 1)
		cub->keys.s = true;
	if (key == 0)
		cub->keys.a = true;
	if (key == 2)
		cub->keys.d = true;
	if (key == 126)
		cub->keys.up = true;
	if (key == 125)
		cub->keys.down = true;
	if (key == 123)
		cub->keys.left = true;
	if (key == 124)
		cub->keys.right = true;
	printf("Down: %d\n", key);
}

void	h(int key, void *ptr)
{
	t_cub	*cub;

	cub = (t_cub *) ptr;
	if (key == 13)
		cub->keys.w = false;
	if (key == 1)
		cub->keys.s = false;
	if (key == 0)
		cub->keys.a = false;
	if (key == 2)
		cub->keys.d = false;
	if (key == 126)
		cub->keys.up = false;
	if (key == 125)
		cub->keys.down = false;
	if (key == 123)
		cub->keys.left = false;
	if (key == 124)
		cub->keys.right = false;
	printf("Up: %d\n", key);
}

void	test()
{
	t_cub	cub;

	cub.keys.w = false;
	cub.keys.s = false;
	cub.keys.a = false;
	cub.keys.d = false;
	cub.keys.up = false;
	cub.keys.down = false;
	cub.keys.left = false;
	cub.keys.right = false;
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
	
	cub.pos.vec.x = 2.5;
	cub.pos.vec.y = 2.5;
	cub.pos.angle = M_PI;
	gfx_set_tick_function(&cub.gfx, f, &cub);
	gfx_keys(&cub.gfx, g, h, &cub);
	gfx_run(&cub.gfx);
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
