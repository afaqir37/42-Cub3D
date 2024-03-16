/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:14 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 20:15:32 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		dst = img.addr + (y * img.size_line + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

size_t	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
