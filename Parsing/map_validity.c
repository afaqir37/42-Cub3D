#include "../cub3D.h"

int ft_check_map_lenght(t_file *file, int line_start)
{
	t_file 	*tmp;
	int 	last;
	
	last = 0;
	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->index + 1;
	if (last - line_start < 3)
		return (-1);
	return (0);
}

int ft_return_index_of_first_line(t_file *file)
{
	t_file *tmp;
	int i;
	int wall;

	wall = 0;
	tmp = file;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (ft_is_it_a_map_character(tmp->line[i]))	
				i++;
			else
				break ;
		}
		if (tmp->line[i] == '\0' && !ft_is_the_whole_line_space(tmp->line))
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int ft_check_one_player(t_file *file, int line_start)
{
	t_file *tmp;
	int i;
	int counter;

	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	counter = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'N' || tmp->line[i] == 'S' || tmp->line[i] == 'E' || tmp->line[i] == 'W')
				counter++;
			i++;
		}
		tmp = tmp->next;
	}
	if (counter == 0)
		return (-1);
	if (counter > 1)
		return (-2);
	return (0);
}

int ft_check_map_is_closed(t_file *file, int line_start)
{
	t_file *tmp;
	int i;

	i = 0;
	tmp = ft_return_node_with_index(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == '0' || tmp->line[i] == 'N' || tmp->line[i] == 'S' || tmp->line[i] == 'E' || tmp->line[i] == 'W')
			{
				if (i > 0 && (ft_isemptychar(tmp->line[i - 1])))
					return (ft_write_error("one"));
				if (i < ft_strlen(tmp->line) - 1 && (ft_isemptychar(tmp->line[i + 1])))
					return (ft_write_error("two"));
				if (tmp->prev && (((ft_strlen(tmp->prev->line) > i && ((ft_isemptychar(tmp->prev->line[i])))) || ft_strlen(tmp->prev->line) <= i)))
					return (ft_write_error("three"));
				if (tmp->next && (((ft_strlen(tmp->next->line) > i && ((ft_isemptychar(tmp->next->line[i])))) || ft_strlen(tmp->next->line) <= i)))
					return (ft_write_error("four"));
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int ft_check_lines_after(t_file *file, int line_start)
{
	t_file *tmp;
	int i;

	tmp = ft_return_index_line(file, line_start);
	if (tmp == NULL)
		return (-1);
	while (tmp)
	{
		i = 0;
		if ((tmp->line[0] == '\n' && tmp->line[1] == '\0') 
			|| !ft_is_theretwoplus(tmp->line) || ft_is_the_whole_line_space(tmp->line))
		{
			return (-1);
		}
		while (tmp->line[i])
		{
			if (ft_isemptychar(tmp->line[i]))
				i++;
			else if (tmp->line[i] == '1')
				i++;
			else if (tmp->line[i] == '0')
				i++;
			else if (tmp->line[i] == 'N' || tmp->line[i] == 'S' || tmp->line[i] == 'E' || tmp->line[i] == 'W')
				i++;
			else
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int ft_check_map_validity(t_file *file)
{
	int i;
	int error_code;

	if ((i = ft_return_index_of_first_line(file)) < 0)
		return (ft_write_error("\033[31mMap is not valid: Where is the map bro?"));
	if (ft_check_map_lenght(file, i) < 0)
		return (ft_write_error("\033[31mMap is not valid: Chhad l3b tlbnaya?"));
	if (ft_check_lines_after(file, i) < 0)
		return (ft_write_error("\033[31mMap is not valid: Weird Map, Redo it!"));
	if (ft_check_map_is_closed(file, i) < 0)
		return (ft_write_error("\033[31mMap is not valid: Map 3ndek mt9ouba!"));
	if ((error_code = ft_check_one_player(file, i)) < 0)
	{	
		if (error_code == -1)
			return (ft_write_error("\033[31mMap is not valid: Where is the player bro?"));
		if (error_code == -2)
			return (ft_write_error("\033[31mMap is not valid: Bruh, this aint a mutliplayer game!"));
	}
	return (0);
}