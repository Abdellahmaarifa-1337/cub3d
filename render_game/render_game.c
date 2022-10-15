/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/15 11:13:17 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void render_game(t_cub *cub)
{
	void *mlx;
	void *mlx_win;

	(void) cub;
	int i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	while (i++ < 700)
		mlx_pixel_put(mlx, mlx_win, i, i, 0xffffffff);
	mlx_loop(mlx);
}