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

	horz = (t_horz){0};
	vert = (t_vert){0};
	_horizontal_intersect(&inter, data, ray_angle);
	_horizontal_dda(data, &horz, &inter, ray_angle);
	_vertical_intersect(&inter, data, ray_angle);
	_vertical_dda(data, &vert, &inter, ray_angle);
	horz.distance = INT_MAX;
	vert.distance = INT_MAX;
	if (horz.wall)
		horz.distance = _distance_between_points(data->player.x, data->player.y, horz.wall_hit_x, horz.wall_hit_y);
	if (vert.wall)
		vert.distance = _distance_between_points(data->player.x, data->player.y, vert.wall_hit_x, vert.wall_hit_y);
	_horz_vert_choice(data, &horz, &vert, i);

}

void	_horz_vert_choice(t_data *data, t_horz *horz, t_vert *vert, int i)
{
	if (horz->distance < vert->distance)
	{
		data->rays[i].distance = horz->distance;
		data->rays[i].x = horz->wall_hit_x;
		data->rays[i].y = horz->wall_hit_y;
		data->rays[i].is_horizontal = 1;
	}
	else
	{
		data->rays[i].distance = vert->distance;
		data->rays[i].x = vert->wall_hit_x;
		data->rays[i].y = vert->wall_hit_y;
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
		texture_offset_x = (int)(data->rays[i].x * data->texture->width / TILE_SIZE) % data->texture->width;
	}
	else
	{
		if (_ray_facing_right(ray_angle))
			data->texture = data->info->EA_img;
		else
			data->texture = data->info->WE_img;
		texture_offset_x = (int)(data->rays[i].y * data->texture->width / TILE_SIZE) % data->texture->width;
	}

	return (texture_offset_x);
}

void	_render_the_world(t_data *data, t_pack *pack, int texture_offset_x)
{
	int	i;
	int wall_y;
	int texture_y;
	char	*dst;

	i = 0;
	while (i < pack->wall_top)
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->C.r, data->info->C.g, data->info->C.b));
	while (i < pack->wall_bottom)
	{
		printf("saxa\n");
		wall_y = i + (pack->wall_height / 2) - (data->screen_height / 2);
		texture_y = (int)(wall_y * (float)data->texture->height / pack->wall_height) % data->texture->height;
		dst = data->texture->addr + texture_y * data->texture->size_line + texture_offset_x * (data->texture->bits_per_pixel / 8);
		printf("%u\n", *(unsigned int *)dst);
		my_mlx_pixel_put(data->img, pack->i, i, *(unsigned int *)dst);
		i++;
	}
	while (i < data->screen_height)
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->F.r, data->info->F.g, data->info->F.b));
}


void	_draw_line(t_data *data, float ray_angle, int i)
{
	double dist_to_proj;
	double correct_distance;
	double wall_height;
	double wall_top;
	double wall_bottom;
	int texture_offset_x;

	
	correct_distance = data->rays[i].distance * cos(ray_angle - data->player.rotation_angle);
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


void	_ray_casting(t_data *data)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = _normalize_angle(data->player.rotation_angle - data->half_of_FOV);
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->screen_width);
	while (i < data->screen_width)
	{
		_cast_ray(data, ray_angle, i);
		_draw_line(data, ray_angle, i);
		ray_angle += data->increment_angle;
		i++;
	}
	free(data->rays);
}

