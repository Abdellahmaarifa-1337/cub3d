/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horizontal_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:48:39 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/30 22:44:06 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

int is_wall_ray_h(t_cub *cub, float x, float y)
{
	// printf("x: %d\ty: %d\n", (int)((x - 5) / CELL), (int)((y - 5) / CELL));
	int yy;
	if (is_ray_up(cub))
		yy = y - 1;
	else
		yy = y + CELL;
	if (cub->map.data[(int)(((yy) / (float)CELL))][(int)(((x)/ (float)CELL))] == '1')
		return 1;
	return 0;
}
// get the first intersection point
void set_fpt_h(t_cub * cub, double *fpt)
{

	if (is_ray_up(cub))
		fpt[1] = (int)(PLY.y / CELL) * CELL;
	else
		fpt[1] = (int)(PLY.y / CELL) * CELL;
	fpt[0] = PLY.x + (double)((double)fpt[1] - PLY.y)/tan(cub->map.ray_pa);
}

// get the distance between each horizontal point
void set_horizontal_distance(t_cub * cub, double *dist)
{
	double	sign;

	sign = 1;
	if (is_ray_up(cub))
	{
		dist[1] = -CELL;
		sign = -1;
	}
	else
		dist[1] = CELL;
	dist[0] = (double)(sign * CELL) / tan(cub->map.ray_pa);
}

// set the horizontal ray
void set_horizontal_ray(t_cub * cub, double *ray)
{
	double	fpt[2];
	double	dist[2];
	double	px;
	double	py;

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
		if (is_wall_ray_h(cub, px, py))
		{
			//printf("wall in x:%d y:%d\n",(int)(px / CELL), (int)(py / CELL));
			//printf("wall: x :: dist[0] %f wall:y :: dist[1] %f\n", dist[0], dist[1]);
			ray[0] = px;
			ray[1] = py;
			//my_mlx_pixel_put(&cub->img, px, py, PRUPLE);
			break ;
		}
		//my_mlx_pixel_put(&cub->img, px, py, PRUPLE);
		//printf("x :: dist[0] %f y :: dist[1] %f\n", dist[0], dist[1]);
		px += dist[0];
		py += dist[1];
	}
}
