/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:07 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/15 05:35:08 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_ray_facing_up(double radian)
{
	return (!_ray_facing_down(radian));
}

int	_ray_facing_down(double radian)
{
	if (radian > 0 && radian < M_PI)
		return (1);
	return (0);
}

int	_ray_facing_right(double radian)
{
	if (radian < M_PI * 0.5 || radian > M_PI * 1.5)
		return (1);
	return (0);
}

int	_ray_facing_left(double radian)
{
	return (!_ray_facing_right(radian));
}
