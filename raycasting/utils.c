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

int	_has_wall_at(double x, double y, char **map)
{
	int	Xmap;
	int	Ymap;

	Xmap = (int)floor(x / TILE_SIZE);
	Ymap =  (int)floor(y / TILE_SIZE);
	printf("check :)\n");
	if (Xmap >= 0 && Xmap < 9 && Ymap >=0 && Ymap < 9 && map[Ymap][Xmap] == '1')
		return (1);
	else
		return (0);
}