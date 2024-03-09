#include "../cub3d.h"

double _to_radian(double degree)
{
	return (degree * M_PI / 180);
}

double _to_degree(double radian)
{
	return (radian * 180 / M_PI);
}

double	_normalize_angle(double radian_angle)
{
	radian_angle = remainder(radian_angle, 2 * M_PI);
	if (radian_angle < 0)
		radian_angle += 2 * M_PI;
	return radian_angle;
}

int ft_how_many_ptrs_in_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	_len_of_longest_str(char **array)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) > max)
			max = ft_strlen(array[i]);
		i++;
	}
	return (max);
}

int	_has_wall_at(double x, double y, t_data *data)
{
	int	Xmap;
	int	Ymap;
	int Xplayer;
	int Yplayer;
	int MAP_MAX_Y = ft_how_many_ptrs_in_array(data->map);
	int MAP_MAX_X = _len_of_longest_str(data->map);


	if (x < 0 || x >= MAP_MAX_X * TILE_SIZE || y < 0 || y >= MAP_MAX_Y * TILE_SIZE)
		return (1);
	Xmap = floor(x / TILE_SIZE);
	Ymap = floor(y / TILE_SIZE);
	if (data->map[Ymap][Xmap] == '1' || data->map[Ymap][Xmap] == ' ')
		return (1);

	return (0);

}