#include "../../include/cub_gfx.h"
#include "../../include/cub_map.h"

void	screen_render_minimap(t_screen *screen, t_map *map, t_vec2_and_angle pos)
{
	int	dx;
	int	dy;

	dy = -5;
	while (dy <= 5)
	{
		dx = -5;
		while (dx <= 5)
		{
			if (map_at(map, pos.vec.x + dx, pos.vec.y + dy) == BLOCK_WALL)
			{
				screen_draw_rect(screen,
								(t_vec2i) { (dx * 10) + screen_get_width(screen) / 2,
											(dy * 10) + screen_get_height(screen) / 2 },
								(t_vec2i) { 10, 10 },
								RGB_GRAY);
			}
			dx++;
		}
		dy++;
	}
}
