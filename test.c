#include "./mlx/mlx.h"
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













/************************************************************/
/***** Fast Inverse Square Root — A Quake III Algorithm *****/
/************************************************************/

// #include <stdio.h>
// #include <math.h>

// float	rsqrt(float number)
// {
// 	long	i;
// 	float	x2, y;
// 	const float	threehalfs = 1.5F;

// 	x2 = number * 0.5F;
// 	y = number;
// 	i = (long)y;
// 	i = 0x5f3759df - (i >> 1);
// 	y = *(float*) &i;
// 	y = y * (threehalfs - (x2 * y * y));
// 	y = y * (threehalfs - (x2 * y * y));
// 	y = y * (threehalfs - (x2 * y * y));

// 	return y;
// }

// int	main() {
// 	float number = 17;

// 	float x = 1 / rsqrt(number);
// 	float y = sqrt(number);

// 	printf("sqrt  : %f\n", x);
// 	printf("rsqrt : %f\n", y);
	
// 	return 0;
// }



/************************************************************/
/********************* Render 3D Scene **********************/
/************************************************************/

// void	draw_walls(t_cub *cub, int x, float lineH)
// {
// 	int		y;
// 	float	y0;

// 	y = -1;
// 	y0 = (float)((float)WIN_HEIGHT) / 2.0f - lineH / 2.0f;
// 	// while (++y < y0)
// 	// 	my_mlx_pixel_put(&(cub->img3d), x, y, rgbToInt(cub->idn._c[0], cub->idn._c[1], cub->idn._c[2]));
// 	// y = -1;
// 	while (++y < lineH)
// 		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), WALL);
// 	while (y0 + y < WIN_HEIGHT)
// 	{
// 		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), EMPTY);
// 		y++;
// 	}
// }

// int render_scene(t_cub *cub)
// {
// 	int	i;
// 	float	lineH;
// 	float	ca;

// 	my_mlx_clear_image(&(cub->img3d), WIN_HEIGHT, WIN_WIDHT);
// 	i = 0;
// 	while (i < WIN_WIDHT)
// 	{
// 		ca = PLY.pa - cub->rays[i].pa;
// 		if (ca < 0)
// 			ca += 2 * PI;
// 		else if (ca > 2 * PI)
// 			ca -= 2 * PI;
// 		cub->rays[i].ray_dist *= cos(ca);
// 		lineH = (float)(CELL * WIN_HEIGHT) / cub->rays[i].ray_dist;
// 		if (lineH > WIN_HEIGHT)
// 			lineH = WIN_HEIGHT;
// 		draw_walls(cub, i, lineH);
// 		i++;
// 	}
// 	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
// 	return (0);
// }
