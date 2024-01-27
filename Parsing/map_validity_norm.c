/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:19 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 05:11:19 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_lines_after(t_file *file, int line_start, int i)
{
	t_file	*tmp;

	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp)
	{
		i = 0;
		if ((tmp->line[0] == '\n' && tmp->line[1] == '\0')
			|| !ft_is_theretwoplus(tmp->line)
			|| ft_is_the_whole_line_space(tmp->line))
			return (-1);
		while (tmp->line[i])
		{
			if (ft_isemptychar(tmp->line[i]) || tmp->line[i] == '1'
				|| tmp->line[i] == '0' || tmp->line[i] == 'N'
				|| tmp->line[i] == 'S' || tmp->line[i] == 'E'
				|| tmp->line[i] == 'W')
				i++;
			else
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_how_many_nodes(t_file *file)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = file;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_extract_map(t_file *file, int i)
{
	char	**map;
	t_file	*tmp;
	int		j;

	tmp = ft_return_index_line(file, i);
	if (tmp == NULL)
		return (NULL);
	map = malloc(sizeof(char *) * (ft_how_many_nodes(file) - i + 1));
	if (map == NULL)
		return (NULL);
	j = 0;
	while (tmp)
	{
		map[j] = ft_strdup(tmp->line);
		j++;
		tmp = tmp->next;
	}
	map[j] = NULL;
	return (map);
}

int	ft_check_map_validity(t_file *file, t_info **info)
{
	int	i;
	int	error_code;

	i = ft_return_index_of_first_line(file);
	if (i < 0)
		return (ft_wr("\033[31mMap is not valid: Where is the map bro?"));
	if (ft_check_map_lenght(file, i) < 0)
		return (ft_wr("\033[31mMap is not valid: Chhad l3b tlbnaya?"));
	if (ft_check_lines_after(file, i, 0) < 0)
		return (ft_wr("\033[31mMap is not valid: Weird Map, Redo it!"));
	if (ft_check_map_is_closed(file, i) < 0)
		return (ft_wr("\033[31mMap is not valid"));
	error_code = ft_check_one_player(file, i);
	if (error_code < 0)
	{
		if (error_code == -1)
			return (ft_wr("\033[31mInvalid Mao: Player Not Found!"));
		if (error_code == -2)
			return (ft_wr("\033[31mInvalid Map: Too Many Players!"));
	}
	(*info)->map = ft_extract_map(file, i);
	return (0);
}
