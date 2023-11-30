#include "cub3d.h"

int main(int argc, char **argv) 
{
	void *mlx;
	void *win;
    t_file *file;
    t_info *info;

    if (ft_parse_args(argc, argv, &info, &file))
        return (1);
	mlx = mlx_init();
	if (!mlx)
	{
		perror("fail");
		return -1;
	}
	
	win = mlx_new_window(mlx, 400, 400, "test");
	if (!win)
	{
		perror("fail");
		return -1;
	}
	mlx_loop(mlx);
}
