
#include "../../include/cub_gfx.h"

void	screen_draw_rect(t_screen *screen, t_vec2i pos, t_vec2i wh, t_rgb color)
{
	int	x;
	int	y;

	y = 0;
	while (y < wh.x)
	{
		x = 0;
		while (x < wh.y)
		{
			screen_put(screen, x + pos.x, y + pos.y, color);
			x++;
		}
		y++;
	}
}
