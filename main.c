#include "cub3d.h"

int main() 
{
	void *mlx;
	void *win;

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