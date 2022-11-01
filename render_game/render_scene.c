/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/01 17:19:55 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

#define DPP 255
#define SH	3*CELL

void draw_slice(t_cub *cub, int psh, int i, int is)
{
	int start;
	int	end;

	if (psh > WIN_HEIGHT)
		psh = WIN_HEIGHT;
	start = WIN_HEIGHT / 2 - psh / 2;
	end = start + psh;
	while (start < end && start < WIN_HEIGHT && start >= 0)
	{
		// if (is == 1)
		// 	my_mlx_pixel_put(&(cub->img3d), i, start, PLAYER);
		// else
		// 	my_mlx_pixel_put(&(cub->img3d), i, start, PRUPLE);
		my_mlx_pixel_put(&(cub->img3d), i , start, get_color_from_textuer(cub, i, start));
		start++;
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
		draw_slice(cub, ((float)SH / dist) * (float)DPP, i, is_ver);
		an += dp;
		i++;
	}
	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
	return 0;
}