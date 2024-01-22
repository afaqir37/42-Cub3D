/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:15 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/22 16:05:18 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_to_find(char *string, char *lookingfor, int i, int j)
{
	while (string[i])
	{
		if (string[i] == lookingfor[j])
		{
			while (string[i] == lookingfor[j])
			{
				i++;
				j++;
			}
			if (lookingfor[j] == '\0')
			{
				if (ft_isemptychar(string[i]))
					return (1);
				else
					return (0);
			}
			else
			{
				i = i - j;
				j = 0;
			}
		}
		i++;
	}
	return (0);
}

int	ft_to_find_index(char *string, char *lookingfor, int i, int j)
{
	while (string[i])
	{
		if (string[i] == lookingfor[j])
		{
			while (string[i] == lookingfor[j])
			{
				i++;
				j++;
			}
			if (lookingfor[j] == '\0')
			{
				if (ft_isemptychar(string[i]))
					return (i);
				else
					return (-1);
			}
			else
			{
				i = i - j;
				j = 0;
			}
		}
		i++;
	}
	return (-1);
}
