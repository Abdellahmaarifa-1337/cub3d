/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vertical_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:06:13 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/30 22:40:18 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

// get the first intersection point
void set_fpt(t_cub * cub, double *fpt)
{
	double sign;
	
	sign = 1;
	if (is_ray_right(cub)) 
		fpt[0] = (int)(PLY.x / CELL) * CELL + CELL;
	else
	{
		fpt[0] = (int)(PLY.x / CELL) * CELL - 1;
		sign = -1;
	}
	if (cub->map.ray_pa == 0 || cub->map.ray_pa == PI)
		fpt[1] = PLY.y;
	else
		fpt[1] = PLY.y + fabs((PLY.x - fpt[0])) * tan(cub->map.ray_pa) * sign;
}

// get the distance between each vertical point
void set_vertical_distance(t_cub * cub, double *dist)
{
	double	sign;

	sign = 1;
	if (is_ray_right(cub)) 
		dist[0] = CELL;
	else
	{
		dist[0] = -CELL ;
		sign = -1;
	}
	dist[1] = (double)(sign * CELL) * (tan(cub->map.ray_pa));
}

// set the vertical ray
void set_vertical_ray(t_cub * cub, double *ray)
{
	double	fpt[2];
	double	dist[2];
	double	px;
	double	py;

	set_fpt(cub, fpt);
	set_vertical_distance(cub, dist);
	// printf("px: %f\tpy: %f\n", fpt[0] / CELL, fpt[1] / CELL);
	if (is_out(cub, fpt[0], fpt[1]))
	{
		ray[0] = -1;
		ray[1] = -1;
		return ;
	}
	//my_mlx_pixel_put(&cub->img, (int)(fpt[0]), (int)(fpt[1]), PRUPLE);
	px = fpt[0];
	py = fpt[1];
	while (1)
	{
		if (is_out(cub, px, py))
		{
			ray[0] = -1;
			ray[1] = -1;	
			break ;
		}
		if (is_wall_ray(cub, px, py))
		{
			ray[0] = px;
			ray[1] = py;
			//my_mlx_pixel_put(&cub->img, px, py, PRUPLE);
			break ;
		}
		//my_mlx_pixel_put(&cub->img, px, py, PRUPLE);
		px += dist[0];
		py += dist[1];
	}
}