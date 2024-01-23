#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < data->screen_width && y >= 0 && y < data->screen_height)
	{
		dst = data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}

}

unsigned int rgb_to_hex(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}


void	_draw_line(t_data* data, int wall_height, int ray_direction , int ray_count, int ray_x)
{
    t_info *tex;
    int	wall_start;
    int	wall_end;
    double tex_x;
    double tex_y;
    char *texture;
    int color;

    int wall_top = (data->screen_height - wall_height) / 2;
    int wall_bottom = (data->screen_height + wall_height) / 2;

    char *textures[] = {data->info->NO_img->addr, data->info->SO_img->addr, data->info->EA_img->addr, data->info->WE_img->addr};
    int widths[] = {data->info->NO_img->width, data->info->SO_img->width, data->info->EA_img->width, data->info->WE_img->width};

    texture = textures[ray_direction];
	//printf("direction---> %d\n", ray_direction);
    tex_x = ((ray_x % (TILE_SIZE)) / (double)(TILE_SIZE)) /*(((ray_x / TILE_SIZE) - (int)(ray_x / TILE_SIZE))*/  * widths[ray_direction];
    tex = data->info;
    for (int y = 0; y < data->screen_height; y++) {
        if (y < wall_top) {
            my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->C.r, data->info->C.g, data->info->C.b));
        } else if (y >= wall_top && y <= wall_bottom) {
            tex_y = ((y - wall_top) / (double)(wall_bottom - wall_top) * tex->NO_img->height);
            tex_y = fmax(0, fmin(tex_y, tex->NO_img->height - 1)); 
            color = *(unsigned int*)(texture + (int)tex_y * tex->NO_img->size_line + (int)tex_x * (tex->NO_img->bits_per_pixel / 8));
            my_mlx_pixel_put(data, ray_count, y, color);
        } else {
            my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->F.r, data->info->F.g, data->info->F.b));
        }
    }
}

// void	_draw_line(t_data* data, int wall_height, int ray_count, int ray_x)
// {
// 	t_info *tex;
// 	int	screen_half_height;
// 	int	wall_start;
// 	int	wall_end;
// 	double tex_x;
// 	double tex_y;
// 	char *texture;
// 	int color;

// 	int wall_top = (data->screen_height - wall_height) / 2;
// 	int wall_bottom = (data->screen_height + wall_height) / 2;


// 	tex_x = ((ray_x % TILE_SIZE) / (double)TILE_SIZE * data->info->NO_img->width);
// 	texture = data->info->NO_img->addr;
// 	tex = data->info;
// 	for (int y = 0; y < data->screen_height; y++) {
// 		if (y < wall_top) {
// 			my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->C.r, data->info->C.g, data->info->C.b));
// 		} else if (y >= wall_top && y <= wall_bottom) {
// 			tex_y = ((y - wall_top) / (double)(wall_bottom - wall_top) * tex->NO_img->height);
// 			tex_y = fmax(0, fmin(tex_y, tex->NO_img->height - 1)); 
// 			color = *(unsigned int*)(tex->NO_img->addr + (int)tex_y * tex->NO_img->size_line + (int)tex_x * (tex->NO_img->bits_per_pixel / 8));
// 			my_mlx_pixel_put(data, ray_count, y, color); 
// 		} else {
// 			my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->F.r, data->info->F.g, data->info->F.b));
// 		}
// 	}
// }