/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:14 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/27 05:38:46 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	ft_print_t_info(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	for (i = 0; i < 13; i++)
// 		printf("\n");
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  NO  ||  \033[37m\'%s\'\n", info->NO);
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  SO  ||  \033[37m\'%s\'\n", info->SO);
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  WE  ||  \033[37m\'%s\'\n", info->WE);
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  EA  ||  \033[37m\'%s\'\n", info->EA);
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  F   ||  \033[37m\'%d,%d,%d\'\n", info->F.r, info->F.g,
// 			info->F.b);
// 	printf("\033[34m|---------------------------------------------------\n");
// 	printf("|  C   ||  \033[37m\'%d,%d,%d\'\n", info->C.r, info->C.g,
// 			info->C.b);
// 	printf("\033[34m|---------------------------------------------------\n
//		\033[0m");
// }

int	ft_is_the_whole_line_full_of_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '\n' && str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_full_line(char *str, int i)
{
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
