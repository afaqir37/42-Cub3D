#include "../cub3d.h"

void	_ray_casting(t_data* data)
{
	double	ray_angle;
	int		ray_count;
	t_ray	ray;

	ray_angle = data->player.player_dir - data->field_of_view / 2;
	ray_count = 0;
	ray.wall = '0';
	while (ray_count < data->screen_width)
	{
		ray.x = data->player.x;
		ray.y = data->player.y;

		rayCos = cos(ray_angle) / data->precision;
		raySin = sin(ray_angle) / data->precision;

		while (ray.wall == '0')
		{
			ray.x += rayCos;
			ray.y += raySin;
			ray.wall = map[(int)round(ray.y)][(int)round(ray.x)];
		}
		ray.distance = (int)sqrt(pow(data->player.x - ray.x, 2.0) + pow(data->player.y - ray.y, 2.0));

		ray_angle += data->increment_angle;
		ray_count++;
	}
}