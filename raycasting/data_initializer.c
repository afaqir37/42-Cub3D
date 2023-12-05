#include "../cub3d.h"



void	_initialize(t_data* data, char **map)
{
	data->screen_height = SCREEN_HEIGHT;
	data->screen_width = SCREEN_WIDTH;
	data->field_of_view = FOV;
	data->increment_angle = FOV / SCREEN_WIDTH;
	_init_player(map, &data->player);
}