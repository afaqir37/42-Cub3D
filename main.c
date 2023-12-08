#include "cub3d.h"

int	_render_next_frame(t_data* data)
{
	mlx_clear_window(data->mlx, data->win);
	//_ray_casting(data, data->map);
	return 0;
}


int main(int argc, char **argv) 
{
	t_data	data;
	char *map[] = {
    "11111111",
    "10001111",
    "10N00001",
    "10001101",
    "11001011",
	"10001101",
	"10001101",
	"11111111",
	NULL
};

	if (_initialize(&data, map))
		return (1);

	_draw_map(&data);
	// while (1) {
	// 	mlx_clear_window(data.mlx, data.win);
	// 	_ray_casting(&data, map);
	// }

	mlx_hook(data.win, 2, 1L<<0, _event_listener, &data);
	//mlx_loop_hook(data.mlx, _render_next_frame, &data);
	mlx_loop(data.mlx);

	return (0);
}
