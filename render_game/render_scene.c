/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/06 13:31:12 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

// void	draw_walls(t_cub *cub, int x, float lineH)
// {
// 	int		y;
// 	float	y0;

// 	y = -1;
// 	y0 = (float)((float)WIN_HEIGHT) / 2.0f - lineH / 2.0f;
// 	// while (++y < y0)
// 	// 	my_mlx_pixel_put(&(cub->img3d), x, y, rgbToInt(cub->idn._c[0], cub->idn._c[1], cub->idn._c[2]));
// 	// y = -1;
// 	while (++y < lineH)
// 		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), WALL);
// 	while (y0 + y < WIN_HEIGHT)
// 	{
// 		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), EMPTY);
// 		y++;
// 	}
// }

// int render_scene(t_cub *cub)
// {
// 	int	i;
// 	float	lineH;
// 	float	ca;

// 	my_mlx_clear_image(&(cub->img3d), WIN_HEIGHT, WIN_WIDHT);
// 	i = 0;
// 	while (i < WIN_WIDHT)
// 	{
// 		ca = PLY.pa - cub->rays[i].pa;
// 		if (ca < 0)
// 			ca += 2 * PI;
// 		else if (ca > 2 * PI)
// 			ca -= 2 * PI;
// 		cub->rays[i].ray_dist *= cos(ca);
// 		lineH = (float)(CELL * WIN_HEIGHT) / cub->rays[i].ray_dist;
// 		if (lineH > WIN_HEIGHT)
// 			lineH = WIN_HEIGHT;
// 		draw_walls(cub, i, lineH);
// 		i++;
// 	}
// 	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
// 	return (0);
// }

#define DPP 255
#define SH	3*CELL

void draw_slice(t_cub *cub, int psh, int i)
{
	int index;
	int	end;
	int x;
	double size;
	int start;
	int reminder;

	 if (psh > WIN_HEIGHT)
	 {
		//start = psh - WIN_HEIGHT;
		reminder = (psh - WIN_HEIGHT) / 2;
	 	psh = WIN_HEIGHT;
	 }
	index = WIN_HEIGHT / 2 - psh / 2;
	end = index + psh;
	// if (index < 0)
	// 	index = start;
	// if (end > WIN_HEIGHT)
	// 	end = WIN_HEIGHT;
	x = 0;
	while (x < index)
	{
		my_mlx_pixel_put(&(cub->img3d), i , x, WALL);
		x++;
	}
	start = index;
	while (index < end && index < WIN_HEIGHT)
	{
		size = (double)(index - start) / psh;
		if (psh + reminder*2 > WIN_HEIGHT)
		{
			size = (double)(index - start + reminder) / (psh + (reminder * 2));
		}
		my_mlx_pixel_put(&(cub->img3d), i , index, get_color_from_textuer(cub, i, size));
		index++;
	}
	while (end < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&(cub->img3d), i , end, PRUPLE);
		end++;
	}
}


int render_scene(t_cub *cub)
{
	double		dp;
	double		an;
	double		dist;
	int			i;

	my_mlx_clear_image(&(cub->img3d),WIN_HEIGHT, WIN_WIDHT);
	i = 0;
	dp = (float)(PI / (3.0 * (float)WIN_WIDHT));
	an = PLY.pa - PI / 6;
	while (an < PLY.pa + PI / 6 && i < WIN_WIDHT)
	{
		cub->map.ray_pa = an;
		dist = get_ray_dist(cub);
		draw_slice(cub, ((float)SH / dist) * (float)DPP, i);
		an += dp;
		i++;
	}

	//exit(1);
	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
	return 0;
}
