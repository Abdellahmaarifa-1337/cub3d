/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vertical_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:06:13 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 09:37:35 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

int is_out_v(t_cub *cub ,int x, int y)
{
	int xx;
	if (is_ray_right(cub))
		xx = x ;
	else
		xx = x - 1;
	if (y < 0 || (size_t)y  >= MAP.height * CELL)
			return (1);
	if (xx < 0 || (size_t)xx >= MAP.width * CELL)
			return (1);
	return (0);
}

int is_wall_ray_v(t_cub *cub, float x, float y)
{
	// printf("x: %d\ty: %d\n", (int)((x - 5) / CELL), (int)((y - 5) / CELL));
	int xx;
	if (is_ray_right(cub))
		xx = x ;
	else
		xx = x - 1;
	if (cub->map.data[(int)(((y) / (float)CELL))][(int)(((xx)/ (float)CELL))] == '1')
		return 1;
	return 0;
}

// get the first intersection point
void set_fpt(t_cub * cub, double *fpt)
{
	double sign;
	
	sign = 1;
	if (is_ray_right(cub)) 
		fpt[0] = (int)(PLY.x / CELL) * CELL + CELL ;
	else
	{
		fpt[0] = (int)(PLY.x / CELL) * CELL ;
		sign = -1;
	}
	if (cub->map.ray_pa == 0 || cub->map.ray_pa == PI)
	{
		fpt[1] = PLY.y;
	}
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
	// if (is_ray_up(cub))
	//  	sign = -1;
	dist[1] = (double)(sign * CELL) * (tan(cub->map.ray_pa));
}

// set the vertical ray
double set_vertical_ray(t_cub * cub)
{
	double	fpt[2];
	double	dist[2];
	double	px;
	double	py;

	set_fpt(cub, fpt);
	set_vertical_distance(cub, dist);
	px = fpt[0];
	py = fpt[1];
	while (1)
	{
		if (is_out_v(cub, px, py))
		{
			px = -1;
			py = -1;	
			break ;
		}
		if (is_wall_ray_v(cub, px, py))
		{
			cub->inter.inter_v = py;
			break ;
		}
		px += dist[0];
		py += dist[1];
	}
	if (px == -1 && py == -1)
		return (INT_MAX);
	return (sqrt((px - PLY.x)*(px - PLY.x) + (py - PLY.y) * (py - PLY.y)));
}