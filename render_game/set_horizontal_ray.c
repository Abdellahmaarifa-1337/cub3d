/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horizontal_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:48:39 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 09:37:08 by amaarifa         ###   ########.fr       */
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
		yy = y ;
	if (cub->map.data[(int)(((yy) / (float)CELL))][(int)(((x)/ (float)CELL))] == '1')
		return 1;
	return 0;
}

int is_out_h(t_cub *cub ,int x, int y)
{
	int yy;
	if (is_ray_up(cub))
		yy = y - 1;
	else
		yy = y;
	
	if (yy < 0 || (size_t)yy  >= MAP.height * CELL)
			return (1);
	if (x < 0 || (size_t)x >= MAP.width * CELL)
			return (1);
	return (0);
}

// get the first intersection point
void set_fpt_h(t_cub * cub, double *fpt)
{

	if (is_ray_up(cub))
		fpt[1] = (int)(PLY.y / CELL) * CELL;
	else
		fpt[1] = (int)(PLY.y / CELL) * CELL + CELL;

	if (cub->map.ray_pa == (3 * PI) / 2 || cub->map.ray_pa == PI/2)
	{
		fpt[0] = PLY.x;
	}
	else
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
	if (cub->map.ray_pa == (3 * PI) / 2 || cub->map.ray_pa == PI/2)
	{
		printf("this\n");
		dist[0] = sign * CELL;
	}
	else
		dist[0] = (double)(sign * CELL) / tan(cub->map.ray_pa);
}

// set the horizontal ray
double set_horizontal_ray(t_cub * cub)
{
	double	fpt[2];
	double	dist[2];
	double	px;
	double	py;

	set_fpt_h(cub, fpt);
	set_horizontal_distance(cub, dist);
	px = fpt[0];
	py = fpt[1];
	while (1)
	{
		if (is_out_h(cub, px, py))
		{
			px = -1;
			py = -1;	
			break ;
		}
		if (is_wall_ray_h(cub, px, py))
		{
			cub->inter.inter_h = px;
			break ;
		}
		px += dist[0];
		py += dist[1];
	}
	if (px == -1 && py == -1)
		return (INT_MAX);
	return (sqrt((px - PLY.x)*(px - PLY.x) + (py - PLY.y) * (py - PLY.y)));
}
