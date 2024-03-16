/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:36 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 22:56:03 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_render_next_frame(t_data *data)
{
	if (data->player.walk_direction || data->player.side_direction
		|| data->player.turn_direction)
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

int	ft_open_images(t_info **info, t_data *data)
{
	(*info)->no_img = load_xpm_file(data->mlx, (*info)->no);
	(*info)->so_img = load_xpm_file(data->mlx, (*info)->so);
	(*info)->we_img = load_xpm_file(data->mlx, (*info)->we);
	(*info)->ea_img = load_xpm_file(data->mlx, (*info)->ea);
	if (!(*info)->no_img || !(*info)->so_img
		|| !(*info)->we_img || !(*info)->ea_img)
	{
		ft_wr("Failed to load XPM file");
		return (1);
	}
	return (0);
}

void	ft_print_2d(char **str)
{
	int	i;

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
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	_ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_parse_args(argc, argv, &data.info, &data.file))
		return (system("leaks cub3D"), 1);
	if (_initialize(&data, data.info, data.info->map))
		return (1);
	if (ft_open_images(&data.info, &data))
		return (ft_free_info(&data.info), ft_free_file(&data.file));
	_paint(&data);
	mlx_hook(data.win, 2, 1L << 0, _key_press_listener, &data);
	mlx_hook(data.win, 3, 1L << 1, _key_release_listener, &data);
	mlx_hook(data.win, 17, 0, _close, &data);
	mlx_loop_hook(data.mlx, _render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
