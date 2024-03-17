/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:10 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 00:08:02 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_close(t_data *data)
{
	ft_free_info(&data->info);
	ft_free_file(&data->file);
	exit(0);
}

int	_key_press_listener(int key, t_data *data)
{
	if (key == 53)
		_close(data);
	else if (key == 123)
		data->player.turn_direction = -1;
	else if (key == 124)
		data->player.turn_direction = +1;
	else if (key == 13)
		data->player.walk_direction = +1;
	else if (key == 1)
		data->player.walk_direction = -1;
	else if (key == 0)
		data->player.side_direction = -1;
	else if (key == 2)
		data->player.side_direction = +1;
	return (0);
}

int	_key_release_listener(int key, t_data *data)
{
	if (key == 123 || key == 124)
		data->player.turn_direction = 0;
	else if (key == 13 || key == 1)
		data->player.walk_direction = 0;
	else if (key == 0 || key == 2)
		data->player.side_direction = 0;
	return (0);
}
