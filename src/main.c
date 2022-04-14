/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/07 17:12:37 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/cub_map.h"
#include "include/cub_gfx.h"
#include "include/cub_parser.h"
// #include "parser/parser_internal.h"
#include "utils/utils.h"

#include <unistd.h>

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

void	move(t_map *map, t_vec2_and_angle *pos, t_fl x_dir, t_fl y_dir)
{
	int	dx;
	int	dy;
	int	c;

	if (x_dir < 0)
		dx = -1;
	else
		dx = 1;
	if (y_dir < 0)
		dy = -1;
	else
		dy = 1;
	c = 0;
	while (c < CUB_PORTAL_COUNT)
	{
		if ((int) (pos->vec.x + 0.15 * dx) == map->portals[c].x && (int) (pos->vec.y + 0.15 * dy) == map->portals[c].y)
		{
			c = (c + 1) % CUB_PORTAL_COUNT;
			pos->vec.x = map->portals[c].x - cos(direction_as_angle(map->portals[c].dir)) + 0.5f;
			pos->vec.y = map->portals[c].y - sin(direction_as_angle(map->portals[c].dir)) + 0.5f;
			pos->angle = direction_as_angle(map->portals[c].dir);
			return ;
		}
		c++;
	}
	if (!block_is_solid(map_at(map, (int) (pos->vec.x + 0.1 * dx), (int) pos->vec.y)))
		pos->vec.x += x_dir;
	if (!block_is_solid(map_at(map, (int) pos->vec.x, (int) (pos->vec.y + 0.1 * dy))))
		pos->vec.y += y_dir;
}

void	f(void *ptr)
{
	t_cub	*cub;
	t_vec2	plane;
	t_fl	speed;

	speed = 2;
	cub = (t_cub *) ptr;
	if (cub->keys.w || cub->keys.up)
		move(&cub->map, &cub->pos, cos(cub->pos.angle) * 0.02 * speed, -sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.s || cub->keys.down)
		move(&cub->map, &cub->pos, -cos(cub->pos.angle) * 0.02 * speed, sin(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.a)
		move(&cub->map, &cub->pos, -sin(cub->pos.angle) * 0.02 * speed, -cos(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.d)
		move(&cub->map, &cub->pos, sin(cub->pos.angle) * 0.02 * speed, cos(cub->pos.angle) * 0.02 * speed);
	if (cub->keys.left)
		cub->pos.angle += 0.02 * speed;
	if (cub->keys.right)
		cub->pos.angle -= 0.02 * speed;
	map_render_portals(&cub->map, cub->pos, true);
	map_render_portals(&cub->map, cub->pos, false);
	plane.x = 0;
	plane.y = 1;
	screen_render(&cub->screen, &cub->map, cub->pos, NULL, plane, false);
	screen_render_minimap(&cub->screen, &cub->map, cub->pos);
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

void	cub_init(t_cub *cub)
{
	cub->keys.w = false;
	cub->keys.s = false;
	cub->keys.a = false;
	cub->keys.d = false;
	cub->keys.up = false;
	cub->keys.down = false;
	cub->keys.left = false;
	cub->keys.right = false;
	gfx_create(&cub->gfx, 800, 600);
	screen_create(&cub->screen, &cub->gfx, 800, 600);
	map_create(&cub->map, &cub->gfx);
	gfx_set_tick_function(&cub->gfx, f, cub);
	gfx_keys(&cub->gfx, g, h, cub);
}

void	cub_destroy(t_cub *cub)
{
	map_destroy(&cub->map);
	screen_destroy(&cub->screen);
	gfx_destroy(&cub->gfx);
}

void	print_map(t_map *map)
{
	for (int yy = 0; yy < map_get_height(map); yy++)
	{
		for (int xx = 0; xx < map_get_width(map); xx++)
		{
			switch (map_at(map, xx, yy))
			{
				case BLOCK_NOTHING: putchar('.'); break;
				case BLOCK_AIR: putchar('_'); break;
				case BLOCK_WALL: putchar('#'); break;
				default: putchar('?'); break;
			}
		}
		putchar('\n');
	}
}

bool	parse_config(char *configuration, t_gfx *gfx, t_map *map)
{
	t_reader	reader;
	t_parser	parser;
	bool		value;
	
	reader_create_on_string(&reader, configuration);
	parser_create(&parser, gfx, map, &reader);
	value = parser_parse_config(&parser);
	parser_destroy(&parser);
	reader_destroy(&reader);
	return (value);
}

void	cub_main(char *config_file)
{
	char	*configuration;
	t_cub	cub;

	configuration = utils_read_file(config_file);
	if (configuration == NULL)
		printf("File not found!\n");
	else
	{
		cub_init(&cub);
		if (parse_config(configuration, &cub.gfx, &cub.map) && map_validate(&cub.map))
		{
			cub.pos = cub.map.spawn;
			print_map(&cub.map);
			gfx_run(&cub.gfx);
		}
		else
			// give back an error
			printf("Wrong file input!\n");
		cub_destroy(&cub);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		cub_main(argv[1]);
	else
	{
		printf("Error: Arguments!\n");
	}
	return (0);
}
