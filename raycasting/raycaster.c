#include "../cub3d.h"
double min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

float	_distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	_cast_ray(t_data *data, float ray_angle, int i)
{
	t_horz			horz;
	t_vert			vert;
	t_intersection	inter;

	horz = {0};
	vert = {0};
	_horizontal_intersect(&inter, data, ray_angle);
	_horizontal_dda(data, &horz, &inter, ray_angle);
	_vertical_intersect(&inter, data, ray_angle);
	_vertical_dda(data, &vert, &inter, ray_angle);
	horz.distane = INT_MAX;
	vert.distance = INT_MAX;
	if (horz.wall)
		horz.distance = _distance_between_points(data->player.x, data->player.y, horz.wall_hit_x, horz.wall_hit_y);
	if (vert.wall)
		vert.distance = _distance_between_points(data->player.x, data->player.y, vert.wall_hit_x, vert.wall_hit_y);
	_horz_vert_choice(data, &horz, &vert, ray_angle);

}

void	_horz_vert_choice(t_data *data, t_horz *horz, t_vert *vert, float ray_angle)
{
	if (horz->distance < vert->distance)
	{
		data->rays[i].distance = horz->distance;
		data->rays[i].wall_hit_x = horz->wall_hit_x;
		data->rays[i].wall_hit_y = horz->wall_hit_y;
		data->rays[i].is_horizontal = 1;
	}
	else
	{
		data->rays[i].distance = vert->distance;
		data->rays[i].wall_hit_x = vert->wall_hit_x;
		data->rays[i].wall_hit_y = vert->wall_hit_y;
		data->rays[i].is_horizontal = 0;
	}
}

int		_set_texture(t_data *data, float ray_angle, int i)
{
	int texture_offset_x;

	if (data->rays[i].is_horizontal)
	{
		if (_ray_facing_up(ray_angle))
			data->texture = data->info->NO_img;
		else
			data->texture = data->info->SO_img;
		texture_offset_x = (int)(data->rays[i].wall_hit_x * data->texture->width / TILE_SIZE) % data->texture->width;
	}
	else
	{
		if (_ray_facing_right(ray_angle))
			data->texture = data->info->EA_img;
		else
			data->texture = data->info->WE_img;
		texture_offset_x = (int)(data->rays[i].wall_hit_y * data->texture->width / TILE_SIZE) % data->texture->width;
	}

	return (texture_offset_x);
}

void	_render_the_world(t_data *data, t_pack *pack, int texture_offset_x)
{
	
}


void	_draw_line(t_data *data, float ray_angle, int i)
{
	double dist_to_proj;
	double correct_distance;
	double wall_height;
	double wall_top;
	double wall_bottom;
	int texture_offset_x;

	
	correct_distance = data->rays[i].distance * cos(ray.angle - data->player.rotation_angle);
	dist_to_proj = (data->screen_width / 2) / tan(data->half_of_FOV);
	wall_height = (TILE_SIZE / correct_distance) * dist_to_proj;

	wall_top = (data->screen_height / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (data->screen_height / 2) + (wall_height / 2);
	if (wall_bottom > data->screen_height)
		wall_bottom = data->screen_height;
	texture_offset_x = _set_texture(data, ray_angle, i);
	_render_the_world(data, &(t_pack){wall_top, wall_bottom, wall_height, i}, texture_offset_x);

}


void	_ray_casting(t_data *data, char **map)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = _normalize_angle(data->player.rotation_angle - data->half_of_FOV);
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->screen_width);
	while (i < data->screen_width)
	{
		_cast_ray(data, ray_angle, i);
		_draw_line(...);
		ray_angle += data->increment_angle;
		i++;
	}
	free(data->rays);
}

