/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:26:18 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/10 15:35:26 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

void	set_sides(t_cub *cub, float x, float y)
{
	if (cub->inter.is_ver && PLY.x < x)
		cub->side = E;
	else if (cub->inter.is_ver)
		cub->side = W;
	if (!cub->inter.is_ver && PLY.y < y)
		cub->side = S;
	else if (!cub->inter.is_ver)
		cub->side = N;
}

double	get_ray_dist(t_cub *cub)
{
	double		dist_h;
	double		dist_v;

	if (cub->map.ray_pa < 0)
		cub->map.ray_pa += 2 * PI;
	else if (cub->map.ray_pa > 2*PI)
		cub->map.ray_pa -= 2 * PI;
	dist_v = set_vertical_ray(cub);
	dist_h = set_horizontal_ray(cub);
	cub->inter.is_ver = 0;
	if (dist_h <= dist_v)
	{
		set_sides(cub, cub->rays->x_hor, cub->rays->y_hor);
		return (dist_h * fabs(cos(fabs(PLY.pa - cub->map.ray_pa))));
	}
	cub->inter.is_ver= 1;
	set_sides(cub, cub->rays->x_ver, cub->rays->y_ver);
	return (dist_v * fabs(cos(fabs(PLY.pa - cub->map.ray_pa))));
}