/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/19 13:55:07 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "miniMap.h"

void render_game(t_cub *cub)
{
	void*	mlx = NULL;
	void*	mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, MAP.width * CELL, MAP.height * CELL, "miniMap");

	execute_MiniMap(mlx, mlx_win, cub);
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