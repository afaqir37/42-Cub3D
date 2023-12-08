#include "../cub3d.h"



int	_initialize(t_data* data, char **map)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->win)
		return (1);
	data->screen_height = SCREEN_HEIGHT;
	data->screen_width = SCREEN_WIDTH;
	data->field_of_view = _to_radian(FOV);
	data->increment_angle = _to_radian(FOV / SCREEN_WIDTH);
	data->precision = PRECISION;
	data->map = map;
	_init_player(map, &data->player);
	return (0);
}