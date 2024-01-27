/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:12 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 05:34:46 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_sentence_existance(t_file *file, char *str)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		if (ft_compare_no_null(tmp->line, str, ft_skip_ec(tmp->line)) == 1)
		{
			tmp = tmp->next;
			while (tmp)
			{
				if (ft_compare_no_null(tmp->line, str, ft_skip_ec(tmp->line)))
					return (-2);
				tmp = tmp->next;
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

t_file	*ft_rnwi(t_file *file, char *str)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		if (ft_to_find(tmp->line, str, 0, 0) == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_does_have_content(t_file *file, char *str)
{
	t_file	*tmp;
	int		index;
	int		i;

	tmp = ft_rnwi(file, str);
	if (tmp == NULL)
		return (-1);
	index = ft_to_find_index(tmp->line, str, 0, 0);
	if (index < 0)
		return (-1);
	while (tmp->line[index])
	{
		if (ft_isemptychar(tmp->line[index]))
			index++;
		else
			break ;
	}
	if (tmp->line[index] != '\0' && tmp->line[index] != '\n')
		return (0);
	return (-1);
}

int	ft_rs(char *str, char *lookingfor)
{
	int	i;

	i = ft_to_find_index(str, lookingfor, 0, 0);
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_check_if_exists(t_file *file, char *name)
{
	t_file	*tmp;
	char	*str;
	int		fd;

	tmp = ft_rnwi(file, name);
	if (tmp == NULL)
		return (-1);
	str = ft_substr(ft_rnwi(file, name)->line, ft_rs(ft_rnwi(file, name)->line,
				name), ft_return_len(ft_rnwi(file, name)->line,
				ft_rs(ft_rnwi(file, name)->line, name)));
	if (ft_string(str, ".xpm") < 0)
		return (free(str),
			ft_wr("Invalid File: xpm file shoul have valid texture!"));
	free(str);
	str = ft_substr(ft_rnwi(file, name)->line, ft_rs(ft_rnwi(file, name)->line,
				name), ft_return_len(ft_rnwi(file, name)->line,
				ft_rs(ft_rnwi(file, name)->line, name)));
	if (!str)
		return (ft_wr("Malloc Failed!"));
	if (ft_check_existance(str) < 0)
		return (free(str),
			ft_wr("Invalid File: File does not exist!"));
	free(str);
	return (0);
}
