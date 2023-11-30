#include "../cub3d.h"

int	ft_fill_info(t_info** info, t_file *file)
{
	t_info *tmp;

	if (ft_check_infos_existance(file) < 0)
		return (-1);
	if (ft_check_info(file) < 0)
		return (-1);
	if (ft_check_if_xpm_file_existance(file) < 0)
		return (-1);
	if (ft_check_rgb(file) < 0)
		return (-1);
	if (ft_fill_tmp(info, file) < 0)
		return (-1);
	return (0);
}

int	ft_parse_args(int ac, char **av, t_info **inf, t_file **fle )
{
	t_file *file;
	t_info *info;

	if (ft_error_args(ac, av) < 0)
		return (1);
	ft_intialize_file(&file, open(av[1], O_RDONLY));
	if (file == NULL)
		return (1);
	if (ft_check_if_file_has_lines_filled_with_blank_characters(file) < 0)
		return (ft_write_error("Invalid File: Please Remove Unwanted Lines!") * -1);
	if (ft_fill_info(&info, file) < 0)
		return (1);
	if (ft_check_if_file_has_unwanted_lines(file) < 0)
		return (ft_write_error("Invalid File: Please Remove Unwanted Lines!") * -1);
	ft_print_t_info(info);
	if (ft_check_map_validity(file))
	 	return (1);
	printf("\033[32mMap is valid!\n");
	(*inf) = info;
	(*fle) = file;
	return (0);
}