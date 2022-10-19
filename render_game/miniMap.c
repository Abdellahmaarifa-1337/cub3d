/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/19 14:06:54 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

void	putPixels(void* mlx, void* mlx_win, size_t i[2], size_t axe[2], int unit)
{
	size_t	x;
	size_t	y;

	y = axe[1];
	while (y < (i[0] + 1) * CELL - 1)
	{
		x = axe[0];
		while (x < (i[1] + 1) * CELL - 1)
		{
			if (unit)
				mlx_pixel_put(mlx, mlx_win, x, y, WALL);
			else
				mlx_pixel_put(mlx, mlx_win, x, y, EMPTY);
			x++;
		}
		y++;
	}
}

void	putPlayer(void* mlx, void* mlx_win, t_cub* cub)
{
	size_t	a;
	size_t	x;
	size_t	y;

	a = CELL / 2 - 5;
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			mlx_pixel_put(mlx, mlx_win, PLY.x + a + x, PLY.y + a + y, PLAYER);
			x++;
		}
		y++;
	}
}

void	renderingTheMap(void* mlx, void* mlx_win, t_cub* cub)
{
	size_t	i[2];
	size_t	axe[2];
	i[0] = 0;
	axe[1] = 0;
	while (MAP.data[i[0]])
	{
		i[1] = 0;
		axe[0] = 0;
		while (MAP.data[i[0]][i[1]]) {
			if (MAP.data[i[0]][i[1]] == '1')
				putPixels(mlx, mlx_win, i, axe, 1);
			else if (MAP.data[i[0]][i[1]] == '0'
				|| ft_strchr("NSWE", MAP.data[i[0]][i[1]]))
				putPixels(mlx, mlx_win, i, axe, 0);
			if (ft_strchr("NSWE", MAP.data[i[0]][i[1]]))
				putPlayer(mlx, mlx_win, cub);
			i[1]++;
			axe[0] += CELL;
		}
		i[0]++;
		axe[1] += CELL;
	}
}

void	execute_MiniMap(void* mlx, void* mlx_win, t_cub* cub)
{
	renderingTheMap(mlx, mlx_win, cub);
	// putPlayer(mlx, mlx_win, cub);
}



