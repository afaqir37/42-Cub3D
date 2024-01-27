/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:39:09 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 18:48:55 by agoujdam         ###   ########.fr       */
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
	if (ft_check_if_file_has_lines_filled_with_blank_characters(file) < 0)
		return (ft_wr("Invalid File: Please Remove Unwanted Lines!") * -1);
	if (ft_fill_info(&info, file) < 0)
		return (1);
	if (ft_check_if_file_has_unwanted_lines(file) < 0)
		return (ft_wr("Invalid File: Please Remove Unwanted Lines!") * -1);
	if (ft_check_map_validity(file, &info))
		return (1);
	(*inf) = info;
	(*fle) = file;
	return (0);
}

int	ft_fill_info(t_info **info, t_file *file)
{
	t_info	*tmp;

	if (ft_check_infos_existance(file) < 0)
		return (-1);
	if (ft_check_info(file) < 0)
		return (-1);
	if (ft_check_if_xpm_file_existance(file) < 0)
		return (-1);
	if (ft_check_rgb(file) < 0)
		return (-1);
	if (ft_fill_tmp(info, file) < 0)
		return (-1);
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

int	ft_nor_m_ap(t_file *tmp, int i)
{
	if (i > 0 && (ft_isemptychar(tmp->line[i - 1])))
		return (-1);
	if (i < ft_strlen(tmp->line) - 1 && (ft_isemptychar(tmp->line[i + 1])))
		return (-1);
	if (tmp->prev && (((ft_strlen(tmp->prev->line) > i
					&& ((ft_isemptychar(tmp->prev->line[i]))))
				|| ft_strlen(tmp->prev->line) <= i)))
		return (-1);
	if (tmp->next && (((ft_strlen(tmp->next->line) > i
					&& ((ft_isemptychar(tmp->next->line[i]))))
				|| ft_strlen(tmp->next->line) <= i)))
		return (-1);
	return (0);
}
