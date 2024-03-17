/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:22 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 04:18:58 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	_distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

t_direction	_set_direction(float ray_angle)
{
	t_direction	dir;

	dir.up = 0;
	dir.down = 0;
	dir.left = 0;
	dir.right = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		dir.down = 1;
	else
		dir.up = 1;
	if (ray_angle < M_PI * 0.5 || ray_angle > M_PI * 1.5)
		dir.right = 1;
	else
		dir.left = 1;
	return (dir);
}

void	_cast_ray(t_data *data, float ray_angle, int i)
{
	t_horz			horz;
	t_vert			vert;
	t_intersection	inter;
	t_direction		dir;

	horz = (t_horz){0};
	vert = (t_vert){0};
	ray_angle = _normalize(ray_angle);
	dir = _set_direction(ray_angle);
	_horizontal_intersect(&inter, data, ray_angle, dir);
	_horizontal_dda(data, &horz, &inter, dir.up);
	_vertical_intersect(&inter, data, ray_angle, dir);
	_vertical_dda(data, &vert, &inter, dir.left);
	horz.distance = INT_MAX;
	vert.distance = INT_MAX;
	if (horz.wall)
		horz.distance = _distance_between_points(data->player.x, data->player.y,
				horz.wall_hit_x, horz.wall_hit_y);
	if (vert.wall)
		vert.distance = _distance_between_points(data->player.x, data->player.y,
				vert.wall_hit_x, vert.wall_hit_y);
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

void	_ray_casting(t_data *data)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = _normalize(data->player.rotation_angle - data->half_of_fov);
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->screen_width);
	while (i < data->screen_width)
	{
		_cast_ray(data, ray_angle, i);
		_draw_line(data, ray_angle, i, 0.0);
		ray_angle = _normalize(ray_angle + data->increment_angle);
		i++;
	}
	free(data->rays);
}
