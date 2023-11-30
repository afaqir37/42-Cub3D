#include "cub3d.h"
#define SQUARE_SIZE 59

void _draw_square(void* mlx, void* win, int x, int y, int color)
{
    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            mlx_pixel_put(mlx, win, x + i, y + j, color);
        }
    }
}

void _draw_map(void* mlx, void* win, char grid[][7], int map_width, int map_height)
{
    for (int i = 1; i < map_height; i++) {
        for (int j = 1; j < map_width; j++) {
            if (grid[i][j] == '1')
                _draw_square(mlx, win, j * SQUARE_SIZE, i * SQUARE_SIZE, 0xFFFFFF);
            else 
                _draw_square(mlx, win, j * SQUARE_SIZE, i * SQUARE_SIZE, 0x000000);
        }
    }
}

int main()
{
	// void *mlx;
	// void *win;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 6*SQUARE_SIZE, 5*SQUARE_SIZE, "The_Grid");
	
    // char map[5][7] = {
    //     "111011",
    //     "100101",
    //     "101001",
    //     "1100N1",
    //     "111111"
    // };
   // _draw_map(mlx, win, map, 6, 5);

    //mlx_loop(mlx);
}