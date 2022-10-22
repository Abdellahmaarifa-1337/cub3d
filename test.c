#include <stdio.h>
#include "minilibx/mlx.h"



int main()
{
	void *mlx, *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "hi");
	mlx_loop(mlx);
	return 0;
}

