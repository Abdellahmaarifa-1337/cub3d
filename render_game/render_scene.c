/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/30 21:32:24 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

#define DPP 277
#define SH	3*CELL

void draw_slice(t_cub *cub, int psh, int i, int is)
{
	int j;
	int y;
	// draw up
	j = psh / 2;
	y = WIN_HEIGHT / 2;
	while(j > 0 && y >=0)
	{
		if (is == 1)
			my_mlx_pixel_put(&(cub->img3d), i, y, PLAYER);
		else
			my_mlx_pixel_put(&(cub->img3d), i, y, PRUPLE);
		y--;
		j--;
	}

	// draw down
	j = psh / 2;
	y = WIN_HEIGHT / 2;
	while (j > 0 && y < WIN_HEIGHT)
	{
		if (is == 1)
			my_mlx_pixel_put(&(cub->img3d), i, y, PLAYER);
		else
			my_mlx_pixel_put(&(cub->img3d), i, y, PRUPLE);
		y++;
		j--;
	}
}

int render_scene(t_cub *cub)
{
	int	i;
	float psh;

	my_mlx_clear_image(&(cub->img3d),WIN_HEIGHT, WIN_WIDHT);
	psh = 0;
	i = 0;
	//printf("middle ray: %f\n", cub->rays[539].ray_dist);
	while (i < WIN_WIDHT)
	{
		cub->rays[i].ray_dist = (cub->rays[i].ray_dist * fabs(cos(fabs(PLY.pa - cub->rays[i].pa))));

		if (!cub->rays[i].ray_dist)
		{
			i++;
			continue ;
		}
		psh = (float)((((float)SH / cub->rays[i].ray_dist) * (float)DPP));
		//dprintf(2, "%f from %f x : %d, y : %d\n", psh, cub->rays[i].ray_dist, cub->rays[i].x, cub->rays[i].y);
		draw_slice(cub, (int)(psh), i, cub->rays[i].is);
		// if (i > 500)
		// 	break ;
		i++;
	}
	//exit(1);
	mlx_put_image_to_window(cub->mlx3d, cub->mlx3d_win, cub->img3d.img, 0, 0);
	return 0;
}