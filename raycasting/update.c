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

// int _check_collision(float x, float y, t_data *data) {
//     float tile;
//     float check_x;
// 	float check_y;
// 	int dx = -1;
// 	int dy;

// 	tile = TILE_SIZE / 6;
// 	while (dx <= 1) 
// 	{
// 		dy = -1;
// 		while (dy <= 1) 
// 		{
// 			check_x = x + (dx * tile);
// 			check_y = y + (dy * tile);
// 			if (_has_wall_at(check_x, check_y, data->map))
// 				return 1;
// 			dy += 1;
// 		}
// 		dx += 1;
// 	}
//     return 0;
// }

// void	_update(t_data* data)
// {
// 	double next_x;
// 	double	next_y;

// 	next_x = data->player.x;
// 	next_y = data->player.y;
// 	data->player.rotation_angle = _normalize_angle(data->player.rotation_angle + data->player.turn_direction * data->player.rotation_speed);
// 	double rot_ang = _normalize_angle(data->player.rotation_angle + M_PI_2);

// 	data->player.x = data->player.x + (data->player.walk_direction * data->player.move_speed * cos(data->player.rotation_angle));
// 	data->player.y = data->player.y + (data->player.walk_direction * data->player.move_speed * sin(data->player.rotation_angle));

// 	if (data->player.side_direction == 1)
// 	{
// 		data->player.x += data->player.side_direction * data->player.move_speed * cos(rot_ang);
// 		data->player.y += data->player.side_direction * data->player.move_speed * sin(rot_ang);
// 	}
// 	else if (data->player.side_direction  == -1)
// 	{
// 		data->player.x += data->player.side_direction * data->player.move_speed * cos(rot_ang);
// 		data->player.y += data->player.side_direction * data->player.move_speed * sin(rot_ang);
// 	}
// 	if (_check_collision(data->player.x, next_y, data))
// 		data->player.x = next_x;
// 	if (_check_collision(next_x, data->player.y, data))
// 		data->player.y = next_y;
// }

void	_move_vertical(t_data* data)
{
	float move_step;
	float new_x;
	float new_y;

	move_step = data->player.walk_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle) * move_step;
	new_y = data->player.y + sin(data->player.rotation_angle) * move_step;
	if (!_has_wall_at(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_move_horizontal(t_data* data)
{
	float move_step;
	float new_x;
	float new_y;

	move_step = data->player.side_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle + M_PI_2) * move_step;
	new_y = data->player.y + sin(data->player.rotation_angle + M_PI_2) * move_step;
	if (!_has_wall_at(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_rotate(t_data* data)
{
	data->player.rotation_angle = _normalize_angle(data->player.rotation_angle + data->player.turn_direction * data->player.rotation_speed);
}
