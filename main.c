/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:36 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 04:48:28 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_render_next_frame(t_data *data)
{
	if (data->player.walk_direction || data->player.side_direction || data->player.turn_direction)
	{
		if (data->player.walk_direction)
			_move_vertical(data);
		if (data->player.side_direction)
			_move_horizontal(data);
		if (data->player.turn_direction)
			_rotate(data);
		_paint(data);
	}
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
	printf("address: %p\n", (*info)->SO_img);
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
	int bits_per_pixel;
	int size_line;
	int endian;
    Image *image = malloc(sizeof(Image));
    if (image == NULL)
    {
        printf("Failed to allocate memory for image\n");
        return NULL;
    }
    image->img = NULL;
    image->addr = NULL;

    image->img = mlx_xpm_file_to_image(mlx_ptr, (char *)file_name, &image->width, &image->height);
    if (image->img == NULL)
    {
        printf("Failed to load XPM file\n");
        free(image);
        return NULL;
    }

    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->size_line, &image->endian);
    if (image->addr == NULL)
    {
        printf("Failed to get image data address\n");
        mlx_destroy_image(mlx_ptr, image->img);
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

void ft_print_2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
}

void	_paint(t_data *data)
{
	char	*img;

	img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = img;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	_ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}




int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_parse_args(argc, argv, &data.info, &data.file))
		return (printf("rani skrana\n"));
	

	if (_initialize(&data, data.info, data.info->map))
		return (1);
	if (ft_open_images(&data.info, &data))
		return(ft_free_info(&data.info), ft_free_file(&data.file));

	_paint(&data);
	mlx_hook(data.win, 2, 1L << 0, _key_press_listener, &data);
	mlx_hook(data.win, 3, 1L << 1, _key_release_listener, &data);
	mlx_loop_hook(data.mlx, _render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
