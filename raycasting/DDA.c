#include "../cub3d.h"

int	_ray_facing_up(double radian)
{
	return !_ray_facing_down(radian);
}

int _ray_facing_down(double radian)
{
	if (radian > 0 && radian < M_PI)
		return 1;
	return 0;
}

int _ray_facing_right(double radian)
{
	if (radian < M_PI * 0.5 || radian > M_PI * 1.5)
		return 1;
	return 0;
}

int _ray_facing_left(double radian)
{
	return !_ray_facing_right(radian);
}

