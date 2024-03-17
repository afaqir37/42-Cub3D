/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:29 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 02:21:23 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	_to_radian(float degree)
{
	return (degree * M_PI / 180);
}

float	_to_degree(float radian)
{
	return (radian * 180 / M_PI);
}

float	_normalize_angle(float radian_angle)
{
	radian_angle = remainder(radian_angle, 2 * M_PI);
	if (radian_angle < 0)
		radian_angle += 2 * M_PI;
	return (radian_angle);
}
