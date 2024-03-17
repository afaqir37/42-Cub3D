/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:32 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 02:44:54 by afaqir           ###   ########.fr       */
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
	int		i;
	size_t	max;

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

int	_has_wall_at(float x, float y, t_data *data)
{
	size_t		map_y;
	size_t		map_x;
	char	c;

	map_y = ft_how_many_ptrs_in_array(data->map);
	map_x = _len_of_longest_str(data->map);
	if (x < 0 || x >= map_x * TILE_SIZE || y < 0 || y >= map_y * TILE_SIZE)
		return (1);
	map_y = floor(y / TILE_SIZE);
	map_x = floor(x / TILE_SIZE);
	if (map_x >= ft_lenstr(data->map[map_y]))
		return (1);
	c = data->map[map_y][map_x];
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

int	_has_wall(float x, float y, t_data *data)
{
	int	fx;
	int	fy;
	int	fx2;
	int	fy2;

	fy = ft_how_many_ptrs_in_array(data->map);
	fx = _len_of_longest_str(data->map);
	if (x <= 0 || x >= fx * TILE_SIZE || y <= 0 || y >= fy * TILE_SIZE)
		return (1);
	fx = floor((data->player.x) / TILE_SIZE);
	fy = floor((data->player.y) / TILE_SIZE);
	fx2 = floor(x / TILE_SIZE);
	fy2 = floor(y / TILE_SIZE);
	if (data->map[fy][fx] == '1' || data->map[fy2][fx2] == '1'
		|| data->map[fy2][fx] == '1' || data->map[fy][fx2] == '1')
		return (1);
	if (data->map[fy][fx] == ' ' || data->map[fy2][fx2] == ' '
		|| data->map[fy2][fx] == ' ' || data->map[fy][fx2] == ' ')
		return (1);
	return (0);
}
