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
	radian_angle = fmod(radian_angle, 2 * M_PI);
	if (radian_angle < 0)
		radian_angle += 2 * M_PI;
	return radian_angle;
}

int	_has_wall_at(double x, double y, char **map)
{
	int	Xmap;
	int	Ymap;

	Xmap = (round)(x / TILE_SIZE);
	Ymap = (round)(y / TILE_SIZE);

	if (map[Ymap][Xmap] == '1')
		return (1);
	else
		return (0);
}