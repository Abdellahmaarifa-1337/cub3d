/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/22 12:50:57 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "miniMap.h"
#include "../manage_player/manage_player.h"

int	ft_close()
{
	exit(0);
	return (0);
}

// void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = IMG.addr + (y * IMG.line_length + x * (IMG.bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, MAP.width * CELL,
		MAP.height * CELL, "miniMap");
	IMG.img = mlx_new_image(cub->mlx, MAP.width * CELL, MAP.height * CELL);
	IMG.addr = mlx_get_data_addr(IMG.img, &(IMG.bits_per_pixel), &(IMG.line_length),
		&(IMG.endian));
	size_t i = 0;
	size_t j = 0;
	i = 0;
	while (i <  MAP.height * CELL)
	{
		j = 0;
		while(j < MAP.width * CELL)
		{
			_my_mlx_pixel_put(&(cub->img),i, j , WALL);
			j++;
		}
		i++;
	}
	// my_mlx_pixel_put(cub, 500, 500, PLAYER);
	// mlx_loop_hook(cub->mlx, execute_MiniMap, cub);
	// mlx_hook(cub->mlx_win, 2, 1L << 0, player_moves, cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, IMG.img, 0, 0);
	// mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_loop(cub->mlx);
}