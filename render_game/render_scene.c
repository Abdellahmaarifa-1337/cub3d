/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/30 00:30:56 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

void	draw_walls(t_cub *cub, int x, float lineH)
{
	int		y;
	float	y0;

	y = -1;
	y0 = (float)((float)WIN_HEIGHT) / 2.0f - lineH / 2.0f;
	// while (++y < y0)
	// 	my_mlx_pixel_put(&(cub->img3d), x, y, rgbToInt(cub->idn._c[0], cub->idn._c[1], cub->idn._c[2]));
	// y = -1;
	while (++y < lineH)
		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), WALL);
	while (y0 + y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&(cub->img3d), x, (y0 + y), EMPTY);
		y++;
	}
}

int render_scene(t_cub *cub)
{
	int	i;
	float	lineH;
	float	ca;

	my_mlx_clear_image(&(cub->img3d), WIN_WIDHT, WIN_HEIGHT);
	i = 0;
	while (i < WIN_WIDHT)
	{
		ca = PLY.pa - cub->rays[i].pa;
		if (ca < 0)
			ca += 2 * PI;
		else if (ca > 2 * PI)
			ca -= 2 * PI;
		cub->rays[i].ray_dist *= cos(ca);
		lineH = (float)(CELL * WIN_HEIGHT) / cub->rays[i].ray_dist;
		if (lineH > WIN_HEIGHT)
			lineH = WIN_HEIGHT;
		draw_walls(cub, i, lineH);
		i++;
	}
	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
	return 0;
}
