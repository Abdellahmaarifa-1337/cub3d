#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_cub {
	void	*mlx;
	void	*win;
	int		keys[6];
}	t_cub;

void	move(t_cub *cub)
{
	if (cub->keys[0] && !cub->keys[1])
		printf("up\t");
	if (cub->keys[1] && !cub->keys[0])
		printf("down\t");
	if (cub->keys[2] && !cub->keys[3])
		printf("right\t");
	if (cub->keys[3] && !cub->keys[2])
		printf("left\t");
	if (cub->keys[4] && !cub->keys[5])
		printf("look right\t");
	if (cub->keys[5] && !cub->keys[4])
		printf("look left\t");
	printf("\n");
}

int	pressed(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->keys[0] = 1;
	if (keycode == 1)
		cub->keys[1] = 1;
	if (keycode == 2)
		cub->keys[2] = 1;
	if (keycode == 0)
		cub->keys[3] = 1;
	if (keycode == 124)
		*(cub->keys + 4) = 1;
	else if (keycode == 123)
		cub->keys[5] = 1;

	if (keycode == 53)
		exit(0);
	else
		move(cub);

	return (0);
}

int released(int keycode, t_cub *cub)
{

	if (keycode == 13)
	{
		cub->keys[0] = 0;
		printf("0.key released\n");
	}
	if (keycode == 1)
	{
		cub->keys[1] = 0;
		printf("1.key released\n");
	}
	if (keycode == 2)
	{
		cub->keys[2] = 0;
		printf("2.key released\n");
	}
	if (keycode == 0)
	{
		cub->keys[3] = 0;
		printf("3.key released\n");
	}
	if (keycode == 124)
	{
		printf("4.key released\n");
		cub->keys[4] = 0;
	}
	if (keycode == 123)
	{
		cub->keys[5] = 0;
		printf("5.key released\n");
	}
	return (0);
}

int	main(void)
{
	t_cub	cub;

	cub.keys[0] = 0;
	cub.keys[1] = 0;
	cub.keys[2] = 0;
	cub.keys[3] = 0;
	cub.keys[4] = 0;
	cub.keys[5] = 0;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, 460, 240, "Hello world!");
	
	mlx_hook(cub.win, 2, 1L<<0, pressed, &cub);
	
	mlx_hook(cub.win, 3, 1L<<1, released, &cub);
	
	mlx_loop(cub.mlx);
	return(0);
}