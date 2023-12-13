#include "../cub3d.h"

int	_ray_facing_up(double radian)
{
	if (radian >= M_PI && radian <= 2 * M_PI)
		return 1;
	return 0;
}

int _ray_facing_down(double radian)
{
	return !_ray_facing_up(radian);
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

