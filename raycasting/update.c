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
		my_mlx_pixel_put(data, x0, y0, color);
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
	double next_x;
	double	next_y;

	next_x = data->player.x;
	next_y = data->player.y;
	data->player.rotation_angle = _normalize_angle(data->player.rotation_angle + data->player.turn_direction * data->player.rotation_speed);
	double rot_ang = _normalize_angle(data->player.rotation_angle + M_PI_2);

	data->player.x = data->player.x + (data->player.walk_direction * data->player.move_speed * cos(data->player.rotation_angle));
	data->player.y = data->player.y + (data->player.walk_direction * data->player.move_speed * sin(data->player.rotation_angle));

	if (data->player.side_direction == 1)
	{
		data->player.x += data->player.side_direction * data->player.move_speed * cos(rot_ang);
		data->player.y += data->player.side_direction * data->player.move_speed * sin(rot_ang);
	}
	else if (data->player.side_direction  == -1)
	{
		data->player.x += data->player.side_direction * data->player.move_speed * cos(rot_ang);
		data->player.y += data->player.side_direction * data->player.move_speed * sin(rot_ang);
	}
	if (_has_wall_at(data->player.x, next_y, data->map))
		data->player.x = next_x;
	else if (_has_wall_at(next_x, data->player.y, data->map))
		data->player.y = next_y;

}
