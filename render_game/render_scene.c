/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 12:36:51 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

#define DPP 255
#define SH	3*CELL

void draw_slice(t_cub *cub, int psh, int i)
{
	int start;
	int	end;
	int x;

	if (psh > WIN_HEIGHT)
		psh = WIN_HEIGHT;
	start = WIN_HEIGHT / 2 - psh / 2;
	end = start + psh;
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;
	x = 0;
	while (x < start)
	{
		my_mlx_pixel_put(&(cub->img3d), i , x, WALL);
		x++;
	}
	while (start < end)
	{
		my_mlx_pixel_put(&(cub->img3d), i , start, get_color_from_textuer(cub, i, 1.0 - (double)(end - start) / psh ));
		start++;
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
	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
	return 0;
}