/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/03/23 14:13:02 by enijakow         ###   ########.fr       */
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
	map_put(&map, 5, 7, BLOCK_WALL);
	map_put(&map, 15, 12, BLOCK_WALL);
	map_put(&map, 3, 3, BLOCK_WALL);
	for (unsigned int y = 0; y < map_get_height(&map); y++)
	{
		for (unsigned int x = 0; x < map_get_width(&map); x++)
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
	printf("Testing ended! %u %u\n", map_get_width(&map), map_get_height(&map));
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
