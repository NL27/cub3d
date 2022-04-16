/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:10:09 by enijakow          #+#    #+#             */
/*   Updated: 2022/04/16 15:27:51 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/cub_map.h"
#include "include/cub_gfx.h"
#include "include/cub_parser.h"
#include "utils/utils.h"

#include <unistd.h>

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
		cub_create(&cub);
		if (parse_config(configuration, &cub.gfx, &cub.map)
			&& map_validate(&cub.map))
		{
			cub.pos = cub.map.spawn;
			gfx_run(&cub.gfx);
		}
		else
			// give back an error
			printf("Wrong file input!\n");
		cub_destroy(&cub);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		cub_main(argv[1]);
	else
	{
		printf("Error: Arguments!\n");
	}
	return (0);
}
