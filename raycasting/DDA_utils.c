#include "../cub3d.h"

int ft_ret_ptr_nbr(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}


int ft_max_strlen(char **str)
{
	int i;
	int max;

	i = 0;
	max = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strlen(str[i]) > max)
			max = ft_strlen(str[i]);
		i++;
	}
	return (max);
}

void	_horizontal_intersect(t_intersection* inter, t_data* data, float ray_angle, t_direction dir)
{

	// 		if (fabs(ray_angle - M_PI / 2) < 0.00001 || fabs(ray_angle - 3 * M_PI / 2) < 0.00001 || fabs(ray_angle) < 0.00001 || fabs(ray_angle - M_PI) < 0.00001 || fabs(ray_angle - 2 * M_PI) < 0.00001) {
	// 	ray_angle += 0.0000001;
	// }
	inter->yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (dir.down)
		inter->yintercept += TILE_SIZE;
	
	inter->xintercept = data->player.x + (inter->yintercept - data->player.y) / tan(ray_angle);
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

void	_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter, float ray_angle, int up)
{
	float y_check;

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
			break;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
	
		}
	}
}

void	_vertical_intersect(t_intersection* inter, t_data* data, float ray_angle, t_direction dir)
{

	int screen_width = ft_max_strlen(data->map) * TILE_SIZE;
	int screen_height = ft_ret_ptr_nbr(data->map) * TILE_SIZE;
	// 	if (fabs(ray_angle - M_PI / 2) < 0.00001 || fabs(ray_angle - 3 * M_PI / 2) < 0.00001 || fabs(ray_angle) < 0.00001 || fabs(ray_angle - M_PI) < 0.00001 || fabs(ray_angle - 2 * M_PI) < 0.00001) {
	// 	ray_angle += 0.0000001;
	// }

	inter->xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (dir.right)
		inter->xintercept += TILE_SIZE;
	inter->yintercept = data->player.y + tan(ray_angle) * (inter->xintercept - data->player.x);
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

void	_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter, float ray_angle, int left)
{
	float x_check;

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
			break;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
		}
	}   
}