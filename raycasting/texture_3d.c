/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:46:21 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 20:18:42 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_set_texture(t_data *data, float ray_angle, int i)
{
	int	texture_offset_x;

	if (data->rays[i].is_horizontal)
	{
		if (_ray_facing_up(ray_angle))
			data->texture = data->info->no_img;
		else
			data->texture = data->info->so_img;
		texture_offset_x = (int)(data->rays[i].x * data->texture->width
				/ TILE_SIZE) % data->texture->width;
	}
	else
	{
		if (_ray_facing_right(ray_angle))
			data->texture = data->info->ea_img;
		else
			data->texture = data->info->we_img;
		texture_offset_x = (int)(data->rays[i].y * data->texture->width
				/ TILE_SIZE) % data->texture->width;
	}
	return (texture_offset_x);
}

void	_render_the_world(t_data *data, t_pack *pack, int texture_offset_x)
{
	int		i;
	int		wall_y;
	int		texture_y;
	char	*dst;

	i = 0;
	while (i < pack->wall_top)
	{
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->c.r,
				data->info->c.g, data->info->c.b));
	}
	while (i < pack->wall_bottom)
	{
		wall_y = i + (pack->wall_height / 2) - (data->screen_height / 2);
		texture_y = (int)(wall_y * (float)data->texture->height
				/ pack->wall_height) % data->texture->height;
		dst = data->texture->addr + texture_y * data->texture->size_line
			+ texture_offset_x * (data->texture->bits_per_pixel / 8);
		my_mlx_pixel_put(data->img, pack->i, i, *(unsigned int *)dst);
		i++;
	}
	while (i < data->screen_height)
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->f.r,
				data->info->f.g, data->info->f.b));
}

void	_draw_line(t_data *data, float ray_angle, int i, float dist_to_proj)
{
	float	correct_distance;
	float	wall_height;
	float	wall_top;
	float	wall_bottom;
	int		texture_offset_x;

	correct_distance = data->rays[i].distance * cos(ray_angle
			- data->player.rotation_angle);
	dist_to_proj = (data->screen_width / 2) / tan(data->half_of_fov);
	wall_height = (TILE_SIZE / correct_distance) * dist_to_proj;
	wall_top = (data->screen_height / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (data->screen_height / 2) + (wall_height / 2);
	if (wall_bottom > data->screen_height)
		wall_bottom = data->screen_height;
	texture_offset_x = _set_texture(data, ray_angle, i);
	_render_the_world(data, &(t_pack){wall_top, wall_bottom, wall_height, i},
		texture_offset_x);
}
