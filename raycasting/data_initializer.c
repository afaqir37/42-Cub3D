/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:34:59 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 03:13:25 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_initialize(t_data *data, t_info *info, char **map)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->win)
		return (1);
	data->screen_height = SCREEN_HEIGHT;
	data->screen_width = SCREEN_WIDTH;
	data->field_of_view = _to_radian(FOV);
	data->half_of_fov = _to_radian(FOV) / 2;
	data->increment_angle = data->field_of_view / data->screen_width;
	data->map = map;
	data->info = info;
	data->img.img = NULL;
	_init_player(map, &data->player);
	return (0);
}
