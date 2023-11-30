#include "../cub3d.h"

int	ft_arg_num(int ac)
{
	if (ac != 2)
		return (-1);
	return (0);
}

int ft_string(char *str, char *look)
{
	int i;
	int j;

	i = ft_strlen(str) - ft_strlen(look);
	j = 0;
	if (i <= 0)
		return (-1);
	while (str[i])
	{
		if (str[i] != look[j])
			return (-1);
		i++;
		j++;
	}
	if (look[j] == '\0')
		return (0);
	return (-1);
}

int ft_check_existance(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int ft_check_if_file_has_lines_filled_with_blank_characters(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		if (ft_is_the_whole_line_full_of_spaces(tmp->line))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int ft_error_args(int ac, char **av)
{
	if (ft_arg_num(ac) < 0)
		return (ft_write_error("Please provide 1 argument only."));
	if (ft_string(av[1], ".cub") < 0)
		return (ft_write_error("Please provide a \".cub\" file."));
	if (ft_check_existance(av[1]) < 0)
		return (ft_write_error("File does not exist."));
	return (0);
}

int ft_check_if_file_has_unwanted_lines(t_file *file)
{
	t_file *tmp;
	int		i;

	i = ft_return_index_of_first_line(file);
	tmp = file;
	while (tmp)
	{
		if (tmp->index >= i)
			return (0);
		if ((ft_compare_no_null(tmp->line, "R") < 0) && ft_compare_no_null(tmp->line, "NO") < 0
			&& ft_compare_no_null(tmp->line, "SO") < 0 && ft_compare_no_null(tmp->line, "WE") < 0
			&& ft_compare_no_null(tmp->line, "EA") < 0 && ft_compare_no_null(tmp->line, "S") < 0
			&& ft_compare_no_null(tmp->line, "F") < 0 && ft_compare_no_null(tmp->line, "C") < 0 
			&& !ft_is_the_whole_line_space(tmp->line))
		{	
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}