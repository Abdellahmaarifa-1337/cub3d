/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/29 13:21:38 by mkabissi         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = IMG.addr + (y * IMG.line_length + x * (IMG.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render_game(t_cub *cub)
{
	initializing_keys(cub);
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, MAP.width * CELL,
		MAP.height * CELL, "miniMap");
	// cub->mlx_win = mlx_new_window(cub->mlx, 1080, 720, "miniMap");
	IMG.img = mlx_new_image(cub->mlx, MAP.width * CELL, MAP.height * CELL);
	IMG.addr = mlx_get_data_addr(IMG.img, &IMG.bits_per_pixel, &IMG.line_length,
		&IMG.endian);
	mlx_loop_hook(cub->mlx, execute_MiniMap, cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, released_keys, cub);
	
	cub->mouse_on = 0;
	mlx_hook(cub->mlx_win, 4, 1L<<2, mouse_switcher, cub);
	mlx_hook(cub->mlx_win, 6, 0L, mouse_hook, cub);

	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_loop(cub->mlx);
}