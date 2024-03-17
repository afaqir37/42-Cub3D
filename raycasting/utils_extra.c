/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:29 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 04:18:58 by agoujdam         ###   ########.fr       */
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

float	_normalize(float radian_angle)
{
	radian_angle = remainder(radian_angle, 2 * M_PI);
	if (radian_angle < 0)
		radian_angle += 2 * M_PI;
	return (radian_angle);
}
