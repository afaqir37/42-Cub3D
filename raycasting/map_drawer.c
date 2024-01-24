#include "../cub3d.h"

#define DARK_GREEN 0x00FF00
void	_draw_wall(int x, int y, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILE_SIZE - 1)
	{
		j = 0;
		while (j < TILE_SIZE - 1)
		{
			//mlx_pixel_put(data->mlx, data->win, x + i, y + j, DARK_RED);
			my_mlx_pixel_put(data, x + i, y + j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	_draw_space(int x, int y, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILE_SIZE - 2)
	{
		j = 0;
		while (j < TILE_SIZE - 2)
		{
			my_mlx_pixel_put(data, x + i, y + j, DARK_GREEN);
			j++;
		}
		i++;
	}
}

void	_draw_square(int x_center, int y_center, int size, t_data *data)
{
	int x, y;
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < size; y++)
		{
			my_mlx_pixel_put(data, x_center + x, y_center + y, 0x0000FF);
		}
	}
}

void	_draw_map(t_data *data)
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
				_draw_wall(j * TILE_SIZE, i * TILE_SIZE, data);
			else
				_draw_space(j * TILE_SIZE, i * TILE_SIZE, data);

			j++;
		}
		i++;
	}

	//_draw_square(data->player.x, data->player.y, 20, data);

}