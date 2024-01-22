#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

void	_draw_line(t_data* data, int wall_height, int ray_count, int ray_x)
{
	t_info *tex;
	int	screen_half_height;
	int	wall_start;
	int	wall_end;
	double tex_x;
	double tex_y;
	char *texture;
	int color;

	int wall_top = (data->screen_height - wall_height) / 2;
	int wall_bottom = (data->screen_height + wall_height) / 2;


	tex_x = ((ray_x % TILE_SIZE) / (double)TILE_SIZE * data->info->NO_img->width);
	texture = data->info->NO_img->addr;
	tex = data->info;
	for (int y = 0; y < data->screen_height; y++) {
		if (y < wall_top) {
			my_mlx_pixel_put(data, ray_count, y, 0x00FF00);
		} else if (y >= wall_top && y <= wall_bottom) {
			tex_y = ((y - wall_top) / (double)(wall_bottom - wall_top) * tex->NO_img->height);
			if (tex_y < 0 || tex_y > tex->NO_img->height)
			{	printf("tex_y: %f\n", tex_y);
				exit(1);
			}
			tex_y = fmax(0, fmin(tex_y, tex->NO_img->height - 1)); // Ensure tex_y is within bounds
			color = *(unsigned int*)(tex->NO_img->addr + (int)tex_y * tex->NO_img->size_line + (int)tex_x * (tex->NO_img->bits_per_pixel / 8));
			my_mlx_pixel_put(data, ray_count, y, color); // Use color from texture
		} else {
			my_mlx_pixel_put(data, ray_count, y, 0xFF0000);
		}
	}
}