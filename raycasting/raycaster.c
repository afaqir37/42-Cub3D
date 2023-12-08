#include "../cub3d.h"

void	_ray_casting(t_data* data, char **map)
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

		double rayCos = cos(ray_angle);
		double raySin = sin(ray_angle);

		while (ray.wall == '0')
		{
			ray.x += rayCos;
			ray.y += raySin;
			ray.wall = map[(int)round(ray.y)][(int)round(ray.x)];
		}
		
		ray.distance = sqrt(pow(data->player.x - ray.x, 2.0) + pow(data->player.y - ray.y, 2.0));
		printf("distance: %d\n", ray.distance);
		
		int wall_height = (data->screen_height) / ray.distance;
		_draw_line(data, wall_height, ray_count);

		ray_angle += data->increment_angle;
		ray_count++;
	}
}