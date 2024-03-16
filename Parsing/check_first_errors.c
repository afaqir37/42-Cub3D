/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:27:49 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 21:20:21 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_arg_num(int ac)
{
	if (ac != 2)
		return (-1);
	return (0);
}

int	ft_string(char *str, char *look)
{
	int	i;
	int	j;

	i = ft_lenstr(str) - ft_lenstr(look);
	j = 0;
	if (i <= 0)
		return (-1);
	while (str[i])
	{
		if (str[i] != look[j])
			return (-1);
		i++;
		j++;
	}
	if (look[j] == '\0')
		return (0);
	return (-1);
}

int	ft_check_existance(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	ft_check_line_blank(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		if (ft_is_the_whole_line_full_of_spaces(tmp->line))
			return (ft_free_file(&file), -1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_error_args(int ac, char **av)
{
	if (ft_arg_num(ac) < 0)
		return (ft_wr("Please provide 1 argument only."));
	if (ft_string(av[1], ".cub") < 0)
		return (ft_wr("\".cub\" file required with valid name."));
	if (ft_check_existance(av[1]) < 0)
		return (ft_wr("File does not exist."));
	return (0);
}
