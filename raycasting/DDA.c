#include "../cub3d.h"

int	_ray_facing_up(double radian)
{
	if (radian >= M_PI && radian <= 2 * M_PI)
		return 1;
	return 0;
}

int _ray_facing_down(double radian)
{
	return !_ray_facing_up(radian);
}

int _ray_facing_right(double radian)
{
	if (radian < M_PI * 0.5 || radian > M_PI * 1.5)
		return 1;
	return 0;
}

int _ray_facing_left(double radian)
{
	return !_ray_facing_right(radian);
}

int		_horizontal_intersect(t_ray* ray, t_data* data)
{
	int	xintercept;
	int	yintercept;
	int	xstep;
	int	ystep;
	int	next_X;
	int next_Y;

	yintercept = (round)(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (_ray_facing_down(ray->angle))
		yintercept += TILE_SIZE;
	
	xstep = (-1) * (data->player.y - yintercept) / tan(ray->angle);
	if (_ray_facing_left(ray->angle))
		xstep *= -1;
	xintercept = data->player.x + xstep;
	xstep = TILE_SIZE / tan(ray->angle);
	if (_ray_facing_right(ray->angle) && xstep < 0)
		xstep *= -1;

	if (_ray_facing_left(ray->angle) && xstep > 0)
		xstep *= -1;

	ystep = TILE_SIZE;
	if (_ray_facing_up(ray->angle))
		ystep *= -1;

	next_X = xintercept;
	next_Y = yintercept;

	if (_ray_facing_up(ray->angle))
		next_Y -= 1;

	while (1)
	{
		if (_has_wall_at(next_X, next_Y, data->map))
		{
			draw_line(data->player.x + 10, data->player.y +10, next_X, next_Y, 0x000000, data);
			break;
		}
		else
		{
			next_X += xstep;
			next_Y += ystep;
		}
	}
	
	return 0;
}