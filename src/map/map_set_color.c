
#include "../include/cub_map.h"

void	map_set_color(t_map *map, unsigned int number, t_rgb color)
{
    map->colors[number] = color;
}
