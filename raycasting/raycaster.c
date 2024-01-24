#include "../cub3d.h"
double min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

void	_ray_casting(t_data *data, char **map)
{
	double ray_angle;
	int ray_count;
	int ray_direction;
	t_ray ray;
	double correct_distance;
	double prev_ray_angle;
	double prev_ray_direction;
	int prev_horz;
	int prev_vert;

	ray.angle = _normalize_angle(data->player.rotation_angle - data->half_of_FOV);
	ray_count = 0;
	ray.wall = '0';


	while (ray_count < data->screen_width)
	{

		
		double horizontal_distance = _horizontal_intersect(&ray, data);
		double vertical_distance = _vertical_intersect(&ray, data);
		double dist_to_proj = (data->screen_width / 2) / tan(data->half_of_FOV);

		double epsilon = 0.0000001;

		if (fabs(horizontal_distance - vertical_distance) < epsilon) {
	correct_distance = horizontal_distance * cos(ray.angle - data->player.rotation_angle);

        if ((prev_ray_angle > 0 && prev_ray_angle < M_PI / 2 && ray.angle > 0 && ray.angle < M_PI / 2) ||
            (prev_ray_angle > M_PI / 2 && prev_ray_angle < M_PI && ray.angle > M_PI / 2 && ray.angle < M_PI) ||
            (prev_ray_angle > M_PI && prev_ray_angle < 3 * M_PI / 2 && ray.angle > M_PI && ray.angle < 3 * M_PI / 2) ||
            (prev_ray_angle > 3 * M_PI / 2 && prev_ray_angle < 2 * M_PI && ray.angle > 3 * M_PI / 2 && ray.angle < 2 * M_PI)) {
            // The previous ray's angle and the current ray's angle are in the same interval
            // Use the texture of the previous ray
           // _draw_line(data, (TILE_SIZE / correct_distance) * dist_to_proj, prev_ray_direction, ray_count, prev_horz);
		  // 	draw_line(data->player.x, data->player.y, (int)ray.horz_wall_hit_X, (int)ray.horz_wall_hit_Y, 0xFF0000, data);
			}
		else {
			// The previous ray's angle and the current ray's angle are in different intervals
			// Use the texture of the current ray
			_draw_line(data, (TILE_SIZE / correct_distance) * dist_to_proj, ray_direction, ray_count, ray.horz_wall_hit_X);
		
    if (_ray_facing_right(ray.angle) && _ray_facing_up(ray.angle)) {
        ray_direction = 3; // upper right quadrant, horizontal wall
    } else if (_ray_facing_right(ray.angle) && _ray_facing_down(ray.angle)) {
        ray_direction = 2; // lower right quadrant, vertical wall
    } else if (_ray_facing_left(ray.angle) && _ray_facing_down(ray.angle)) {
        ray_direction = 1; // lower left quadrant, horizontal wall
    } else if (_ray_facing_left(ray.angle) && _ray_facing_up(ray.angle)) {
        ray_direction = 0; // upper left quadrant, vertical wall
    }
    _draw_line(data, (TILE_SIZE / (correct_distance)) * dist_to_proj, ray_direction, ray_count, ray.horz_wall_hit_X);
		}
		}
	


		 else if (horizontal_distance < vertical_distance) {
			correct_distance = horizontal_distance * cos(ray.angle - data->player.rotation_angle);
			if (_ray_facing_up(ray.angle))
				ray_direction = 1;
			else
				ray_direction = 0;

		 //_draw_line(data, (TILE_SIZE / correct_distance) * dist_to_proj, ray_direction, ray_count, ray.horz_wall_hit_X);
		 prev_horz = ray.horz_wall_hit_X;

			 //printf("x: %f, y: %f, x1: %f, y1: %f\n", data->player.x, data->player.y, ray.horz_wall_hit_X, ray.horz_wall_hit_Y);	
			draw_line(data->player.x, data->player.y, (int)ray.horz_wall_hit_X, (int)ray.horz_wall_hit_Y, 0xFF0000, data);
		}

		else if (horizontal_distance > vertical_distance)
		{
			correct_distance = vertical_distance * cos(ray.angle - data->player.rotation_angle);
			if (_ray_facing_right(ray.angle))
				ray_direction = 2;
			else if (_ray_facing_left(ray.angle))
				ray_direction = 3;
			// printf("x: %f, y: %f, x1: %f, y1: %f\n", data->player.x, data->player.y, ray.vert_wall_hit_X, ray.vert_wall_hit_Y);
			draw_line(data->player.x, data->player.y, (int)ray.vert_wall_hit_X, (int)ray.vert_wall_hit_Y, 0xFF0000, data);
			//_draw_line(data, (TILE_SIZE / correct_distance) * dist_to_proj, ray_direction ,ray_count, ray.vert_wall_hit_Y);
			prev_vert = ray.vert_wall_hit_X;
		}


		ray.angle = _normalize_angle(ray.angle + data->increment_angle);
		prev_ray_angle = ray.angle;
		prev_ray_direction = ray_direction;
		ray_count++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

}
