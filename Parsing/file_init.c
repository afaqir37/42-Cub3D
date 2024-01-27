/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:27:27 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 05:43:36 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_intialize_file(t_file **file, int fd)
{
	t_file	*tmp;
	t_file	*new_node;
	char	*read;
	int		i;

	i = 0;
	read = get_next_line(fd);
	tmp = NULL;
	while (read)
	{
		new_node = malloc(sizeof(t_file));
		new_node->line = read;
		new_node->index = i;
		new_node->next = NULL;
		new_node->prev = tmp;
		if (tmp == NULL)
			(*file) = new_node;
		else
			tmp->next = new_node;
		tmp = new_node;
		i++;
		read = get_next_line(fd);
	}
}

int	ft_check_if_xpm_file_existance(t_file *file)
{
	t_file	*tmp;

	if (ft_check_if_exists(file, "NO") < 0)
		return (-1);
	if (ft_check_if_exists(file, "SO") < 0)
		return (-1);
	if (ft_check_if_exists(file, "WE") < 0)
		return (-1);
	if (ft_check_if_exists(file, "EA") < 0)
		return (-1);
	return (0);
}

int	ft_check_rgb(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	if (ft_rgb_codes(file, "F") < 0)
		return (-1);
	if (ft_rgb_codes(file, "C") < 0)
		return (-1);
	return (0);
}

int	ft_skip_ec(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_check_if_file_has_unwanted_lines(t_file *file)
{
	t_file	*tmp;
	int		i;

	i = ft_return_index_of_first_line(file);
	tmp = file;
	while (tmp)
	{
		if (tmp->index >= i)
			return (0);
		if ((ft_cmp_nnull(tmp->line, "R", ft_skip_ec(tmp->line)) < 0)
			&& ft_cmp_nnull(tmp->line, "NO", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "SO", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "WE", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "EA", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "S", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "F", ft_skip_ec(tmp->line)) < 0
			&& ft_cmp_nnull(tmp->line, "C", ft_skip_ec(tmp->line)) < 0
			&& !ft_is_the_whole_line_space(tmp->line))
		{
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
