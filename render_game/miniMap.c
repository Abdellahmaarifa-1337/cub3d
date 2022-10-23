/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/23 12:22:09 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

double	get_player_view_angle(t_cub *cub, int i, int j)
{
	if (MAP.data[i][j] == 'N')
		return ((3 * PI) / 2);
	if (MAP.data[i][j] == 'S')
		return (PI / 2);
	if (MAP.data[i][j] == 'E')
		return (0);
	else
		return (PI);
}

void	set_map_attribute(t_cub *cub)
{
	size_t	i;
	size_t	j;

	MAP.width = 0;
	MAP.height = 0;
	i = 0;
	while (MAP.data[i])
	{
		j = 0;
		while (MAP.data[i][j])
		{
			if (ft_strchr("NSWE", MAP.data[i][j]))
			{
				PLY.x = j * CELL + (float)((float)CELL / 2);
				PLY.y = i * CELL + (float)((float)CELL / 2);
				PLY.pa = get_player_view_angle(cub, i, j);
				MAP.data[i][j] = '0';
			}
			j++;
		}
		if (MAP.width < j)
			MAP.width = j;
		i++;
	}
	MAP.height = i;
}

void	draw_line(t_cub *cub, float pa)
{
	int		pixels;
	float	dx;
	float	dy;
	float	px;
	float	py;

	dx = cos(pa) * 5 * (CELL / 2);
	dy = sin(pa) * 5 * (CELL / 2);
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	px = PLY.x;
	py = PLY.y;
	while (pixels)
	{
		my_mlx_pixel_put(cub, px, py, LINE);
		px += dx;
		py += dy;
		--pixels;
	}
}

void	putPixels(t_cub *cub, size_t i[2], size_t axe[2], int unit)
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
				my_mlx_pixel_put(cub, x, y, WALL);
			else
				my_mlx_pixel_put(cub, x, y, EMPTY);
			x++;
		}
		y++;
	}
}

void	putPlayer(t_cub *cub)
{
	int	x = 0;
	int	y = 0;

	y = - (CELL / 12);
	while (y < (CELL / 12))
	{
		x = - (CELL / 12);
		while (x < (CELL / 12))
		{
			my_mlx_pixel_put(cub, PLY.x + x, PLY.y + y, PLAYER);
			x++;
		}
		y++;
	}
}

void	renderingTheMap(t_cub* cub)
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
				putPixels(cub, i, axe, 1);
			else if (MAP.data[i[0]][i[1]] == '0'
				|| ft_strchr("NSWE", MAP.data[i[0]][i[1]]))
				putPixels(cub, i, axe, 0);
			i[1]++;
			axe[0] += CELL;
		}
		i[0]++;
		axe[1] += CELL;
	}
}

void	my_mlx_clear_image(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAP.height * CELL) {
		j = 0;
		while (j < MAP.width * CELL) {
			my_mlx_pixel_put(cub, j, i, 0x0);
			j++;
		}
		i++;
	}
}

int	execute_MiniMap(t_cub* cub)
{

	PLY.dx = cos(PLY.pa) * 5;
	PLY.dy = sin(PLY.pa) * 5;
	my_mlx_clear_image(cub);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	renderingTheMap(cub);
	putPlayer(cub);
	draw_line(cub, PLY.pa);
	// 	draw_line(cub, PLY.pa + (PI / 12));
	// 	draw_line(cub, PLY.pa - (PI / 12));
	// 	draw_line(cub, PLY.pa + (PI / 6));
	// 	draw_line(cub, PLY.pa - (PI / 6));
	
	// int	pa;
	// pa = PLY.pa;
	// while (pa >= PLY.pa - (PI / 6))
	// {
	// 	draw_line(cub, pa);
	// 	pa += 0.1;
	// }
	// pa = PLY.pa + 0.1;
	// while (pa <= PLY.pa + (PI / 6))
	// {
	// 	draw_line(cub, pa);
	// 	pa -= 0.1;
	// }
	
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, IMG.img, 0, 0);
	return (0);
}

