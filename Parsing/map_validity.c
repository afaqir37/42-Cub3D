/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:33 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 20:50:36 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_map_lenght(t_file *file, int line_start)
{
	t_file	*tmp;
	int		last;

	last = 0;
	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->index + 1;
	if (last - line_start < 3)
		return (-1);
	return (0);
}

int	ft_return_index_of_first_line(t_file *file)
{
	t_file	*tmp;
	int		i;
	int		wall;

	wall = 0;
	tmp = file;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (ft_is_it_a_map_character(tmp->line[i]))
				i++;
			else
				break ;
		}
		if (tmp->line[i] == '\0' && !ft_is_the_whole_line_space(tmp->line))
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_check_first_last(t_file *tmp, int j)
{
	int	i;

	i = 0;
	if (j == 0 || tmp->next == NULL)
	{
		while (tmp->line[i])
		{
			if (tmp->line[i] != '1' && tmp->line[i] != ' ')
			{
				if (j == 0 && (size_t)i == ft_lenstr(tmp->line) - 1
					&& tmp->line[i] == '\n')
				{
					i++;
					continue ;
				}
				else
					return (-1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_check_first_char(t_file *tmp)
{
	int	i;

	i = 0;
	while (tmp->line[i])
	{
		if (tmp->line[i] == ' ')
			i++;
		else
		{
			if (tmp->line[i] != '1')
				return (-1);
			else
				break ;
		}
	}
	return (0);
}

int	ft_check_map_is_closed(t_file *file, int line_start)
{
	t_file	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = ft_return_node_with_index(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp)
	{
		i = 0;
		if (ft_check_first_last(tmp, j) == -1 || ft_check_first_char(tmp) == -1)
			return (-1);
		while (tmp->line[i])
		{
			if ((tmp->line[i] == '0' || tmp->line[i] == 'N'
					|| tmp->line[i] == 'S' || tmp->line[i] == 'E'
					|| tmp->line[i] == 'W') && (ft_nor_m_ap(tmp, i) == -1))
				return (-1);
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	return (0);
}
