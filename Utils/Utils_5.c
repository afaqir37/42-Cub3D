/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:13 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 02:32:46 by afaqir           ###   ########.fr       */
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
	str = ft_sbstr(tmp->line, ft_rs(tmp->line, name), ft_lenstr(tmp->line)
			- ft_rs(tmp->line, name));
	if (!str)
		return (ft_wr("Malloc Failed!"));
	if (ft_how_many_commas(str) != 2)
		return (free(str), ft_wr("RGB must be separated by 2 commas!"));
	if (ft_number_seperated_bycomma(str, 0) == -1)
		return (free(str), ft_wr("RGB must be numbers!"));
	rgb.r = ft_atoi(str);
	rgb.g = ft_atoi(ft_strchr(str, ',') + 1 + ft_skip_ec(ft_strchr(str, ',')
				+ 1));
	rgb.b = ft_atoi(ft_strchr(ft_strchr(str + 1, ',') + 1, ',') + 1
			+ ft_skip_ec(ft_strchr(ft_strchr(str + 1, ',') + 1, ',') + 1));
	if (!(rgb.r >= 0 && rgb.r <= 255) || !(rgb.b >= 0 && rgb.b <= 255)
		|| !(rgb.g >= 0 && rgb.g <= 255))
		return (free(str),
			ft_wr("Invalid File: RGB codes must be between 0 and 255!"));
	return (free(str), 0);
}

int	ft_check_line_nm(char *str, int i)
{
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] && ft_isemptychar(str[i]))
		i++;
	if (str[i] != ',')
		return (-1);
	return (i);
}

int	ft_number_seperated_bycomma(char *str, int i)
{
	i = ft_check_line_nm(str, i);
	if (i < 0)
		return (-1);
	i += ft_skip_ec(str + i + 1) + 1;
	i = ft_check_line_nm(str, i);
	if (i < 0)
		return (-1);
	i += ft_skip_ec(str + i + 1) + 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_check_full_line(str, i))
		return (-1);
	return (0);
}
