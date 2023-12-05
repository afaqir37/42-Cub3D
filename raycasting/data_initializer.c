#include "../cub3d.h"



void	_initialize(t_data* data, char **map)
{
	data->screen_height = SCREEN_HEIGHT;
	data->screen_width = SCREEN_WIDTH;
	data->field_of_view = _to_radian(FOV);
	data->increment_angle = _to_radian(FOV / SCREEN_WIDTH);
	data->precision = PRECISION;
	_init_player(map, &data->player);
}