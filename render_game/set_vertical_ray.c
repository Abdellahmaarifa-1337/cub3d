/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vertical_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:06:13 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/28 18:08:11 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

// get the first intersection point
void set_fpt(t_cub * cub, float *fpt)
{
	float sign;
	
	sign = 1;
	if (is_ray_right(cub)) 
		fpt[0] = (int)(PLY.x / CELL) * CELL + CELL;
	else
	{
		fpt[0] = (int)(PLY.x / CELL) * CELL - 1 ;
		sign = -1;
	}
	if (cub->map.ray_pa == 0 || cub->map.ray_pa == PI)
		fpt[1] = PLY.y;
	else
		fpt[1] = PLY.y + fabs((PLY.x - (float)fpt[0])) * tan(cub->map.ray_pa) * sign;
}

// get the distance between each vertical point
void set_vertical_distance(t_cub * cub, float *dist)
{
	float	sign;

	sign = 1;
	if (is_ray_right(cub)) 
		dist[0] = CELL;
	else
	{
		dist[0] = -CELL ;
		sign = -1;
	}
	dist[1] = (float)(sign * CELL) * (tan(cub->map.ray_pa));
}

// set the vertical ray
void set_vertical_ray(t_cub * cub, int *ray)
{
	float	fpt[2];
	float	dist[2];
	float	px;
	float	py;

	set_fpt(cub, fpt);
	set_vertical_distance(cub, dist);
	if (is_out(cub, fpt[0], fpt[1]))
	{
		ray[0] = -1;
		ray[1] = -1;
		return ;
	}
	//my_mlx_pixel_put(cub, (int)(fpt[0]), (int)(fpt[1]), WALL);
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
			//my_mlx_pixel_put(cub, px, py, WALL);
			break ;
		}
		//my_mlx_pixel_put(cub, px, py, WALL);
		px += dist[0];
		py += dist[1];
	}
}