/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:32 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 02:32:46 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_how_many_ptrs_in_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	_len_of_longest_str(char **array)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (array[i])
	{
		if (ft_lenstr(array[i]) > max)
			max = ft_lenstr(array[i]);
		i++;
	}
	return (max);
}

int	_has_wall_at(double x, double y, t_data *data)
{
	int	xmap;
	int	ymap;
	int	map_max_y;
	int	map_max_x;

	map_max_y = ft_how_many_ptrs_in_array(data->map);
	map_max_x = _len_of_longest_str(data->map);
	if (x < 0 || x >= map_max_x * TILE_SIZE || y < 0 || y >= map_max_y
		* TILE_SIZE)
		return (1);
	xmap = floor(x / TILE_SIZE);
	ymap = floor(y / TILE_SIZE);
	if (data->map[ymap][xmap] == '1' || data->map[ymap][xmap] == ' ')
		return (1);
	return (0);
}
