/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horizontal_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:48:39 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/13 21:37:16 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game.h"

int	is_wall_ray_h(t_cub *cub, float x, float y)
{
	int	yy;

	if (is_ray_up(cub))
		yy = y - 1;
	else
		yy = y ;
	if (cub->map.data[(int)(((yy) / (float)CELL))]
		[(int)(((x) / (float)CELL))] == '1')
		return (1);
	return (0);
}

int	is_out_h(t_cub *cub, int x, int y)
{
	int	yy;

	if (is_ray_up(cub))
		yy = y - 1;
	else
		yy = y;
	if (yy < 0 || (size_t)yy >= cub->map.height * CELL)
		return (1);
	if (x < 0 || (size_t)x >= cub->map.width * CELL)
		return (1);
	return (0);
}

// get the first intersection point
void	set_fpt_h(t_cub *cub, double *fpt)
{
	if (is_ray_up(cub))
		fpt[1] = (int)(cub->p.y / CELL) * CELL;
	else
		fpt[1] = (int)(cub->p.y / CELL) * CELL + CELL;
	if (cub->map.ray_pa == (3 * PI) / 2 || cub->map.ray_pa == PI / 2)
	{
		fpt[0] = cub->p.x;
	}
	else
		fpt[0] = cub->p.x + (double)((double)fpt[1] - cub->p.y)
			/ tan(cub->map.ray_pa);
}

// get the distance between each horizontal point
void	set_horizontal_distance(t_cub *cub, double *dist)
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
	if (cub->map.ray_pa == (3 * PI) / 2 || cub->map.ray_pa == PI / 2)
	{
		printf("this\n");
		dist[0] = sign * CELL;
	}
	else
		dist[0] = (double)(sign * CELL) / tan(cub->map.ray_pa);
}

// set the horizontal ray
double	set_horizontal_ray(t_cub *cub)
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
			return (INT_MAX);
		if (is_wall_ray_h(cub, px, py))
			break ;
		px += dist[0];
		py += dist[1];
	}
	cub->rays.x_hor = px;
	cub->rays.y_hor = py;
	return (sqrt((px - cub->p.x) * (px - cub->p.x)
			+ (py - cub->p.y) * (py - cub->p.y)));
}
