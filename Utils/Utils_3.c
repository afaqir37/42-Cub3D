/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:11 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 20:51:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_theretwoplus(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
		{
			counter++;
			i++;
		}
	}
	if (counter > 0)
		return (1);
	return (0);
}

t_file	*ft_return_node_with_index(t_file *file, int index)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_free_t_file_node(t_file **file)
{
	t_file	*tmp;

	tmp = *file;
	free(tmp->line);
	free(tmp);
}

void	ft_print_t_file(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
	printf("\n");
}
