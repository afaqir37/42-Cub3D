/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:03 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/15 05:41:04 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	_horizontal_intersect(t_intersection *inter, t_data *data,
		float ray_angle, t_direction dir)
{
	inter->yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (dir.down)
		inter->yintercept += TILE_SIZE;
	inter->xintercept = data->player.x + (inter->yintercept - data->player.y)
		/ tan(ray_angle);
	inter->ystep = TILE_SIZE;
	if (dir.up)
		inter->ystep *= -1;
	inter->xstep = inter->ystep / tan(ray_angle);
	if (dir.right && inter->xstep < 0)
		inter->xstep *= -1;
	if (dir.left && inter->xstep > 0)
		inter->xstep *= -1;
	inter->next_X = inter->xintercept;
	inter->next_Y = inter->yintercept;
}

void	_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter,
		int up)
{
	float	y_check;

	while (1)
	{
		y_check = inter->next_Y;
		if (up)
			y_check -= 1;
		if (_has_wall_at(inter->next_X, y_check, data))
		{
			horz->wall = 1;
			horz->wall_hit_x = inter->next_X;
			horz->wall_hit_y = inter->next_Y;
			break ;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
		}
	}
}

void	_vertical_intersect(t_intersection *inter, t_data *data,
		float ray_angle, t_direction dir)
{
	inter->xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (dir.right)
		inter->xintercept += TILE_SIZE;
	inter->yintercept = data->player.y + tan(ray_angle) * (inter->xintercept
			- data->player.x);
	inter->xstep = TILE_SIZE;
	if (dir.left)
		inter->xstep *= -1;
	inter->ystep = tan(ray_angle) * inter->xstep;
	if (dir.up && inter->ystep > 0)
		inter->ystep *= -1;
	if (dir.down && inter->ystep < 0)
		inter->ystep *= -1;
	inter->next_X = inter->xintercept;
	inter->next_Y = inter->yintercept;
}

void	_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter,
		int left)
{
	float	x_check;

	while (1)
	{
		x_check = inter->next_X;
		if (left)
			x_check -= 1;
		if (_has_wall_at(x_check, inter->next_Y, data))
		{
			vert->wall = 1;
			vert->wall_hit_x = inter->next_X;
			vert->wall_hit_y = inter->next_Y;
			break ;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
		}
	}
}
