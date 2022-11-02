/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 11:22:04 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "miniMap.h"
#include "../manage_player/manage_player.h"

void	initializing_keys(t_cub *cub)
{
	cub->keys[0] = 0;
	cub->keys[1] = 0;
	cub->keys[2] = 0;
	cub->keys[3] = 0;
	cub->keys[4] = 0;
	cub->keys[5] = 0;
	cub->prev_x_mouse = WIN_WIDHT / 2;
}

int	ft_close()
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	init_miniMap(t_cub *cub)
{
	initializing_keys(cub);
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, MAP.width * CELL,
		MAP.height * CELL, "miniMap");
	// cub->mlx_win = mlx_new_window(cub->mlx, 1080, 720, "miniMap");
	IMG.img = mlx_new_image(cub->mlx, MAP.width * CELL, MAP.height * CELL);
	IMG.addr = mlx_get_data_addr(IMG.img, &IMG.bits_per_pixel, &IMG.line_length,
		&IMG.endian);
};

void	init_3d(t_cub *cub)
{
	cub->mlx3d = mlx_init();
	cub->mlx3d_win = mlx_new_window(cub->mlx, WIN_WIDHT ,
		WIN_HEIGHT , "miniMap");
	cub->img3d.img = mlx_new_image(cub->mlx, WIN_WIDHT , WIN_HEIGHT );
	cub->img3d.addr = mlx_get_data_addr(cub->img3d.img, &cub->img3d.bits_per_pixel, &cub->img3d.line_length,
		&cub->img3d.endian);
}

void render_game(t_cub *cub)
{
	int d;
	// textures 
	init_miniMap(cub);
	init_3d(cub);
	(cub->textuers).img = mlx_xpm_file_to_image(cub->mlx, "./textuer/wall.xpm", &d, &d);
	(cub->textuers).addr = mlx_get_data_addr(cub->textuers.img, &(cub->textuers.bits_per_pixel),
	 	&(cub->textuers.line_length), &(cub->textuers.endian));
	// for(int i = 0; i < 30; i++)

	// 	dprintf(2, "%f from %f x : %d, y : %d\n", cub->rays[i].ray_dist, cub->rays[i].ray_dist, cub->rays[i].x, cub->rays[i].y);
	// exit(1);
	mlx_loop_hook(cub->mlx, execute_MiniMap, cub);
	//execute_MiniMap(cub);
	// mlx_hook(cub->mlx_win, 2, 1L << 0, pressed_keys, cub);
	// mlx_hook(cub->mlx_win, 3, 1L << 1, released_keys, cub);
	// mlx_hook(cub->mlx_win, 4, 1L<<2, mouse_switcher, cub);
	// mlx_hook(cub->mlx_win, 6, 0L, mouse_hook, cub);
	
	cub->mouse_on = 0;
	mlx_hook(cub->mlx3d_win, 4, 1L<<2, mouse_switcher, cub);
	mlx_hook(cub->mlx3d_win, 6, 0L, mouse_hook, cub);

	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);


	// 3d hooks
	mlx_loop_hook(cub->mlx3d, render_scene, cub);
	//render_scene(cub);
	mlx_hook(cub->mlx3d_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx3d_win, 3, 1L << 1, released_keys, cub);
	mlx_loop(cub->mlx);
	mlx_loop(cub->mlx3d);
} 