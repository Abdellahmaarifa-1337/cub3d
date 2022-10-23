/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/23 20:45:05 by mkabissi         ###   ########.fr       */
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

void	ray_drawing(t_cub *cub, float *p, float *d, int pixels)
{
	pixels = sqrt((d[0] * d[0]) + (d[1] * d[1]));
	d[0] /= pixels;
	d[1] /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(cub, p[0], p[1], LINE);
		p[0] += d[0];
		p[1] += d[1];
		--pixels;
	}
}
void	draw_line(t_cub *cub, float pa)
{
	int		pixels;
	float	dl;
	float	d[2];
	float	p[2];

	pixels = 0;
	RAY.rayLenght = 12;
	dl = 12;
	d[0] = 0;
	d[1] = 0;
	p[0] = PLY.x;
	p[1] = PLY.y;
	while (dl > 0)
	{
		d[0] = cos(pa) * RAY.rayLenght;
		d[1] = sin(pa) * RAY.rayLenght;
		if (MAP.data[(int)(p[1] + d[1]) / CELL][(int)(p[0] + d[0]) / CELL] == '0')
		{
			ray_drawing(cub, p, d, pixels);
			printf("px: %d\tpy: %d\n", (int)(p[0]) / CELL, (int)(p[1]) / CELL);
		}
		else
			dl /= 2;
		RAY.rayLenght += dl;
	}
	d[0] = cos(pa) * RAY.rayLenght;
	d[1] = sin(pa) * RAY.rayLenght;
	ray_drawing(cub, p, d, pixels);
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

