#include "../cub3d.h"

double	_direction(int c)
{
	if (c == 'E')
		return (0.0);
	else if (c == 'N')
		return (90.0);
	else if (c == 'W')
		return (180.0);
	else
		return (270.0);
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
				player->x = j * TILE_SIZE + TILE_SIZE/2;
				player->y = i * TILE_SIZE + TILE_SIZE/2;
				player->player_dir = _to_radian(_direction(map[i][j]));
				player->rotation_angle = player->player_dir;
				player->turn_direction = 0;
				player->walk_direction = 0;
				player->move_speed = 4.0;
				player->rotation_speed = 4 * (M_PI / 180);
				return ;
			}
			j++;
		}
		i++;
	}
}
