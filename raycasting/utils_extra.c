/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:29 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/15 05:55:21 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

double	_to_degree(double radian)
{
	return (radian * 180 / M_PI);
}

double	_normalize_angle(double radian_angle)
{
	radian_angle = remainder(radian_angle, 2 * M_PI);
	if (radian_angle < 0)
		radian_angle += 2 * M_PI;
	return (radian_angle);
}
