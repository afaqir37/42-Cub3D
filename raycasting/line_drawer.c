#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}


void	_draw_line(t_data* data, int wall_height, int ray_count)
{
	
	int	screen_half_height;
	int	wall_start;
	int	wall_end;

	screen_half_height = data->screen_height / 2;
	wall_start = screen_half_height - wall_height / 2;
	wall_end = screen_half_height + wall_height / 2;
	
	
	int i = 0;
	while (i < wall_start)
	{
		// i want to draw the lines to an img, and then when the img is done, put it on the window
		my_mlx_pixel_put(data, ray_count, i, 0x0000FF);
		i++;
	}
	i = wall_start;
	while (i < wall_end)
	{
		my_mlx_pixel_put(data, ray_count, i, 0xFF0000);
		i++;
	}
	i = wall_end;
	while (i < data->screen_height)
	{
		my_mlx_pixel_put(data, ray_count, i, 0x00FF00);
		i++;
	}
}