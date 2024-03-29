/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:20:30 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 20:42:32 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	t_need	x;

	x.sign = 1;
	x.result = 0;
	x.i = 0;
	while (str[x.i] == 32 || (str[x.i] >= 9 && str[x.i] <= 13))
		x.i++;
	if (str[x.i] == '-')
	{
		x.sign = -1;
		x.i++;
	}
	else if (str[x.i] == '+')
		x.i++;
	while (str[x.i] >= '0' && str[x.i] <= '9')
	{
		x.result = x.result * 10 + str[x.i] - '0';
		x.i++;
	}
	if (x.result > 9223372036854775807 && x.sign == -1)
		return (0);
	if (x.result > 9223372036854775807)
		return (-1);
	return (x.result * x.sign);
}

int	ft_atf(char *str)
{
	t_need	x;

	x.sign = 1;
	x.result = 0;
	x.i = 0;
	while (str[x.i] == 32 || (str[x.i] >= 9 && str[x.i] <= 13))
		x.i++;
	if (str[x.i] == '-')
	{
		x.sign = -1;
		x.i++;
	}
	else if (str[x.i] == '+')
		x.i++;
	while (str[x.i] >= '0' && str[x.i] <= '9')
	{
		x.result = x.result * 10 + str[x.i] - '0';
		x.i++;
	}
	if (x.result > 9223372036854775807 && x.sign == -1)
		return (free(str), 0);
	if (x.result > 9223372036854775807)
		return (free(str), -1);
	return (free(str), (x.result * x.sign));
}
