#include "../cub3d.h"

void	_draw_line(t_data* data, int wall_height, int ray_count)
{
	
	int	screen_half_height;
	int	wall_start;
	int	wall_end;

	screen_half_height = data->screen_height / 2;
	wall_start = screen_half_height - wall_height / 2;
	wall_end = screen_half_height + wall_height / 2;
	
	//printf("%d %d %d\n", screen_half_height, wall_start, wall_end);
	int i = 0;
	while (i < wall_start)
	{
		mlx_pixel_put(data->mlx, data->win, ray_count, i, 0x0000FF);
		i++;
	}
	i = wall_start;
	while (i < wall_end)
	{
		mlx_pixel_put(data->mlx, data->win, ray_count, i , 0xFF0000);
		i++;
	}
	i = wall_end;
	while (i < data->screen_height)
	{
		mlx_pixel_put(data->mlx, data->win, ray_count, i, 0x00FF00);
		i++;
	}
	
}