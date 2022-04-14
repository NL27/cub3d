#include "../include/cub.h"

static void	move(t_map *map, t_vec2_and_angle *pos, t_fl x_dir, t_fl y_dir)
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
			pos->vec.x = map->portals[c].x + cos(direction_as_angle(map->portals[c].dir)) + 0.5f;
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

void	cub_tick(t_cub *cub)
{
	t_vec2	plane;
	t_fl	speed;

	speed = 2;
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
	if (cub->map_displayed)
		screen_render_minimap(&cub->screen, &cub->map, cub->pos);
	screen_blit(&cub->screen, &cub->gfx);
}
