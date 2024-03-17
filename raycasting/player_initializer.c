/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:19 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/17 02:21:23 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	_direction(int c)
{
	if (c == 'E')
		return (0.0);
	else if (c == 'N')
		return (270.0);
	else if (c == 'W')
		return (180.0);
	else
		return (90.0);
}

void	_set_player(char **map, t_player *player, int i, int j)
{
	player->x = j * TILE_SIZE + TILE_SIZE / 2;
	player->y = i * TILE_SIZE + TILE_SIZE / 2;
	player->player_dir = _to_radian(_direction(map[i][j]));
	player->rotation_angle = player->player_dir;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = 7.0;
	player->rotation_speed = 4 * (M_PI / 180);
}

void	_init_player(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				_set_player(map, player, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
