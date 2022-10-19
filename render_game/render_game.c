/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/19 02:52:36 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "miniMap.h"

void render_game(t_cub *cub)
{
	void*	mlx = NULL;
	void*	mlx_win;

	mlx_win = mlx_new_window(mlx, MAP.width * CELL, MAP.height * CELL, "miniMap");

	mlx = mlx_init();
	execute_MiniMap(mlx, cub);
	// mlx_key_hook(mlx_win, player_moves, cub);
	
	// (void)cub;
	// int i = 0;
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// while (i++ < 1080)
	// {
	// 	int j = 0;
	// 	while (j < 1920)
	// 	{
	// 		/* code */
	// 		mlx_pixel_put(mlx, mlx_win, i, j, WALL);
	// 		j++;
	// 	}
	// }

	mlx_loop(mlx);
}