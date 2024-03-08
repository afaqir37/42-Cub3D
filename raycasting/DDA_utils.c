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

void	_horizontal_intersect(t_intersection* inter, t_data* data, float ray_angle)
{

	int screen_width = ft_max_strlen(data->map) * TILE_SIZE;
	int screen_height = ft_ret_ptr_nbr(data->map) * TILE_SIZE;

	inter->yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (_ray_facing_down(ray->angle))
		inter->yintercept += TILE_SIZE;
	
	inter->xintercept = data->player.x + (inter->yintercept - data->player.y) / tan(ray->angle);
	
	inter->xstep = TILE_SIZE / tan(ray->angle);
	if (_ray_facing_right(ray->angle) && inter->xstep < 0)
		inter->xstep *= -1;

	if (_ray_facing_left(ray->angle) && inter->xstep > 0)
		inter->xstep *= -1;
	inter->ystep = TILE_SIZE;
	if (_ray_facing_up(ray->angle))
		inter->ystep *= -1;
	inter->next_X = inter->xintercept;
	inter->next_Y = inter->yintercept;

}

void	_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter, float ray_angle)
{
	float y_check = inter->next_Y

	while (1)
	{
		

		if (_ray_facing_up(ray->angle))
			y_check -= 1;

		if (_has_wall_at(inter->next_X, y_check, data))
		{
			horz->wall = 1;
			horz->wall_hit_X = inter->next_X;
			horz->wall_hit_Y = inter->next_Y;
			break;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
	
		}
	}
}

void	_vertical_intersect(t_intersection* inter, t_data* data, float ray_angle)
{

	int screen_width = ft_max_strlen(data->map) * TILE_SIZE;
	int screen_height = ft_ret_ptr_nbr(data->map) * TILE_SIZE;

	inter->xstep = TILE_SIZE;
	inter->ystep = tan(ray->angle) * TILE_SIZE;
	inter->xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	inter->yintercept = data->player.y + tan(ray->angle) * (inter->xintercept - data->player.x);
	
	if (_ray_facing_right(ray->angle))
		inter->xintercept += TILE_SIZE;
		

	if (_ray_facing_left(ray->angle))
		inter->xstep *= -1;

	

	if (_ray_facing_up(ray->angle) && inter->ystep > 0)
		inter->ystep *= -1;
		

	if (_ray_facing_down(ray->angle) && inter->ystep < 0)
		inter->ystep *= -1;

	inter->next_X = inter->xintercept;
	inter->next_Y = inter->yintercept;

	
    
}

void	_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter, float ray_angle)
{
	float x_check;

	while (1)
	{
		x_check = inter->next_X;
		if (_ray_facing_left(ray->angle))
			x_check -= 1;
		if (_has_wall_at(x_check, inter->next_Y, data))
		{
			vert->wall = 1;
			vert->wall_hit_X = inter->next_X;
			vert->wall_hit_Y = inter->next_Y;
			break;
		}
		else
		{
			inter->next_X += inter->xstep;
			inter->next_Y += inter->ystep;
		}
	}   
}