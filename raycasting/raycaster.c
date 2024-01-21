#include "../cub3d.h"

void	_ray_casting(t_data *data, char **map)
{
	double ray_angle;
	int ray_count;
	t_ray ray;

	ray.angle = _normalize_angle(data->player.rotation_angle - data->half_of_FOV);
	ray_count = 0;
	ray.wall = '0';

	void *img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);

	while (ray_count < data->screen_width)
	{

		
		double horizontal_distance = _horizontal_intersect(&ray, data);
		double vertical_distance = _vertical_intersect(&ray, data);


		if (horizontal_distance < vertical_distance)
			draw_line(data->player.x, data->player.y, ray.horz_wall_hit_X, ray.horz_wall_hit_Y, 0x000000, data);

		else
			draw_line(data->player.x, data->player.y, ray.vert_wall_hit_X, ray.vert_wall_hit_Y, 0xFF00FF, data);
		// ray.x = data->player.x + min_distance * cos(ray.angle);
		// ray.y = data->player.y + min_distance * sin(ray.angle);
		// 
		// printf("is it facing right? : %d\n", _ray_facing_right(ray.angle));
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

		ray.angle = _normalize_angle(ray.angle + data->increment_angle);
		ray_count++;
	}
}