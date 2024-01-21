#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}


void	_draw_line(t_data* data, int wall_height, int ray_count)
{
	t_info *tex;
	int	screen_half_height;
	int	wall_start;
	int	wall_end;

        int wall_top = (data->screen_height - wall_height) / 2;
        int wall_bottom = (data->screen_height + wall_height) / 2;

        tex = data->info;
		for (int y = 0; y < data->screen_height; y++) {
            if (y < wall_top) {
			
                my_mlx_pixel_put(data, ray_count, y, 0x00FF00);
            } else if (y >= wall_top && y <= wall_bottom) {
                // Draw the wall
                my_mlx_pixel_put(data, ray_count, y, 0x0000FF);
            } else {
                // Draw the floor
                my_mlx_pixel_put(data, ray_count, y, 0xFF0000);
            }
        }
}