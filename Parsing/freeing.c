/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:35:35 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 20:48:46 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_free_info(t_info **info)
{
	if (!info || !*info)
		return (1);
	if ((*info)->no)
		free((*info)->no);
	if ((*info)->so)
		free((*info)->so);
	if ((*info)->we)
		free((*info)->we);
	if ((*info)->ea)
		free((*info)->ea);
	if ((*info)->no_img)
		free((*info)->no_img);
	if ((*info)->so_img)
		free((*info)->so_img);
	if ((*info)->we_img)
		free((*info)->we_img);
	if ((*info)->ea_img)
		free((*info)->ea_img);
	if ((*info)->map)
		ft_free_2d((*info)->map);
	return (free(*info), 1);
}

int	ft_free_file(t_file **file)
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

t_image	*load_xpm_file(void *mlx_ptr, const char *file_name)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (image == NULL)
		return (ft_wr("Failed to allocate memory for image"), NULL);
	image->img = NULL;
	image->addr = NULL;
	image->img = mlx_xpm_file_to_image(mlx_ptr, (char *)file_name,
			&image->width, &image->height);
	if (image->img == NULL)
		return (ft_wr("Failed to load XPM file"), free(image), NULL);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
	{
		ft_wr("Failed to get image data address");
		mlx_destroy_image(mlx_ptr, image->img);
		free(image);
		return (NULL);
	}
	return (image);
}
