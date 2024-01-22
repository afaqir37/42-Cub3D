#include "../cub3d.h"

int		_horizontal_intersect(t_ray* ray, t_data* data)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	next_X;
	float next_Y;
	if (fabs(ray->angle - M_PI / 2) < 0.00001 || fabs(ray->angle - 3 * M_PI / 2) < 0.00001 || fabs(ray->angle) < 0.00001 || fabs(ray->angle - M_PI) < 0.00001 || fabs(ray->angle - 2 * M_PI) < 0.00001) {
		ray->angle += 0.000001;
	}
	yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (_ray_facing_down(ray->angle))
		yintercept += TILE_SIZE;
	
	xintercept = data->player.x + (yintercept - data->player.y) / tan(ray->angle);
	
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

	
	while (next_X >= 0 && next_X <= data->screen_width && next_Y >= 0 && next_Y <= data->screen_height)
	{
		float x_check = next_X;
		float y_check = next_Y + (_ray_facing_up(ray->angle) ? -1 : 0);

		if (_has_wall_at(x_check, y_check, data->map))
		{
			//draw_line(data->player.x, data->player.y, next_X, next_Y, 0x000000, data);
			ray->horz_wall_hit_X = next_X;
			ray->horz_wall_hit_Y = next_Y;
			break;
		}
		else
		{
			next_X += xstep;
			next_Y += ystep;
	
		}
	}

	ray->distance = sqrt((data->player.x - next_X) * (data->player.x - next_X) + (data->player.y - next_Y) * (data->player.y - next_Y));
	
	return ray->distance;
}

int	_vertical_intersect(t_ray* ray, t_data* data)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	next_X;
	float	next_Y;

	xstep = TILE_SIZE;
	ystep = tan(ray->angle) * TILE_SIZE;
	if (fabs(ray->angle - M_PI / 2) < 0.00001 || fabs(ray->angle - 3 * M_PI / 2) < 0.00001 || fabs(ray->angle) < 0.00001 || fabs(ray->angle - M_PI) < 0.00001 || fabs(ray->angle - 2 * M_PI) < 0.00001) {
		ray->angle += 0.000001;
	}
	if (_ray_facing_right(ray->angle))
	{
		xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
		

	if (_ray_facing_left(ray->angle))
	{
		xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
		xstep *= -1;
	}

	yintercept = data->player.y + tan(ray->angle) * (xintercept - data->player.x);

	if (_ray_facing_up(ray->angle))
	{
		
		if (ystep > 0)
			ystep *= -1;
	}
		

	if (_ray_facing_down(ray->angle))
	{
		if (ystep < 0)
			ystep *= -1;
	}

	next_X = xintercept;
	next_Y = yintercept;

	
	while (next_X >= 0 && next_X <= data->screen_width && next_Y >= 0 && next_Y <= data->screen_height)
	{
		float x_check = next_X +  (_ray_facing_left(ray->angle) ? -1 : 0);
		float y_check = next_Y;

		if (_has_wall_at(x_check, y_check, data->map))
		{
			//draw_line(data->player.x, data->player.y, next_X, next_Y, 0x000000, data);
			ray->vert_wall_hit_X = next_X;
			ray->vert_wall_hit_Y = next_Y;
			break;
		}
		else
		{
			next_X += xstep;
			next_Y += ystep;
		}
	}        

	ray->distance = sqrt((data->player.x - next_X) * (data->player.x - next_X) + (data->player.y - next_Y) * (data->player.y - next_Y));
	
	return (ray->distance);


}