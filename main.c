#include "cub3d.h"

int	_render_next_frame(t_data *data)
{
	void	*img;
	char	*img_data;

	mlx_clear_window(data->mlx, data->win);
	_update(data);
	img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	img_data = mlx_get_data_addr(img, &data->bits_per_pixel, &data->size_line,
			&data->endian);
	data->img = img;
	data->img_data = img_data;
	_draw_map(data);
	_ray_casting(data, data->map);
	usleep(10000);
	return (0);
}

void ft_free_2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int ft_free_info(t_info **info)
{
	if (!info || !*info)
		return (1);
	if ((*info)->NO)
		free((*info)->NO);
	if ((*info)->SO)
		free((*info)->SO);
	if ((*info)->WE)
		free((*info)->WE);
	if ((*info)->EA)
		free((*info)->EA);
	if ((*info)->NO_img)
		free((*info)->NO_img);
	if ((*info)->SO_img)
		free((*info)->SO_img);
	if ((*info)->WE_img)
		free((*info)->WE_img);
	if ((*info)->EA_img)
		free((*info)->EA_img);
	// if ((*info)->F)
	// 	free((*info)->F);
	// if ((*info)->C) 
	// 	free((*info)->C);
	if ((*info)->map)
		ft_free_2d((*info)->map);
	return (free(*info), 1);
}

int ft_free_file(t_file **file)
{
	t_file	*tmp;

	if (!file || !*file)
		return (1);
	while (*file)
	{
		tmp = (*file)->next;
		if ((*file)->line)
			free((*file)->line);
		free(*file);
		*file = tmp;
	}
	return (1);
}

Image *load_xpm_file(void *mlx_ptr, const char *file_name)
{
    Image *image = malloc(sizeof(Image));
    if (image == NULL)
    {
        printf("Failed to allocate memory for image\n");
        return NULL;
    }
	image->width = TILE_SIZE;
	image->height = TILE_SIZE;
	image->img = NULL;

    image->img = mlx_xpm_file_to_image(mlx_ptr, (char *)file_name, &image->width, &image->height);
    if (image->img == NULL)
    {
        printf("Failed to load XPM file\n");
        free(image);
        return NULL;
    }

    return image;
}

int ft_open_images(t_info **info, t_data *data)
{
	(*info)->NO_img = load_xpm_file(data->mlx, (*info)->NO);
	(*info)->SO_img = load_xpm_file(data->mlx, (*info)->SO);
	(*info)->WE_img = load_xpm_file(data->mlx, (*info)->WE);
	(*info)->EA_img = load_xpm_file(data->mlx, (*info)->EA);
	if (!(*info)->NO_img || !(*info)->SO_img || !(*info)->WE_img || !(*info)->EA_img)
	{
		printf("Failed to load XPM file\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	*info;
	t_file	*file;

	if (ft_parse_args(argc, argv, &info, &file))
		return (ft_free_info(&info), ft_free_file(&file));
	if (_initialize(&data, info, info->map))
		return (1);
	if (ft_open_images(&info, &data))
		return(ft_free_info(&info), ft_free_file(&file));
	//_draw_map(&data);
	// while (1) {
	// 	mlx_clear_window(data.mlx, data.win);
	// 	_ray_casting(&data, map);
	// }
	mlx_hook(data.win, 2, 1L << 0, _key_press_listener, &data);
	mlx_hook(data.win, 3, 1L << 1, _key_release_listener, &data);
	mlx_loop_hook(data.mlx, _render_next_frame, &data);
	mlx_loop(data.mlx);
	ft_free_info(&info);
	ft_free_file(&file);
	return (0);
}
