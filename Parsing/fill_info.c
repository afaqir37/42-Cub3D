/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:29:01 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 04:15:21 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_infos_existance(t_file *file)
{
	int	error_code;

	error_code = ft_check_sentence_existance(file, "NO");
	if (error_code < 0)
	{
		if (error_code == -2)
			return (ft_wr("Invalid File: Provide Only 1 identifier each!"));
		return (ft_wr("Missing info : Provide one North texture Identifier!"));
	}
	if (ft_check_sentence_existance(file, "SO") < 0)
		return (ft_wr("Missing info : Provide one South texture Identifier!"));
	if (ft_check_sentence_existance(file, "WE") < 0)
		return (ft_wr("Missing info : Provide one West texture Identifier!"));
	if (ft_check_sentence_existance(file, "EA") < 0)
		return (ft_wr("Missing info : Provide one East texture Identifier!"));
	if (ft_check_sentence_existance(file, "F") < 0)
		return (ft_wr("Missing info : Provide one Floor color Identifier!"));
	if (ft_check_sentence_existance(file, "C") < 0)
		return (ft_wr("Missing info : Provide one Ceiling color Identifier!"));
	return (0);
}

int	ft_check_info(t_file *file)
{
	if (ft_does_have_content(file, "NO") < 0)
		return (ft_wr("Missing info : Provide a Path for The North texture!"));
	if (ft_does_have_content(file, "SO") < 0)
		return (ft_wr("Missing info : Provide a Path for The South texture!"));
	if (ft_does_have_content(file, "WE") < 0)
		return (ft_wr("Missing info : Provide a Path for The West texture!"));
	if (ft_does_have_content(file, "EA") < 0)
		return (ft_wr("Missing info : Provide a Path for The East texture!"));
	if (ft_does_have_content(file, "F") < 0)
		return (ft_wr("Missing info : Provide a Path Floor color!"));
	if (ft_does_have_content(file, "C") < 0)
		return (ft_wr("Missing info : Provide a Path Ceiling color!"));
	return (0);
}

void	fill_directions(t_info **tm, t_file *file)
{
	t_info	*tmp;

	tmp = (*tm);
	tmp->NO = ft_sbstr(ft_rnwi(file, "NO")->line, ft_rs(ft_rnwi(file,
					"NO")->line, "NO"), ft_return_end(ft_rnwi(file, "NO")->line,
				"NO") - ft_rs(ft_rnwi(file, "NO")->line, "NO"));
	tmp->SO = ft_sbstr(ft_rnwi(file, "SO")->line, ft_rs(ft_rnwi(file,
					"SO")->line, "SO"), ft_return_end(ft_rnwi(file, "SO")->line,
				"SO") - ft_rs(ft_rnwi(file, "SO")->line, "SO"));
	tmp->WE = ft_sbstr(ft_rnwi(file, "WE")->line, ft_rs(ft_rnwi(file,
					"WE")->line, "WE"), ft_return_end(ft_rnwi(file, "WE")->line,
				"WE") - ft_rs(ft_rnwi(file, "WE")->line, "WE"));
	tmp->EA = ft_sbstr(ft_rnwi(file, "EA")->line, ft_rs(ft_rnwi(file,
					"EA")->line, "EA"), ft_return_end(ft_rnwi(file, "EA")->line,
				"EA") - ft_rs(ft_rnwi(file, "EA")->line, "EA"));
}

void	fill_colors(t_info **tm, t_file *file)
{
	t_info	*tmp;

	tmp = (*tm);
	tmp->F.r = ft_atf(ft_sbstr(ft_rnwi(file, "F")->line, ft_rs(ft_rnwi(file,
						"F")->line, "F"), ft_return_end(ft_rnwi(file,
						"F")->line, "F") - ft_rs(ft_rnwi(file, "F")->line,
					"F")));
	tmp->F.g = ft_atf(ft_sbstr(ft_strchr(ft_rnwi(file, "F")->line, ',') + 1,
				0, ft_return_end(ft_strchr(ft_rnwi(file, "F")->line, ',') + 1,
					",") - 0));
	tmp->F.b = ft_atf(ft_sbstr(ft_strchr(ft_strchr(ft_rnwi(file, "F")->line,
						',') + 1, ',') + 1, 0,
				ft_return_end(ft_strchr(ft_strchr(ft_rnwi(file, "F")->line, ',')
						+ 1, ',') + 1, ",") - 0));
	tmp->C.r = ft_atf(ft_sbstr(ft_rnwi(file, "C")->line, ft_rs(ft_rnwi(file,
						"C")->line, "C"), ft_return_end(ft_rnwi(file,
						"C")->line, "C") - ft_rs(ft_rnwi(file, "C")->line,
					"C")));
	tmp->C.g = ft_atf(ft_sbstr(ft_strchr(ft_rnwi(file, "C")->line, ',') + 1,
				0, ft_return_end(ft_strchr(ft_rnwi(file, "C")->line, ',') + 1,
					",") - 0));
	tmp->C.b = ft_atf(ft_sbstr(ft_strchr(ft_strchr(ft_rnwi(file, "C")->line,
						',') + 1, ',') + 1, 0,
				ft_return_end(ft_strchr(ft_strchr(ft_rnwi(file, "C")->line, ',')
						+ 1, ',') + 1, ",") - 0));
}

int	ft_fill_tmp(t_info **info, t_file *file)
{
	t_info	*tmp;

	tmp = malloc(sizeof(t_info));
	if (!tmp)
		return (ft_wr("Data Creation Failed: Abort!"));
	(*tmp) = (t_info){0};
	fill_directions(&tmp, file);
	fill_colors(&tmp, file);
	(*info) = tmp;
	return (0);
}

// int	ft_fill_tmp(t_info **info, t_file *file)
// {
// 	t_info *tmp;

// 	tmp = malloc(sizeof(t_info));
// 	if (!tmp)
// 		return (ft_wr("Data Creation Failed: Abort!"));
// 	tmp->NO = ft_sbstr(ft_rnwi(file, "NO")->line, ft_rs(ft_rnwi(file,
// 					"NO")->line, "NO"), ft_return_end(ft_rnwi(file, "NO")->line,
// 				"NO") - ft_rs(ft_rnwi(file, "NO")->line, "NO"));
// 	tmp->SO = ft_sbstr(ft_rnwi(file, "SO")->line, ft_rs(ft_rnwi(file,
// 					"SO")->line, "SO"), ft_return_end(ft_rnwi(file, "SO")->line,
// 				"SO") - ft_rs(ft_rnwi(file, "SO")->line, "SO"));
// 	tmp->WE = ft_sbstr(ft_rnwi(file, "WE")->line, ft_rs(ft_rnwi(file,
// 					"WE")->line, "WE"), ft_return_end(ft_rnwi(file, "WE")->line,
// 				"WE") - ft_rs(ft_rnwi(file, "WE")->line, "WE"));
// 	tmp->EA = ft_sbstr(ft_rnwi(file, "EA")->line, ft_rs(ft_rnwi(file,
// 					"EA")->line, "EA"), ft_return_end(ft_rnwi(file, "EA")->line,
// 				"EA") - ft_rs(ft_rnwi(file, "EA")->line, "EA"));
// 	tmp->F.r = ft_atoi(ft_sbstr(ft_rnwi(file, "F")->line, ft_rs(ft_rnwi(file,
// 						"F")->line, "F"), ft_return_end(ft_rnwi(file,
// 						"F")->line, "F") - ft_rs(ft_rnwi(file, "F")->line,
// 					"F")));
// 	tmp->F.g = ft_atoi(ft_sbstr(ft_strchr(ft_rnwi(file, "F")->line, ',') + 1,
//				0,
// 				ft_return_end(ft_strchr(ft_rnwi(file, "F")->line, ',') + 1, ",")
// 				- 0));
// 	tmp->F.b = ft_atoi(ft_sbstr(ft_strchr(ft_strchr(ft_rnwi(file, "F")->line,
//						',')
// 					+ 1, ',') + 1, 0,
// 				ft_return_end(ft_strchr(ft_strchr(ft_rnwi(file, "F")->line, ',')
// 						+ 1, ',') + 1, ",") - 0));
// 	tmp->C.r = ft_atoi(ft_sbstr(ft_rnwi(file, "C")->line, ft_rs(ft_rnwi(file,
// 						"C")->line, "C"), ft_return_end(ft_rnwi(file,
// 						"C")->line, "C") - ft_rs(ft_rnwi(file, "C")->line,
// 					"C")));
// 	tmp->C.g = ft_atoi(ft_sbstr(ft_strchr(ft_rnwi(file, "C")->line, ',') + 1,
//				0,
// 				ft_return_end(ft_strchr(ft_rnwi(file, "C")->line, ',') + 1, ",")
// 				- 0));
// 	tmp->C.b = ft_atoi(ft_sbstr(ft_strchr(ft_strchr(ft_rnwi(file, "C")->line,
//						',')
// 					+ 1, ',') + 1, 0,
// 				ft_return_end(ft_strchr(ft_strchr(ft_rnwi(file, "C")->line, ',')
// 						+ 1, ',') + 1, ",") - 0));
// 	(*info) = tmp;
// 	return (0);
// }