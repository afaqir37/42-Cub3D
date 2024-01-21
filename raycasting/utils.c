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

int	_has_wall_at(double x, double y, char **map)
{
	int	Xmap;
	int	Ymap;
	int MAP_MAX_Y = ft_how_many_ptrs_in_array(map);

	Xmap = (int)floor(x / TILE_SIZE);
	Ymap =  (int)floor(y / TILE_SIZE);
	
	if ((Ymap >=0 && Ymap < MAP_MAX_Y) && (Xmap >= 0 && Xmap < ft_strlen(map[Ymap])) && map[Ymap][Xmap] == '1')
		return (1);
	else
		return (0);
}