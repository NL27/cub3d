
#include "../include/cub_map.h"

t_rgb	map_get_color(t_map *map, unsigned int number)
{
	return map->colors[number];
}
