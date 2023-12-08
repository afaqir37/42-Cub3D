#include "../cub3d.h"

void	_draw_wall(int x, int y, t_data* data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < TILE_SIZE - 2)
	{
		j = 0;
		while (j < TILE_SIZE - 2)
		{
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	_draw_space(int x, int y, t_data* data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < TILE_SIZE - 2)
	{
		j = 0;
		while (j < TILE_SIZE - 2)
		{
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0x00FF00);
			j++;
		}
		i++;
	}
}


void _draw_map(t_data* data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				_draw_wall(j * TILE_SIZE, i * TILE_SIZE , data);
			else
				_draw_space(j * TILE_SIZE , i * TILE_SIZE , data);
			j++;
		}
		i++;
	}

}