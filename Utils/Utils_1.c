/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:10:57 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 05:33:54 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isemptychar(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\n')
		return (1);
	return (0);
}

int	ft_return_len(char *str, int start)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (ft_isemptychar(str[i]) || str[i] == '\n')
			i--;
		else
			break ;
	}
	return (i - start + 1);
}

int	ft_compare_no_null(char *s1, char *s2, int i)
{
	int	j;

	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (-1);
		i++;
		j++;
	}
	if (s2[j] != '\0')
		return (-1);
	return (1);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
