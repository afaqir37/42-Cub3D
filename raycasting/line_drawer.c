#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

unsigned int rgb_to_hex(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

void _draw_line(t_data* data, int wall_height, int ray_direction , int ray_count, int ray_x)
{
    t_info *tex;
    int wall_start;
    int wall_end;
    double tex_x;
    double tex_y;
    char *texture;
    int color;

    int wall_top = (data->screen_height - wall_height) / 2;
    int wall_bottom = (data->screen_height + wall_height) / 2;

    Image *images[] = {data->info->NO_img, data->info->SO_img, data->info->EA_img, data->info->WE_img};
    char *textures[] = {data->info->NO_img->addr, data->info->SO_img->addr, data->info->EA_img->addr, data->info->WE_img->addr};
    int widths[] = {data->info->NO_img->width, data->info->SO_img->width, data->info->EA_img->width, data->info->WE_img->width};
    int heights[] = {data->info->NO_img->height, data->info->SO_img->height, data->info->EA_img->height, data->info->WE_img->height};

    texture = textures[ray_direction];
    tex_x = ((ray_x % (TILE_SIZE)) / (double)(TILE_SIZE)) * widths[ray_direction];
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x > widths[ray_direction])
        tex_x = widths[ray_direction];
    tex = data->info;
    for (int y = 0; y < data->screen_height; y++) {
        if (y < wall_top) {
            my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->C.r, data->info->C.g, data->info->C.b));
        } else if (y >= wall_top && y <= wall_bottom) {
            tex_y = ((y - wall_top) / (double)(wall_bottom - wall_top) * heights[ray_direction]);
            tex_y = fmax(0, fmin(tex_y, heights[ray_direction] - 1));
            if (tex_y < 0)
                tex_y = 0;
            if (tex_y > heights[ray_direction])
                tex_y = heights[ray_direction]; 
            color = *(unsigned int*)(texture + (int)tex_y * images[ray_direction]->size_line + (int)tex_x * (images[ray_direction]->bits_per_pixel / 8));

            my_mlx_pixel_put(data, ray_count, y, color);
        } else {
            my_mlx_pixel_put(data, ray_count, y, rgb_to_hex(data->info->F.r, data->info->F.g, data->info->F.b));
        }
    }
}
