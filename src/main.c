/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/24 14:45:56 by enijakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/cub_map.h"
#include "utils/utils.h"


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
	t_map	map;

	printf("Testing begins!\n");
	map_create(&map);
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			map_put(&map, x, y, (x == 0 || y == 0 || x == 11 || y == 11) ? BLOCK_WALL : BLOCK_AIR);
		}
	}
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
	pos.angle = -3.141592f / 4.0f;
	t_vec2i hit;
	map_raycast(&map, pos, &hit);
	printf("Hit at %d %d\n", hit.x, hit.y);
	printf("Testing ended! %u %u %d\n", map_get_width(&map), map_get_height(&map), map_validate(&map));
	map_destroy(&map);
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
