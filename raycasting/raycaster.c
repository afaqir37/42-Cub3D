#include "../cub3d.h"

void	_ray_casting(t_data *data, char **map)
{
	double ray_angle;
	int ray_count;
	t_ray ray;

	ray_angle = data->player.rotation_angle - data->half_of_FOV;
	double x =ray_angle;
	ray_count = 0;
	ray.wall = '0';
	while (ray_count < data->screen_width)
	{
		int length = 50;
		int x1 = data->player.x + 10 + length * cos(ray_angle);
		int y1 = data->player.y + 10 +length * sin(ray_angle);
		draw_line(data->player.x + 10, data->player.y + 10, x1, y1, 0x000000,
			data);
		// ray.x = data->player.x;
		// ray.y = data->player.y;
		// double rayCos = cos(ray_angle) * 10;
		// double raySin = sin(ray_angle) * 10;
		
		// while (ray.wall == '0')
		// {
		// 	printf("entered?\n");
		// 	ray.x += rayCos;
		// 	ray.y += raySin;
		// 	printf("(x: %d, y: %d)\n", (int)((ray.y - TILE_SIZE/2)) / TILE_SIZE, (int)((ray.x - TILE_SIZE/2) / TILE_SIZE));
		// 	ray.wall = map[(int)((ray.y - TILE_SIZE/2)) / TILE_SIZE][(int)((ray.x - TILE_SIZE/2) / TILE_SIZE)];
			
		// 	printf("wall: %c\n", ray.wall);
		// }
		// ray.distance = sqrt(pow(data->player.x - ray.x, 2.0) + pow(data->player.y - ray.y, 2.0));
		// int x1 = data->player.x + ray.distance * cos(ray_angle);
		// int y1 = data->player.y + ray.distance * sin(ray_angle);
		// draw_line(data->player.x + 10, data->player.y + 10, x1 ,y1, 0x000000, data);
		// printf("distance: %d\n", ray.distance);
		// int wall_height;
		// if (ray.distance == 0)
		// 	wall_height = data->screen_width;
		// else
		// 	wall_height = (data->screen_height) / ray.distance;
		// _draw_line(data, wall_height, ray_count);

		ray_angle += data->increment_angle;
		ray_count++;
	}
}