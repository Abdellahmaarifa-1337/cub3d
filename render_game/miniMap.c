/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/31 18:44:46 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

float	get_player_view_angle(t_cub *cub, int i, int j)
{
	//return (3.850795);
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
			my_mlx_pixel_put(&IMG, px + x, py + y, PLAYER);
			x++;
		}
		y++;
	}
}

float get_dist(t_cub *cub, float x, float y)
{
	return (sqrt((x - PLY.x)*(x - PLY.x) + (y - PLY.y) * (y - PLY.y)));
}

void draw_rays(t_cub *cub)
{
	int		i;
	float	p[2];
	float	d[2];
	float		dist;


	//printf("pa : %f\n", PLY.pa);
	i = 0;
	//printf("pa : %f\n", PLY.pa);
	while (i < WIN_WIDHT + 1)
	{
		// if (i > 0)
		// 	break ;
		d[0] = cos(cub->rays[i].pa);
		d[1] = sin(cub->rays[i].pa);
		p[0] = PLY.x;
		p[1] = PLY.y;
		dist = (cub->rays[i].ray_dist);
		while (get_dist(cub, p[0], p[1]) <= dist)
		{
			if (is_out(cub, p[0], p[1]))
				break;
			my_mlx_pixel_put(&IMG, p[0], p[1], LINE);
			p[0] += d[0];
			p[1] += d[1];
			//--dist;
		}
		// test
		// if (i > 500)
		// 	break ;
		// end test
		i++;
	}
}

void	putPixels(t_cub *cub, size_t i[2], size_t axe[2], int unit)
{
	size_t	x;
	size_t	y;

	y = axe[1];
	while (y < (i[0] + 1) * CELL)
	{
		x = axe[0];
		while (x < (i[1] + 1) * CELL)
		{
			if (unit)
				my_mlx_pixel_put(&IMG, x, y, WALL);
			else
				my_mlx_pixel_put(&IMG, x, y, EMPTY);
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

void	my_mlx_clear_image(t_img *img, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height) {
		j = 0;
		while (j < width) {
			my_mlx_pixel_put(img, j, i, 0x0);
			j++;
		}
		i++;
	}
}

void init_rays(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < WIN_WIDHT + 1)
	{
		cub->rays[i].ray_dist = 0;
		i++;
	}
}

int	execute_MiniMap(t_cub* cub)
{
	PLY.dx = cos(PLY.pa) * 5;
	PLY.dy = sin(PLY.pa) * 5;
	my_mlx_clear_image(&(cub->img), MAP.height * CELL, MAP.width * CELL);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	
	renderingTheMap(cub);
	putPlayer(cub, PLY.x, PLY.y);
	init_rays(cub);
	set_rays(cub);


	// for(int u = 0; u < 30; u++)
	// {
	// 	//cub->rays[u].x = u;
	// 	dprintf(2, "d = %f, x= %d, y= %d\n", cub->rays[u].ray_dist, cub->rays[u].x, cub->rays[u].y);
	// }
	// exit(1);
	draw_rays(cub);
	//render_scene(cub);
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

