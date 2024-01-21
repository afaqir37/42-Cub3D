#include "../cub3d.h"

int _key_press_listener(int key, t_data* data)
{
	if (key == 53)
		exit(0);
	else if (key == 123)
		data->player.turn_direction = -1;
	else if (key == 124)
		data->player.turn_direction = +1;
	else if (key == 13)
		data->player.walk_direction = +1;
	else if (key == 1)
		data->player.walk_direction = -1;
	else if (key == 0)
		data->player.side_direction = +1;
	else if (key == 2)
		data->player.side_direction = -1;
	return 0;
}

int _key_release_listener(int key, t_data* data)
{
	if (key == 123 || key == 124)
		data->player.turn_direction = 0;
	else if (key == 13 || key == 1)
		data->player.walk_direction = 0;
	else if (key == 0 || key == 2)
		data->player.side_direction = 0;
	return 0;
}