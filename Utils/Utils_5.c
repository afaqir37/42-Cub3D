/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:13 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/22 16:21:33 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_how_many_commas(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ',')
			counter++;
		i++;
	}
	return (counter);
}

int	ft_return_end(char *str, char *lookingfor)
{
	int	i;

	i = ft_to_find_index(str, lookingfor, 0, 0);
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
		{
			while (str[i])
			{
				if (ft_isemptychar(str[i]))
					break ;
				i++;
			}
			break ;
		}
	}
	return (i);
}

int	ft_rgb_codes(t_file *file, char *name)
{
	t_file	*tmp;
	char	*str;
	t_rgb	rgb;

	tmp = ft_rnwi(file, name);
	if (tmp == NULL)
		return (-1);
	str = ft_substr(tmp->line, ft_rs(tmp->line, name), ft_return_end(tmp->line,
				name) - ft_rs(tmp->line, name));
	if (!str)
		return (ft_wr("Malloc Failed!"));
	if (ft_how_many_commas(str) != 2)
		return (free(str),
			ft_wr("Invalid File: RGB codes must be separated by 2 commas!"));
	if (ft_number_seperated_bycomma(str, 0) < 0)
		return (free(str),
			ft_wr("Invalid File: RGB codes must be numbers!"));
	rgb.r = ft_atoi(str);
	rgb.g = ft_atoi(ft_strchr(str + 1, ',') + 1);
	rgb.b = ft_atoi(ft_strchr(ft_strchr(str + 1, ',') + 1, ',') + 1);
	if (!(rgb.r >= 0 && rgb.r <= 255) || !(rgb.b >= 0 && rgb.b <= 255)
		|| !(rgb.g >= 0 && rgb.g <= 255))
		return (free(str),
			ft_wr("Invalid File: RGB codes must be between 0 and 255!"));
	return (free(str), 0);
}

int	ft_number_seperated_bycomma(char *str, int i)
{
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ',')
			return (-1);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ',')
			return (-1);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != '\0')
			return (-1);
	}
	return (0);
}
