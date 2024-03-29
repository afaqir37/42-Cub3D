/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:39:09 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/17 05:17:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_args(int ac, char **av, t_info **inf, t_file **fle)
{
	t_file	*file;
	t_info	*info;

	if (ft_error_args(ac, av) < 0)
		return (1);
	ft_intialize_file(&file, open(av[1], O_RDONLY));
	if (file == NULL)
		return (ft_wr("file is invalid"));
	if (ft_check_line_blank(file) < 0)
		return (ft_wr("Invalid File: Please Remove Unwanted Lines!") * -1);
	if (ft_fill_info(&info, &file) < 0)
		return (1);
	if (ft_check_if_file_has_unwanted_lines(file, info) < 0)
		return (ft_wr("Invalid File: Please Remove Unwanted Lines!") * -1);
	if (ft_check_map_validity(file, &info))
		return (1);
	(*inf) = info;
	(*fle) = file;
	return (0);
}

int	ft_fill_info(t_info **info, t_file **file)
{
	if (ft_check_infos_existance(*file) < 0)
		return (ft_free_file(file), -1);
	if (ft_check_info(*file) < 0)
		return (ft_free_file(file), -1);
	if (ft_check_if_xpm_file_existance(*file) < 0)
		return (ft_free_file(file), -1);
	if (ft_check_rgb(*file) < 0)
		return (ft_free_file(file), -1);
	if (ft_fill_tmp(info, *file) < 0)
		return (ft_free_file(file), -1);
	return (0);
}

// Additions ------------------------------------------------

int	ft_check_one_player(t_file *file, int line_start)
{
	t_file	*tmp;
	int		i;
	int		counter;

	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	counter = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'N' || tmp->line[i] == 'S'
				|| tmp->line[i] == 'E' || tmp->line[i] == 'W')
				counter++;
			i++;
		}
		tmp = tmp->next;
	}
	if (counter == 0)
		return (-1);
	if (counter > 1)
		return (-2);
	return (0);
}

int	ft_nor_m_ap(t_file *tmp, int j)
{
	size_t	i;

	i = (size_t)j;
	if (i > 0 && (ft_isemptychar(tmp->line[i - 1])))
		return (-1);
	if (i < ft_lenstr(tmp->line) - 1 && (ft_isemptychar(tmp->line[i + 1])))
		return (-1);
	if (tmp->prev && (((ft_lenstr(tmp->prev->line) > i
					&& ((ft_isemptychar(tmp->prev->line[i]))))
				|| ft_lenstr(tmp->prev->line) <= i)))
		return (-1);
	if (tmp->next && (((ft_lenstr(tmp->next->line) > i
					&& ((ft_isemptychar(tmp->next->line[i]))))
				|| ft_lenstr(tmp->next->line) <= i)))
		return (-1);
	return (0);
}
