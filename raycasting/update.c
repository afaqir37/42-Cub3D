/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:27 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 02:45:50 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	_move_vertical(t_data *data)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = data->player.walk_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle) * move_step;
	new_y = data->player.y + sin(data->player.rotation_angle) * move_step;
	if (!_has_wall(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_move_horizontal(t_data *data)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = data->player.side_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle + M_PI_2)
		* move_step;
	new_y = data->player.y + sin(data->player.rotation_angle + M_PI_2)
		* move_step;
	if (!_has_wall(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_rotate(t_data *data)
{
	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
	data->player.rotation_angle = _normalize_angle(data->player.rotation_angle);
}
