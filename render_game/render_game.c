/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/10 16:55:40 by mkabissi         ###   ########.fr       */
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

void*	get_image(t_cub *cub, char *img_path, int *d)
{
	void*	img;

	img = mlx_xpm_file_to_image(cub->mlx, img_path, d, d);
	if (!img)
	{
		ft_putstr_fd(img_path, 2);
		ft_putendl_fd(" : Invalide file", 2);
		exit(1);
	}
	return (img);
}

void	init_textures(t_cub *cub, int *d)
{
	// NO
	TEX[0].img = get_image(cub, IDN._no, d);
	TEX[0].addr = mlx_get_data_addr(TEX[0].img, &(TEX[0].bits_per_pixel),
	 	&(TEX[0].line_length), &(TEX[0].endian));
	// SO
	TEX[1].img = get_image(cub, IDN._so, d);
	TEX[1].addr = mlx_get_data_addr(TEX[1].img, &(TEX[1].bits_per_pixel),
	 	&(TEX[1].line_length), &(TEX[1].endian));
	// EA
	TEX[2].img = get_image(cub, IDN._ea, d);
	TEX[2].addr = mlx_get_data_addr(TEX[2].img, &(TEX[2].bits_per_pixel),
	 	&(TEX[2].line_length), &(TEX[2].endian));
	// WE
	TEX[3].img = get_image(cub, IDN._we, d);
	TEX[3].addr = mlx_get_data_addr(TEX[3].img, &(TEX[3].bits_per_pixel),
	 	&(TEX[3].line_length), &(TEX[3].endian));
}

void render_game(t_cub *cub)
{
	int	d;

	init_miniMap(cub);
	init_3d(cub);
	init_textures(cub, &d);

	// for(int i = 0; i < 30; i++)

	// 	dprintf(2, "%f from %f x : %d, y : %d\n", cub->rays[i].ray_dist, cub->rays[i].ray_dist, cub->rays[i].x, cub->rays[i].y);
	// exit(1);

	mlx_loop_hook(cub->mlx, execute_MiniMap, cub);
	
	// 3d hooks
	mlx_loop_hook(cub->mlx3d, render_scene, cub);
	
	// render_scene(cub);
	mlx_hook(cub->mlx3d_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx3d_win, 3, 1L << 1, released_keys, cub);

	// Mouse Hooks
	cub->mouse_on = 0;
	mlx_hook(cub->mlx3d_win, 6, 0L, mouse_hook, cub);

	// Close
	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_hook(cub->mlx3d_win, 17, 1L << 5, ft_close, cub);

	mlx_loop(cub->mlx);
	mlx_loop(cub->mlx3d);
} 