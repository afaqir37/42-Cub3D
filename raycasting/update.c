#include "../cub3d.h"

void draw_line(int x0, int y0, int x1, int y1, int color, t_data* data)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	_update(t_data* data)
{
	printf("value: %d\n", data->player.walk_direction);
	data->player.rotation_angle = _normalize_angle(data->player.rotation_angle + data->player.turn_direction * data->player.rotation_speed);
	data->player.x += (data->player.walk_direction * data->player.move_speed * cos(data->player.rotation_angle));
	data->player.y += (data->player.walk_direction * data->player.move_speed * sin(data->player.rotation_angle));
	printf("playerx: %f | cosvvvv: %f | sin: %f\n", data->player.x, data->player.walk_direction * cos(data->player.rotation_angle), data->player.rotation_angle);
}