#include "../cub3d.h"

int ft_is_theretwoplus(char *str)
{
	int i;
	int counter;

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


int	ft_is_there_anything_other_than_space_and_one(t_file *file, int line_start)
{
	int i;
	t_file *tmp;

	i = 0;
	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp->line[i])
	{
		if (ft_isemptychar(tmp->line[i]))
			i++;
		else if (tmp->line[i] == '1')
			i++;
		else
			return (1);
	}
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		else
			tmp = tmp->next;
	}
	while (tmp->line[i])
	{
		if (ft_isemptychar(tmp->line[i]))
			i++;
		else if (tmp->line[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int ft_check_last_line(t_file *file, int line_start)
{
	t_file *tmp;
	int i;
	
	tmp = file;
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		else
			tmp = tmp->next;
	}
	i = 0;
	while (tmp->line[i])
	{
		if (ft_isemptychar(tmp->line[i]))
			i++;
		else if (tmp->line[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

t_file *ft_return_node_with_index(t_file *file, int index)
{
	t_file *tmp;

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
	t_file *tmp;

	tmp = *file;
	free(tmp->line);
	free(tmp);
}

void	ft_print_t_file(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
	printf("\n");
}
