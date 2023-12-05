#include "cub3d.h"


int main(int argc, char **argv) 
{
	t_data	data;
	char *map[] = {
    "11111",
    "10001",
    "10N01",
    "10001",
    "11111",
	NULL
};

	if (_initialize(&data, map))
		return (1);
	_ray_casting(&data, map);
	mlx_loop(data.mlx);

	return (0);
}
