/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/27 02:09:19 by mkabissi         ###   ########.fr       */
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

void	putPlayer(t_cub *cub, float px, float py)
{
	int	x;
	int	y;

	y = - (CELL / 12);
	while (y < (CELL / 12))
	{
		x = - (CELL / 12);
		while (x < (CELL / 12))
		{
			my_mlx_pixel_put(cub, px + x, py + y, PLAYER);
			x++;
		}
		y++;
	}
}


int get_ray_distance(t_cub *cub)
{
	int	ray_h[2];
	int ray_v[2];
	int dist_h;
	int dist_v;
	int dist;

	set_vertical_ray(cub, ray_v);
	set_horizontal_ray(cub, ray_h);
	dist_h = sqrt((ray_h[0] - PLY.x)*(ray_h[0] - PLY.x) + (ray_h[1] - PLY.y) * (ray_h[1] - PLY.y));
	dist_v = sqrt((ray_v[0] - PLY.x)*(ray_v[0] - PLY.x) + (ray_v[1] - PLY.y) * (ray_v[1] - PLY.y));
	// printf("ray hor : %d\n", dist_h);
	// printf("ray vec : %d\n", dist_v);
	if (dist_v < dist_h)
		dist = dist_v;
	else
		dist = dist_h;
	if (ray_h[0] == -1 && ray_h[1] == -1)
	{
		dist = dist_v;
		dist_h = 0;
	}
	if (ray_v[0] == -1 && ray_v[1] == -1)
	{
		dist = dist_h;
		dist_v = 0;
	}
	return (dist);
}

void	draw_line(t_cub *cub, float an)
{
	float	dx;
	float	dy;
	float	px;
	float	py;
	int		dist;

	cub->map.ray_pa = an;
	if (cub->map.ray_pa < 0)
		cub->map.ray_pa += 2 * PI;
	else if (cub->map.ray_pa > 2*PI)
		cub->map.ray_pa -= 2 * PI;
	dist = get_ray_distance(cub);
	dx = cos(cub->map.ray_pa);
	dy = sin(cub->map.ray_pa);
	px = PLY.x;
	py = PLY.y;
	while (dist)
	{
		if (is_out(cub, px, py))
			break;
		my_mlx_pixel_put(cub, px, py, LINE);
		px += dx;
		py += dy;
		--dist;
	}
}

void draw_rays(t_cub *cub)
{
	float dp;
	float an;
	
	//float final = cub->map.ray_pa + 0.5;
	// draw_line(cub);
	//cub->map.ray_pa += 0.6;
	// while (cub->map.ray_pa > 2 * PI)
	// 	cub->map.ray_pa -= 2 * PI;
	//printf("angle: %f\n", cub->map.ray_pa);
	//draw_line(cub);
	dp = (float)(PI / (3.0 * (float)WIN_WIDHT));
	// printf("....%.152f\n", dp);
	an = PLY.pa;
	an -= PI / 6;
	while (an < PLY.pa + PI / 6)
	{
		draw_line(cub, an);
		an += dp;
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
	putPlayer(cub, PLY.x, PLY.y);
	draw_rays(cub);
	//draw_line(cub, PLY.pa);
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

