#include "../cub3D.h"

int	ft_write_error(char *str)
{
	write(2, "\033[31mError : ", 14);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (-1);
}

int ft_is_it_a_map_character(char c)
{
	if (c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W'
		|| ft_isemptychar(c))
		return (1);
	return (0);
}

int	ft_is_the_whole_line_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

t_file *ft_return_index_line(t_file *file, int line_start)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		if (tmp->index == line_start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}