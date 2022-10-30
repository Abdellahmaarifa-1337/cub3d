/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horizontal_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:48:39 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/29 21:20:34 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

// get the first intersection point
void set_fpt_h(t_cub * cub, float *fpt)
{

	if (is_ray_up(cub))
		fpt[1] = (int)(PLY.y / CELL) * CELL - 1;
	else
		fpt[1] = (int)(PLY.y / CELL) * CELL + CELL;
	fpt[0] = PLY.x + ((float)fpt[1] - PLY.y)/tan(cub->map.ray_pa);
}

// get the distance between each horizontal point
void set_horizontal_distance(t_cub * cub, float *dist)
{
	float	sign;

	sign = 1;
	if (is_ray_up(cub))
	{
		dist[1] = -CELL;
		sign = -1;
	}
	else
		dist[1] = CELL;
	dist[0] = (float)(sign * CELL) / tan(cub->map.ray_pa);
}

// set the horizontal ray
void set_horizontal_ray(t_cub * cub, int *ray)
{
	float	fpt[2];
	float	dist[2];
	float	px;
	float	py;

	ray[0] = -1;
	ray[1] = -1;
	set_fpt_h(cub, fpt);
	set_horizontal_distance(cub, dist);
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
			//printf("wall in x:%d y:%d\n",(int)(px / CELL), (int)(py / CELL));
			ray[0] = px;
			ray[1] = py;
			//my_mlx_pixel_put(&(cub->img), px, py, WALL);
			break ;
		}
		//my_mlx_pixel_put(&(cub->img), px, py, WALL);
		px += dist[0];
		py += dist[1];
	}
}
